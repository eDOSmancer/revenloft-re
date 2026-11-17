"""Run DOS tools of a Watcom installation under headless DOSBox-X.

The installation directory is mounted as C: (WATCOM=C:\\, PATH=C:\\BIN, INCLUDE=C:\\H) and a work directory as D:
(the current directory).  One DOSBox-X process per call; the commands are the lines of a generated AUTOEXEC section.
"""
import os, subprocess, shutil

CONF = """[sdl]
output=surface
[dosbox]
memsize=32
[cpu]
cycles=max
[mixer]
nosound=true
[midi]
mpu401=none
mididevice=none
[sblaster]
sbtype=none
[gus]
gus=false
[speaker]
pcspeaker=false
tandy=off
[autoexec]
@echo off
mount c "%(watcom)s"
mount d "%(work)s"
set WATCOM=C:\\
set INCLUDE=C:\\H
set PATH=C:\\BIN
%(env)s
d:
%(commands)s
exit
"""

def dosbox():
    exe = os.environ.get('DOSBOX') or shutil.which('dosbox-x')
    if not exe: raise SystemExit('dosbox-x not found (set DOSBOX)')
    return exe

def run(watcom, work, commands, name='RUN', timeout=120, env=()):
    """commands: DOS command lines, run in `work` (D:\\).  The configuration file is written to `work` and removed."""
    conf = os.path.join(work, 'dosbox-%s.conf' % name)
    with open(conf, 'w') as f:
        f.write(CONF % dict(watcom=os.path.abspath(watcom), work=os.path.abspath(work),
                            env='\n'.join('set ' + e for e in env), commands='\n'.join(commands)))
    e = dict(os.environ, SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy')
    try:
        subprocess.run(['timeout', '-k', '5', str(timeout), dosbox(), '-conf', conf, '-fastlaunch'],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, env=e)
    finally:
        os.remove(conf)

# Ravenloft: Strahd's Possession - CODE.1 and CODE.2 from source.
#   make          build both programs and compare their SHA-1 with expected.sha1 (exit status 0 only if both match)
#   make code1    CODE.1 only            make code2    CODE.2 only
#   make clean    remove build/
# Tool locations: build.cfg (or environment variables WATCOM10A, WATCOM95, LOADER, ...; see README.md).
PYTHON ?= python3
all:
	$(PYTHON) tools/build.py all
code1:
	$(PYTHON) tools/build.py CODE.1
code2:
	$(PYTHON) tools/build.py CODE.2
clean:
	$(PYTHON) -c "import shutil; shutil.rmtree('build', ignore_errors=True)"
.PHONY: all code1 code2 clean

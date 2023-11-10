#!/usr/bin/python3
import subprocess, sys

argv = []
for arg in sys.argv[1:]:
    if arg not in ['-arch', 'arm64']:
        argv.append(arg)
exit(subprocess.call(['em++', *argv]))
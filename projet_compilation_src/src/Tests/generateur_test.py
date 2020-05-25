#!/usr/bin/python

compiler = ""
tests_KO_ = "./tests/KO/"
tests_OK = "./tests/OK/"

ERROR = '\033[91m'
RESET = '\033[0m'
BOLD = '\033[1m'
VALID = '\033[1;32m'

import os

def test_KO():
	i = 0
	print(ERROR + BOLD + "test ko fait")
	for filename in sorted(os.listdir(tests_KO)):
		if filename.endswith(".c"):
			print(RESET + os.path.basename(filename) + RESET + ERROR + BOLD)
			cmd = compiler + tests_KO+ os.path.basename(filename)
			os.system(cmd)
		else:
			continue
	print(ERROR + BOLD + "fin test ko\n" + RESET)

def test_OK():
	i = 0
	print(VALID + BOLD + "test ok fait")
	for filename in sorted(os.listdir(tests_OK_path)):
		if filename.endswith(".c"):
			cmd = compiler_path + tests_OK_path + os.path.basename(filename)
			os.system(cmd)
			print(RESET + os.path.basename(filename) + RESET + VALID + "ok")
		else:
			continue
	print(VALID+ BOLD + "fin test ok" + RESET)

test_KO()
test_OK()
print(RESET + BOLD + "fin" + RESET)


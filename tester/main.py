import os, sys
import argparse
import time

compilerDict = {
	'c++': 'g++',
	'py3': 'python3',
	'c': 'gcc'
}

COLOR = {
	'RED': '\033[31m', 
	'GREEN': '\033[32m',
	'BLUE': '\033[33m',
	'BLACK': '\033[30m',
	'WHITE':'\033[37m',
	'BOLD': '\033[1m',
	'WHITE_BACKGROUND': '\033[47m',
	'ORIGINAL_COLOR': '\033[0;0m'
}

def get_tests(path):
	with open(path) as output:
		ans = ""
		for line in output:
			ans += line
		return ans

def compile(language, code_file_path):
	command = compilerDict[language] + " " + code_file_path
	os.system(command)

def run_code(tests):
	qnt_tests = len(os.listdir(tests))
	idx = 1
	for i in range(qnt_tests):
		ext_test = 'test' + str(idx)
		test = tests + 'test' + str(idx)
		start_time = time.time()
		os.system('./a.out < ' + test + '/in > tests/out' + str(idx))
		end_time = time.time()
		test_out = get_tests(test + '/out')
		run_out = get_tests('tests/out' + str(idx))
		flag_run = True
		first_diff = ''
		for test_line, run_line in zip(test_out, run_out):
			if(test_line != run_line):
				first_diff = test_out + ' ' + run_out
				flag_run = False
				break
		color = COLOR['GREEN']
		if(not flag_run):
			color = COLOR['RED']
		print(color + 'run ' + ext_test + COLOR['ORIGINAL_COLOR'])
		print('run time: %s' % (end_time - start_time))
		if(not flag_run):
			print(color, 'first diff: ' + first_diff, COLOR['ORIGINAL_COLOR'])
		idx += 1

def clear():
	os.system('rm a.out')
	os.system('rm -R tests')


def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('--language', '-l')
	parser.add_argument('--code', '-c')
	parser.add_argument('--tests', '-t')
	args = parser.parse_args()
	lang = str(args.language)
	code = str(args.code)
	tests = str(args.tests)
	if(not lang or not code or not tests):
		print('set all params')
	else:
		print("language: " + lang)
		print("path code: " + code)
		print("path tests: " + tests)
		print("compiling...")
		compile(lang, code)
		print("file compiled")
		os.system('mkdir tests')
		run_code(tests)
		print('clearing...')
		time.sleep(1)
		clear()

main()
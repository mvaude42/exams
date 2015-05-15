# Exemple:
#
# $> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
# l'indifference de celui precede mepris du temps le$
# $> ./rev_wstr "abcdefghijklm"
# abcdefghijklm
# $> ./rev_wstr "il contempla le mont" | cat -e
# mont le contempla il$
# $> ./rev_wstr | cat -e
# $
# $>

import subprocess

def	test1():
	args = ["./rev_wstr", "le temps du mepris precede celui de l'indifference"]
	test = subprocess.check_output(args)
	if test != "l'indifference de celui precede mepris du temps le\n":
		print "\033[91m" + "1st test failed" + "\033[0m"
		return
	print "\033[92m" + "1st test ok" + "\033[0m"

def	test2():
	args = ["./rev_wstr", "abcdefghijklm"]
	test = subprocess.check_output(args)
	if test != "abcdefghijklm\n":
		print "\033[91m" + "2nd test failed" + "\033[0m"
		return
	print "\033[92m" + "2nd test ok" + "\033[0m"

def	test3():
	args = ["./rev_wstr", "il contempla le mont"]
	test = subprocess.check_output(args)
	if test != "mont le contempla il\n":
		print "\033[91m" + "3rd test failed" + "\033[0m"
		return
	print "\033[92m" + "3rd test ok" + "\033[0m"

def	test4():
	args = ["./rev_wstr", "THERE'S BUTTER ON MY FACE"]
	test = subprocess.check_output(args)
	if test != "FACE MY ON BUTTER THERE'S\n":
		print "\033[91m" + "4th test failed" + "\033[0m"
		return
	print "\033[92m" + "4th test ok" + "\033[0m"

def	test5():
	args = ["./rev_wstr", "vingt-huit mille spatules au gravillon"]
	test = subprocess.check_output(args)
	if test != "gravillon au spatules mille vingt-huit\n":
		print "\033[91m" + "5th test failed" + "\033[0m"
		return
	print "\033[92m" + "5th test ok" + "\033[0m"

def	test6():
	args = ["./rev_wstr", "..."]
	test = subprocess.check_output(args)
	if test != "...\n":
		print "\033[91m" + "6th test failed" + "\033[0m"
		return
	print "\033[92m" + "6th test ok" + "\033[0m"

def	test7():
	args = ["./rev_wstr", ""]
	test = subprocess.check_output(args)
	if test != "\n":
		print "\033[91m" + "7th test failed" + "\033[0m"
		return
	print "\033[92m" + "7th test ok\n" + "\033[0m"

def	main():
	subprocess.call(["gcc", "-Wall", "-Werror", "-Wextra", "rev_wstr.c", "-o", "rev_wstr"])
	print "Test rev_wstr:\n"
	test1()
	test2()
	test3()
	test4()
	test5()
	test6()
	test7()

main()


import subprocess

def	test1():
	args = ["./wdmatch", "faya", "fgvvfdxcacpolhyghbreda"]
	test = subprocess.check_output(args)
	if test != "faya\n":
		print "\033[91m" + "1st test failed" + "\033[0m"
		return
	print "\033[92m" + "1st test ok" + "\033[0m"

def	test2():
	args = ["./wdmatch", "faya", "fgvvfdxcacpolhyghbred"]
	test = subprocess.check_output(args)
	if test != "\n":
		print "\033[91m" + "2nd test failed" + "\033[0m"
		return
	print "\033[92m" + "2nd test ok" + "\033[0m"

def	test3():
	args = ["./wdmatch", "quarante deux", "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq "]
	test = subprocess.check_output(args)
	if test != "quarante deux\n":
		print "\033[91m" + "3rd test failed" + "\033[0m"
		return
	print "\033[92m" + "3rd test ok" + "\033[0m"

def	test4():
	args = ["./wdmatch", "error", "rrerrrfiiljdfxjyuifrrvcoojh"]
	test = subprocess.check_output(args)
	if test != "\n":
		print "\033[91m" + "4th test failed" + "\033[0m"
		return
	print "\033[92m" + "4th test ok" + "\033[0m"

def	test5():
	args = ["./wdmatch", "... un dernier pour la route", "... UN DERNIER POUR LA ROUTE"]
	test = subprocess.check_output(args)
	if test != "\n":
		print "\033[91m" + "5th test failed" + "\033[0m"
		return
	print "\033[92m" + "5th test ok" + "\033[0m"

def	test6():
	args = ["./wdmatch", "oui", "qowueir"]
	test = subprocess.check_output(args)
	if test != "oui\n":
		print "\033[91m" + "6th test failed" + "\033[0m"
		return
	print "\033[92m" + "6th test ok" + "\033[0m"

def	test7():
	args = ["./wdmatch", ""]
	test = subprocess.check_output(args)
	if test != "\n":
		print "\033[91m" + "7th test failed" + "\033[0m"
		return
	print "\033[92m" + "7th test ok\n" + "\033[0m"

def	main():
	subprocess.call(["gcc", "-Wall", "-Werror", "-Wextra", "wdmatch.c", "-o", "wdmatch"])
	print "Test wdmatch:\n"
	test1()
	test2()
	test3()
	test4()
	test5()
	test6()
	test7()

main()

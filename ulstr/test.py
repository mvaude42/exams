import subprocess

def	test1():
	args = ["./ulstr", "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification."]
	test = subprocess.check_output(args)
	if test != "l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.\n":
		print "\033[91m" + "1st test failed" + "\033[0m"
		return
	print "\033[92m" + "1st test ok" + "\033[0m"

def	test2():
	args = ["./ulstr", "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  "]
	test = subprocess.check_output(args)
	if test != "s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  \n":
		print "\033[91m" + "2nd test failed" + "\033[0m"
		return
	print "\033[92m" + "2nd test ok" + "\033[0m"

def	test3():
	args = ["./ulstr", "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot"]
	test = subprocess.check_output(args)
	if test != "3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT\n":
		print "\033[91m" + "3rd test failed" + "\033[0m"
		return
	print "\033[92m" + "3rd test ok" + "\033[0m"

def	test4():
	args = ["./ulstr", "Pour l'Imperium de l'Humanite"]
	test = subprocess.check_output(args)
	if test != "pOUR L'iMPERIUM DE L'hUMANITE\n":
		print "\033[91m" + "4th test failed" + "\033[0m"
		return
	print "\033[92m" + "4th test ok" + "\033[0m"

def	test5():
	args = ["./ulstr", "..."]
	test = subprocess.check_output(args)
	if test != "...\n":
		print "\033[91m" + "5th test failed" + "\033[0m"
		return
	print "\033[92m" + "5th test ok" + "\033[0m"

def	test6():
	args = ["./ulstr", ""]
	test = subprocess.check_output(args)
	if test != "\n":
		print "\033[91m" + "6th test failed" + "\033[0m"
		return
	print "\033[92m" + "6th test ok\n" + "\033[0m"

def	main():
	subprocess.call(["gcc", "-Wall", "-Werror", "-Wextra", "ulstr.c", "-o ulstr"])
	print "Test ulstr:\n"
	test1()
	test2()
	test3()
	test4()
	test5()
	test6()

main()

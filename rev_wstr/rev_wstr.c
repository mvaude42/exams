/*
 *
 * Write a program that takes a string as a parameter, and prints its words in reverse order.
 * A "word" is a part of the string bounded by spaces and/or tabs, or the begin/end of the string.
 * If the number of parameters is different from 1, the program will display ’\n’.
 * In the parameters that are going to be tested, there won’t be any "additional" spaces 
 * (meaning that there won’t be additionnal spaces at the beginning or at the end of the string, 
 * and words will always be separated by exactly one space).
 * 
 * Exemple:
 *
 * $> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
 * l'indifference de celui precede mepris du temps le$
 * $> ./rev_wstr "abcdefghijklm"
 * abcdefghijklm
 * $> ./rev_wstr "il contempla le mont" | cat -e
 * mont le contempla il$
 * $> ./rev_wstr | cat -e
 * $
 * $>
 *
*/

#include <unistd.h>

int			ft_strlen(char *s)
{
	return (!*s ? 0 : 1 + ft_strlen(++s));
}

int			ft_ispace(int c)
{
	return (c == 32 || c == '\t' ? 1 : 0);
}

void		rev_wstr(char *s, int max, int len, int first)
{
	if (!max)
	{
		if (first)
			write(1, " ", 1);
		return ((void)write(1, s, len));
	}
	if (ft_ispace(*s))
			write(1, (first ? s : s + 1), (first ? len : len - 1)), len = 0, ++first;
	rev_wstr(--s, --max, ++len, first);
}

int			main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr((av[1] + ft_strlen(av[1])), ft_strlen(av[1]), 0, 0);
	write(1, "\n", 1);
	return (0);
}

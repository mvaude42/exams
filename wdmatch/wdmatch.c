/* 
 * Write a program that takes two strings 
 * and checks whether it’s possible to write the first string with characters from the second string, 
 * while respecting the order in which these characters appear in the second string.
 * If it’s possible, the program displays the string, followed by a \n, otherwise it simply displays a \n.
 * If the number of arguments is not 2, the program displays a \n.
*/

#include <unistd.h>

size_t			ft_strlen(char *s, size_t n)
{
	return (!*s ? n : ft_strlen(++s, ++n));
}

int			wdmatch(char *s1, char *s2)
{
	if (!*s1 || !*s2)
		return (!*s1 ? 1 : 0);
	return (*s1 == *s2 ? wdmatch(++s1, ++s2) : wdmatch(s1, ++s2));
}

int			main(int ac, char **av)
{
	if ((ac == 3  ? wdmatch(av[1], av[2]) : 0))
		write(1, av[1], ft_strlen(av[1], 0));
	write(1, "\n", 1);
}

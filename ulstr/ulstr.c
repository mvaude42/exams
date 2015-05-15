/*
 * Write a program that takes a string and reverses the case of all its letters.
 * Other characters remain unchanged.
 * You must display the result following by a \n.
 * If the number of arguments is not 1, the program displays \n. Examples :
*/

#include <unistd.h>

int			ft_isupper(int c)
{
	return (c >= 65 && c <= 90 ? 1 : 0);
}

int			ft_isalpha(int c)
{
	return (ft_isupper(c) || (c >= 97 && c <= 122) ? 1 : 0);
}

void			ulstr(char *s)
{
	if (!*s)
		return ;
	if (ft_isalpha(*s))
		*s = (ft_isupper(*s) ? *s + 32 : *s- 32);
	write(1, s, 1);
	ulstr(++s);
}

int			main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}

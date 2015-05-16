/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaude <mvaude@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 09:20:36 by exam              #+#    #+#             */
/*   Updated: 2015/05/06 09:20:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}

void		rotone(char *s)
{
	char	c;

	if(!*s)
		return ;
	if (ft_isalpha(*s))
		c = (*s == 'z' || *s == 'Z' ? *s - 25 : *s + 1);
	else
		c = *s;
	write(1, &c, 1);
	rotone(++s);
}

int			main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}

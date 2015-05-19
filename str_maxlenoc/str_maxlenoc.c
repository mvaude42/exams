#include <unistd.h>
#include <stdlib.h>

char		*local_max;

static int	ft_strlen(char *s)
{
	return (!*s ? 0 : 1 + ft_strlen(++s));
}

static void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

static void	ft_strcpy(char *s1, char *s2)
{
	if (!*s2)
		*s1 = 0;
	else
	{
		*s1 = *s2;
		ft_strcpy(++s1, ++s2);
	}
}

char		*ft_strdup(char *s)
{
	char 	*new;

	if (!(new = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(new, s);
	return (new);
}

static int	ft_strnequ(char *s1, char *s2, int n)
{
	if (n < 1)
		return (1);
	if (*s1 != *s2)
		return (0);
	return (ft_strnequ(++s1, ++s2, --n));
}

static char	*ft_strstr(char *s1, char *s2)
{
	if (!*s1)
		return (NULL);
	if (ft_strnequ(s1, s2, ft_strlen(s2)))
		return (s1);
	return (ft_strstr(++s1, s2));
}

static void	loop_match(char *c1, char *s2)
{
	if (!*c1)
		return;
	if (ft_strstr(c1, s2))
	{
		if (ft_strlen(c1) > ft_strlen(local_max))
			local_max = ft_strdup(c1);
	}
	c1[ft_strlen(c1) - 1] = 0;
	loop_match(c1, s2);
}

static void	match_right(char *s1, char *s2)
{
	char	*c1;

	c1 = ft_strdup(s1);
	loop_match(c1, s2);
}

static void	match_left(char *s1, char *s2)
{
	if (!*s1)
		return;
	match_right(s1, s2);
	match_left(++s1, s2);
}

static void	loop_max(char **s, char *s_max)
{
	if (!*s)
		return;
	local_max = "";
	match_left(s_max, *s);
	if (ft_strlen(local_max) < ft_strlen(s_max))
		s_max = local_max;
	loop_max(++s, s_max);
}

static void	maxlenoc(char **s)
{
	char	*s_max;

	s_max = *s;
	loop_max(++s, s_max);
	ft_putstr(s_max);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(av[1]);
	if (ac > 2)
		maxlenoc(++av);
	ft_putstr("\n");
	return (0);
}

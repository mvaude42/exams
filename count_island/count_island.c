#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// Count the number of characters in a string
int		ft_strlen(char *s)
{
	return (!*s ? 0 : 1 + ft_strlen(++s));
}

// Write a string
void		ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

// Read the file
int		ft_read(int fd, char *map_str, int *char_pos)
{
	int	ret;
	char	c;

	ret = -1;
	// read it char by char, if nothing then return read value
	if ((ret = read(fd, &c, 1)) <= 0)
		return (ret);
	// if it's not a valid char then quit
	if (c != '\n' && c != 'X' && c != '.')
		return (-1);
	// write the char
	map_str[*char_pos] = c;
	// increase the cursor
	*char_pos += 1;
	// repeat it
	return (ft_read(fd, map_str, char_pos));
}


char		*read_map(char *path)
{
	int	fd;
	char	*map_str;
	int	*char_pos;

	// Malloc the map to a huge size
	if (!(map_str = malloc(sizeof(char) * (1000 * 1000 * 10))))
		return (NULL);
	// Open the file name 
	if ((fd = open(path, O_RDONLY)) <= 0)
		return (NULL);
	*char_pos = 0;
	// read the map
	if (ft_read(fd, map_str, char_pos) == -1)
		return (NULL);
	// finnish the map with a null character
	map_str[*char_pos] = 0;
	// check if last char is a return
	if (map_str[*char_pos - 1] != '\n')
		return (NULL);
	// return the readed map
	return (map_str);
}

char		**build_it(char *s, char **map, int x, int y, int len)
{
	// If string ended, return
	if (!*s)
	{
		map[y] = NULL;
		return (map);
	}
	// If end of the line
	if (*s == '\n')
	{
		// Replace by null character
		map[y][x] = 0;
		// If first time the calculate the length of line
		if (len == -1)
			len = ft_strlen(map[y]);
		// If length different than before then exit
		else if (len != ft_strlen(map[y]))
			return (NULL);
		y++;
		// Malloc new line
		map[y] = malloc(sizeof(char) * (2000));
		x = 0;
	}
	else
	{
		// Else copy the char
		map[y][x] = *s;
		x++;
	}
	// repeat it
	return (build_it(++s, map, x, y, len));
}

char		**build_map(char *s)
{
	char	**map;
	// malloc a huge size for columns
	if (!(map = malloc(sizeof(char *) * (2000))))
		return (NULL);
	// malloc a huge size for line
	if (!(map[0] = malloc(sizeof(char) * (2000))))
		return (NULL);
	return (build_it(s, map, 0, 0, -1));
}

void		infect(char **map, int x, int y, char count)
{
	// If line exists and char is equal to 'X' 
	if (map[y] && map[y][x] == 'X')
	{
		// Replace the char by count value
		map[y][x] = count;
		// infect line down
		infect(map, x, y + 1, count);
		// infect line up
		infect(map, x, y - 1, count);
		// infect next char
		infect(map, x + 1, y, count);
		// infect previous char
		infect(map, x - 1, y, count);
	}
}

// Count the islands
void		travel(char **map, int x, int y, char count)
{
	// If no more map then exit
	if (!map[y])
		return;
	// If line is ended, change it
	if (!map[y][x])
		return (travel(map, 0, ++y, count));
	// If char is 'X' then infect the island
	if (map[y][x] == 'X')
	{
		infect(map, x, y, count);
		// Increase the island count
		count++;
	}
	// repeat it
	travel(map, ++x, y, count);
}

// Print the resulted map
void		print_map(char **map)
{
	// If no more then exit
	if (!*map)
		return;
	// Print line
	ft_putstr(*map);
	ft_putstr("\n");
	// Repeat it
	print_map(++map);
}

int		main(int ac, char **av)
{
	char	*map_str;
	char	**map;

	// Execute only if there is the good number of argument
	if (ac == 2)
	{
		// If problem during the map reading then exit
		if ((map_str = read_map(av[1])))
		{
			// Build the map
			if ((map = build_map(map_str)))
			{
				// Start the counting
				travel(map, 0, 0, '0');
				// Print the result
				print_map(map);
			}
			else
				ft_putstr("\n");
		}
		else
			ft_putstr("\n");
	}
	return (0);
}

#include "config.h"

void	*ft_realloc(void *buf, int before, int after)
{
	int	i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after);
	i = 0;
	while (i < before)
	{
		dst[i] = src[i];
		i++;
	}
	free(buf);
	return ((void *)dst);
}

void	map_info(t_map *info, int fd)
{
	char	*line;

	line = trim_line(new_line(fd));
	if (!line)
		throw_error("Error\nEmpty file");
	while (*line == '\0')
	{
		free(line);
		line = trim_line(new_line(fd));
	}
	while (line)
	{
		info->map = (char **)ft_realloc(info->map, info->h, info->h + 1);
		info->map[info->h] = line;
		info->h++;
		if (info->w < ft_strlen(line))
			info->w = ft_strlen(line);
		line = trim_line(new_line(fd));
	}
	if (line)
		free(line);
	close(fd);
}
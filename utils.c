#include "config.h"

void	*make_img(void *mlx, char *xpm)
{
	char	*path;
	void	*img;
	int		w;
	int		h;

	path = xpm;
	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	free(path);
	if (!img)
		throw_error("XPM Error");
	return (img);
}

void	throw_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

char	*trim_line(char *line)
{
	char	*result;

	result = ft_strtrim(line, DEL);
	free(line);
	return (result);
}

char	*new_line(int fd)
{
	char	*line;
	char	eol;
	int	len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	eol = line[len - 1];
	if (eol == '\n')
		line[len - 1] = 0;
	return (line);
}

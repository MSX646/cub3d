/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:47 by kezekiel          #+#    #+#             */
/*   Updated: 2022/10/14 16:49:48 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	free_arr(char **arr, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(arr[i]);
	free(arr);
}

void	check_split(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	if (count != 3)
	{
		free_arr(arr, count);
		throw_error("Error\nRGB required");
	}
}

int	ctoi(char c)
{
	int	res;

	res = c - '0';
	return (res);
}

int	get_rgb(char *str)
{
	long long	res;
	long long	tmp;
	int			i;

	i = 0;
	res = 0;
	while (str[i] && ft_strchr(DEL, str[i]))
		i++;
	if (str[i] == 0)
		throw_error("Error\nRGB value is empty");
	while (ft_isdigit(str[i]))
	{
		tmp = res * 10 + ctoi(str[i++]);
		if (tmp > 255)
			throw_error("Error\nColor out of range");
		res = tmp;
	}
	while (str[i] && ft_strchr(DEL, str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		throw_error("Error\nRGB must be integer");
	free(str);
	return ((int)res);
}

int	to_rgb(char *str)
{
	char	**arr;
	int		rgb;

	rgb = 0;
	arr = ft_split(str, ',');
	check_split(arr);
	rgb += get_rgb(trim_line(arr[0])) << 16;
	rgb += get_rgb(trim_line(arr[1])) << 8;
	rgb += get_rgb(trim_line(arr[2]));
	free(arr);
	return (rgb);
}

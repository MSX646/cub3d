/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:33:40 by tshimoda          #+#    #+#             */
/*   Updated: 2021/12/22 22:35:41 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_absolute(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

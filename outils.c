/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:54:53 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/09 23:26:19 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	norm(char *str, double *num, double *sign, int i)
{
	if (str[0] == '-')
	{
		*sign = -1;
		i++;
	}
	while (str[i] != '.' && str[i] != '\0')
		*num = *num * 10 + (str[i++] - '0');
	return (i);
}

double	ft_atod(char *str)
{
	double	num;
	double	sign;
	double	decimal;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	decimal = 0;
	i = norm(str, &num, &sign, i);
	if (str[i] == '.')
	{
		i++;
		decimal = 1;
	}
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	if (decimal)
		num /= decimal;
	return (num * sign);
}

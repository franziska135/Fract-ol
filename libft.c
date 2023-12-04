/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:46:53 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/24 13:51:56 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (*s1 == '0')
		s1++;
	while (*s2 == '0')
		s2++;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
		return (1);
	else if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (0);
	else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return (0);
	else
		return (1);
}

double	ft_atoi(const char *str)
{
	int	i;
	double 	nbr;
	int	sign;
	double fraction;

	i = 0;
	nbr = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
    {
        i++;
        fraction = 0.1;
        while (ft_isdigit(str[i]))
        {
            nbr = nbr + fraction * (str[i] - '0');
            fraction *= 0.1;
            i++;
        }
    }
	return (nbr * sign);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}
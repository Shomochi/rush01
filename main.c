/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smotomur <smotomur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:40:44 by ynakamot          #+#    #+#             */
/*   Updated: 2020/08/16 17:55:42 by smotomur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		output_answer(int ans[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + ans[i][j];
			write(1, &c, 1);
			if(j < 3)
			{
				c = ' ';
				write(1, &c, 1);
			}
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
		j = 0;
	}
	return (1);
}

int	split_clues(int *clues)
{
	int i;
	int colup[4];
	int coldown[4];
	int rowleft[4];
	int rowright[4];

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3)
			colup[i] = clues[i];
		else if (i >= 4 && i <= 7)
			coldown[i - 4] = clues[i];
		else if (i >= 8 && i <= 11)
			rowleft[i - 8] = clues[i];
		else if (i >= 12 && i <= 15)
			rowright[i - 12] = clues[i];
		i++;
	}
	if(!(solve(colup, coldown, rowleft, rowright)))
		return (0);
	return (1);
}

int		cut_str(char *str, int *clues)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (*str == '\0')
		return (0);
	while (*str && i < 16)
	{
		if (*str == ' ' && j % 2 != 0)
		{
		}
		else if (*str >= '1' && *str <= '4' && j % 2 == 0)
		{
			clues[i] = *str - '0';
			i++;
		}
		else
		{
			return (0);
		}
		str++;
		j++;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int clues[17];

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
	{
		if (!(cut_str(argv[1], clues)))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if(!(split_clues(clues)))
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thisai <thisai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:10:17 by thisai            #+#    #+#             */
/*   Updated: 2020/08/16 17:10:21 by thisai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int *find_iter(int n, int *table, int left, int right)
{
	int i;

	if (n == 0)
	{
		if (check(left, right, table))
		{
			table += 4;
			table[0] = (table - 4)[0];
			table[1] = (table - 4)[1];
			table[2] = (table - 4)[2];
		}
	}
	else
	{
		i = 0;
		while (i < 4)
		{
			table[4 - n] = i + 1;
			table = find_iter(n - 1, table, left, right);
			i++;
		}
	}
	return (table);
}

int find(int left, int right, int **vals)
{
	int i;
	int count;
	int table[24 * 4];
	int *table_ptr;

	table_ptr = find_iter(4, table, left, right);
	count = (table_ptr - table) / 4;
	if (count > 0)
	{
		*vals = malloc(sizeof(int) * 4 * count);
		i = 0;
		while (i < count * 4)
		{
			(*vals)[i] = table[i];
			i++;
		}
	}
	return count;
}

int		col_check(int *vals[4], int *idx, int *colup, int *coldown)
{
	int col;
	int found;
	int v[4];
	int ans[4][4];

	col = 0;
	found = 1;
	while (col < 4 && found == 1)
	{
		v[0] = vals[0][idx[0] * 4 + col];
		v[1] = vals[1][idx[1] * 4 + col];
		v[2] = vals[2][idx[2] * 4 + col];
		v[3] = vals[3][idx[3] * 4 + col];
		ans[0][col] = vals[0][idx[0] * 4 + col];
		ans[1][col] = vals[1][idx[1] * 4 + col];
		ans[2][col] = vals[2][idx[2] * 4 + col];
		ans[3][col] = vals[3][idx[3] * 4 + col];
		if(!check(colup[col], coldown[col], v))
			found = 0;
		col++;
	}
	if (found)
		return (output_answer(ans));
	return (0);
}

int		columns_pattern(int *vals[4], int *colup, int *coldown, int *count)
{
	int idx[4];

	idx[0] = 0;
	while (idx[0] < count[0])
	{
		idx[1] = 0;
		while (idx[1] < count[1])
		{
			idx[2] = 0;
			while (idx[2] < count[2])
			{
				idx[3] = 0;
				while (idx[3] < count[3])
				{
					if (col_check(vals, idx, colup, coldown))
						return (1);
					idx[3]++;
				}
				idx[2]++;
			}
			idx[1]++;
		}
		idx[0]++;
	}
	return (0);
}

int		solve(int *colup, int *coldown, int *rowleft, int *rowright)
{
	int *vals[4];
	int count[4];
	int i;
	int c;
	int *v;

	i = 0;
	while (i < 4)
	{
		c = find(rowleft[i], rowright[i], &vals[i]);
		v = vals[i];
		count[i] = c;
		i++;
	}
	return (columns_pattern(vals, colup, coldown, count));
}

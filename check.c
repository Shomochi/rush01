/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:34:39 by smotomur          #+#    #+#             */
/*   Updated: 2020/08/16 17:39:05 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_left(int left, int *vals)
{
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (max < vals[i])
		{
			max = vals[i];
			count++;
		}
		i++;
	}
	if (left != count)
		return (0);
	return (1);
}

int	check_right(int right, int *vals)
{
	int i;
	int max;
	int count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (max < vals[i])
		{
			max = vals[i];
			count++;
		}
		i--;
	}
	if (right != count)
		return (0);
	return (1);
}

int	check(int left, int right, int *vals)
{
	if (vals[0] == vals[1] || vals[0] == vals[2] || vals[0] == vals[3] ||
		vals[1] == vals[2] || vals[1] == vals[3] || vals[2] == vals[3])
		return (0);
	if (!(check_left(left, vals)))
		return (0);
	if (!(check_right(right, vals)))
		return (0);
	return (1);
}

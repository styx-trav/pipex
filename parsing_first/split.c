/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:49:23 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/21 15:22:11 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

char	**split(char *str, char c, char *add)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = ct_words(str, c);
	if (add)
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	res = init(res, i);
	k = 0;
	j = 0;
	while (k < i)
	{
		j = fill_next(str, &res, j, k);
		if (j == -1)
			return (NULL);
		k++;
	}
	if (add)
		res = add_add(res, add);
	return (res);
}

char	**add_add(char **res, char *add)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
		i++;
	res[i] = add;
	return (res);
}

char	**init(char **res, int end)
{
	int	i;

	i = 0;
	while (i <= end)
	{
		res[i] = NULL;
		i++;
	}
	return (res);
}

int	fill_next(char *str, char ***res, int i, int k)
{
	int	ct;

	ct = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (str[i + ct] != '\0' && str[i + ct] != ' ')
		ct++;
	if (!ct)
		return (i);
	(*res)[k] = malloc(ct + 1);
	if (!((*res)[k]))
	{
		free_prot_num(*res, k);
		return (-1);
	}
	ct = 0;
	while (str[i] != '\0' && str[i] != ' ')
	{
		(*res)[k][ct] = str[i];
		ct++;
		i++;
	}
	(*res)[k][ct] = '\0';
	return (i);
}

int	ct_words(char *str, char c)
{
	int	i;
	int	ct;

	ct = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			ct++;
		i++;
	}
	return (ct);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:33:35 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/06 14:01:22 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_linelen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

int	check_newline(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			j = i + 1;
			while (j < BUFFER_SIZE)
			{
				buff[j - (i + 1)] = buff[j];
				buff[j++] = '\0';
			}
			return (1);
		}
		buff[i++] = '\0';
	}
	return (0);
}

char	*thats_line(char *s1, char *s2)
{
	char	*str3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str3 = (char *)malloc(ft_linelen(s1) + ft_linelen(s2) + 1);
	if (!str3)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str3[i] = s2[j];
		i++;
		if (s2[j] == '\n')
			break ;
		j++;
	}
	str3[i] = '\0';
	free(s1);
	return (str3);
}

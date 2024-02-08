/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:28:34 by seozcan           #+#    #+#             */
/*   Updated: 2021/12/13 10:19:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && a == 0)
		return ((char *)s + ft_strlen(s));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (slen <= start)
		d = (char *)malloc(sizeof(char) * 1);
	else if (len > slen)
		d = (char *)malloc(sizeof(char) * ((slen - start) + 1));
	else
		d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
	{	
		free(d);
		return (NULL);
	}
	while (len-- && slen >= start)
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}

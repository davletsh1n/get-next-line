/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:24:16 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/15 13:04:44 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? (char*)s2 : (char*)s1);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(len * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (*s1)
		s3[i++] = *(s1++);
	while (*s2)
		s3[i++] = *(s2++);
	s3[i] = '\0';
	return ((char*)s3);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	copy = malloc(len * sizeof(char));
	if (copy == NULL)
		return (NULL);
	else
		while (*s1 != '\0')
			*copy++ = *s1++;
	*copy = '\0';
	return (copy - len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*copy;

	if (!s)
		return (NULL);
	copy = (char*)malloc(sizeof(*s) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			copy[j] = s[i];
			j++;
		}
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
	{
		i++;
	}
	return (s[i] == (char)c ? (char*)s + i : NULL);
}

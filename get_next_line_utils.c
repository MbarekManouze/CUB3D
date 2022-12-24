/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:22:09 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/08 08:57:35 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strchr(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*a;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	a = (char *)s;
	i = 0;
	j = 0;
	while (i < len && a[start + i])
		i++;
	sub = malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (j < i)
	{
		sub[j] = a[start + j];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strdup(const char	*s1)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	copy = malloc(len + 1 * sizeof(char));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		c;
	char	*store;

	i = 0;
	c = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	store = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!store)
		return (NULL);
	while (s1[i])
	{
		store[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		store[i] = s2[c++];
		i++;
	}
	store[i] = '\0';
	free(s1);
	return (store);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!*dst && !*src)
		return (0);
	while (src[j])
		j++;
	if (!len)
		return (j);
	i = 0;
	while (i < len - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
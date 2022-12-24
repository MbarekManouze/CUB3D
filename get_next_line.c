/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:10:40 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/07 14:11:06 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*after_line(char *buffer)
{
	int		i;
	int		j;
	char	*found_nl;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			found_nl = ft_substr(buffer, i + 1, ft_strlen(buffer) - i + 1);
			free(buffer);
			return (found_nl);
		}
		i++;
	}
	free(buffer);
	return (NULL);
}

char	*only_line(char *buffer)
{
	int		i;
	char	*one_allowed;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	one_allowed = ft_substr(buffer, 0, i + 1);
	return (one_allowed);
}

char	*read_file(int fd, char *buffer)
{
	int		i;
	char	*take_line;

	i = 1;
	take_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(buffer) && i)
	{
		i = read(fd, take_line, BUFFER_SIZE);
		if (i == -1)
		{
			free(take_line);
			return (NULL);
		}
		take_line[i] = 0;
		buffer = ft_strjoin(buffer, take_line);
	}
	free(take_line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = only_line(buffer);
	buffer = after_line(buffer);
	return (line);
}

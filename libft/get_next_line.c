/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:28 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/13 23:59:18 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	clean(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

char	*ft_strchr1(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_get_line(char **full_str)
{
	int		new_line_len;
	char	*str;
	char	*temp;
	char	*newline;

	if (!full_str || !*full_str)
		return (NULL);
	newline = ft_strchr1(*full_str, '\n');
	if (!newline)
		return (str = ft_strdup(*full_str), clean(full_str), str);
	else
	{
		new_line_len = newline - *full_str;
		str = ft_calloc(new_line_len + 2, sizeof(char));
		if (!str)
			return (clean(full_str), NULL);
		ft_strlcpy(str, *full_str, new_line_len + 1);
		temp = ft_strdup(*full_str + new_line_len + 1);
		clean(full_str);
		if (!temp)
			return (clean(&str), NULL);
		*full_str = temp;
	}
	return (str);
}

char	*read_and_join(int fd, char *str)
{
	int		bytes_read;
	char	*buffer;
	
	if (!str)
		str = ft_strdup("");

	while (!ft_strchr(str, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (clean(&str), clean(&buffer), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (clean(&buffer), clean(&str), NULL);
		if (bytes_read == 0)
		{
			clean(&buffer);
			if (str == NULL || *str == '\0')
				return (clean(&str), NULL);
			return (str);
		}
		str = ft_strjoin(str, buffer);
		clean(&buffer);
	}
	return (str);
}


char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_and_join(fd, str);
	if (!str)
		return (clean(&str), NULL);
	line = ft_get_line(&str);
	if (!line)
		return (clean(&str), NULL);
	return (line);
}

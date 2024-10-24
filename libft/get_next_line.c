/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:28 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/24 19:23:39 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

//void	clean(char **p)
//{
//	if (p && *p)
//	{
//		free(*p);
//		*p = NULL;
//	}
//}

//char	*ft_strchr1(char *s, char c)
//{
//	int	i;

//	i = 0;
//	if (!s)
//		return (NULL);
//	if (c == '\0')
//		return (&s[ft_strlen(s)]);
//	while (s[i])
//	{
//		if (s[i] == c)
//			return (&s[i]);
//		i++;
//	}
//	return (NULL);
//}

//char	*ft_get_line(char **full_str)
//{
//	int		new_line_len;
//	char	*str;
//	char	*temp;
//	char	*newline;

//	if (!full_str || !*full_str)
//		return (NULL);
//	newline = ft_strchr1(*full_str, '\n');
//	if (!newline)
//		return (str = ft_strdup(*full_str), clean(full_str), str);
//	else
//	{
//		new_line_len = newline - *full_str;
//		str = ft_calloc(new_line_len + 2, sizeof(char));
//		if (!str)
//			return (clean(full_str), NULL);
//		ft_strlcpy(str, *full_str, new_line_len + 1);
//		temp = ft_strdup(*full_str + new_line_len + 1);
//		clean(full_str);
//		if (!temp)
//			return (clean(&str), NULL);
//		*full_str = temp;
//	}
//	//free(temp);
//	//free(newline);
//	//free()
//	//clean(full_str);
//	return (str);
//}

//char	*read_and_join(int fd, char *str)
//{
//	int		bytes_read;
//	char	*buffer;
	
//	if (!str)
//		str = ft_strdup("");

//	while (!ft_strchr(str, '\n'))
//	{
//		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
//		if (!buffer)
//			return (clean(&str), clean(&buffer), NULL);
//		bytes_read = read(fd, buffer, BUFFER_SIZE);
//		if (bytes_read == -1)
//			return (clean(&buffer), clean(&str), NULL);
//		if (bytes_read == 0)
//		{
//			clean(&buffer);
//			if (str == NULL || *str == '\0')
//				return (clean(&str), NULL);
//			return (str);
//		}
//		str = ft_strjoin(str, buffer);
//		clean(&buffer);
//	}
//	return (str);
//}


//char	*get_next_line(int fd)
//{
//	static char	*str = NULL;
//	char		*line;

//	if (fd < 0 || BUFFER_SIZE <= 0)
//		return (NULL);
//	str = read_and_join(fd, str);
//	if (!str)
//		return (clean(&str), NULL);
//	line = ft_get_line(&str);
//	if (!line)
//		return (clean(&str), NULL);
//	//free(str);
//	return (line);
//}

char	*ft_strchrgnl(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ns = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ns == NULL)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		ns[i] = s1[i];
	while (s2[j])
		ns[i++] = s2[j++];
	ns[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), ns);
}

char	*read_line(int fd, char *ncall)
{
	int		b_read;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b_read = 1;
	while (!ft_strchrgnl(ncall, '\n') && b_read != 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buf);
			free(ncall);
			return (NULL);
		}
		buf[b_read] = '\0';
		ncall = ft_strjoin_g(ncall, buf);
	}
	free(buf);
	return (ncall);
}

char	*ft_get_line(char *ncall)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!ncall[i])
		return (NULL);
	while (ncall[i] != '\0' && ncall[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(ncall), NULL);
	while (j < i)
	{
		line[j] = ncall[j];
		j++;
	}
	if (ncall[i] == '\n')
	{
		line[i] = ncall[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*last_read(char *ncall)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (ncall[i] && ncall[i] != '\n')
		i++;
	if (!ncall[i])
	{
		free(ncall);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(ncall) - i + 1));
	if (!temp)
		return (free(ncall), NULL);
	i++;
	while (ncall[i])
		temp[j++] = ncall[i++];
	temp[j] = '\0';
	free(ncall);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*ncall;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ncall = read_line(fd, ncall);
	if (!ncall)
		return (NULL);
	line = ft_get_line(ncall);
	ncall = last_read(ncall);
	return (line);
}
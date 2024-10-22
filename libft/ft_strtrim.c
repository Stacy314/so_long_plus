/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:15:00 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/08 16:35:49 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



char	*ft_strtrim(char const *s1, char const *set)
{
	int		first_char;
	int		last_char;
	char	*res;

	if (s1 == 0 || set == 0)
		return (NULL);
	first_char = 0;
	last_char = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first_char]) && first_char <= last_char)
		first_char++;
	if (first_char > last_char)
		return (ft_strdup(s1 + last_char + 1));
	while (ft_strchr(set, s1[last_char]) && last_char >= 0)
		last_char--;
	res = malloc(last_char - first_char + 2);
	if (res == 0)
		return (NULL);
	ft_strlcpy(res, &s1[first_char], last_char - first_char + 2);
	return (res);
}

/*int main(void)
{
    char *s1 = "   Hello, world!   ";
    char *set = " ";
    char *trimmed = ft_strtrim(s1, set);

    if (trimmed != NULL)
    {
        printf("Trimmed string: \"%s\"\n", trimmed);
        free(trimmed);
    }
    else
        printf("Memory allocation failed\n");
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:51:52 by apechkov          #+#    #+#             */
/*   Updated: 2024/09/30 22:03:56 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (dup == 0)
		return (0);
	while (i >= 0)
	{
		dup[i] = s[i];
		i--;
	}
	return (dup);
}

/*int main() {
    char src[] = "Hello, world!";
    char *duplicate = ft_strdup(src);

    if (duplicate != NULL) 
    {
        printf("Original string: %s\n", src);
        printf("Duplicate string: %s\n", duplicate);
        free(duplicate);
    } 
    else 
        printf("Memory allocation failed.\n");
    return 0;
}*/

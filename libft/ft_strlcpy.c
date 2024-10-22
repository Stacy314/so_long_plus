/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:04:49 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/13 22:12:21 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	if (!dst && !src && !size)
// 		return (ft_strlen(src));
// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (src[i] != '\0' && i < (size - 1))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	while (src[i] != '\0')
// 		i++;
// 	return (i);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)  // Якщо хоча б один аргумент є NULL
		return (0);  // Повертаємо 0, бо немає даних для копіювання

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);  // Повертаємо довжину вихідного рядка
}


/*int main(void)
{
	char src[] = "Hello World!";
	char *dst = NULL;
	printf("%zu\n", ft_strlcpy(dst, src, 0));
	printf("%s\n", dst);
	return(0);
}*/

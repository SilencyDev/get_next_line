/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:06:07 by kmacquet          #+#    #+#             */
/*   Updated: 2021/02/03 14:25:43 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_strlen(const char *s)
{
	int		n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char		*ft_strdup(const char *str)
{
	char	*new;
	ssize_t	i;

	if (!(new = ft_memalloc(ft_strlen(str) + 1)))
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;
	char	*dest_init;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc(sizeof(char *) * len + 1)))
		return (NULL);
	dest_init = dest;
	while (*(char *)s1)
		*dest++ = *(char *)s1++;
	while (*(char *)s2)
		*dest++ = *(char *)s2++;
	*dest = '\0';
	return (dest_init);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s || !(dest = ((int)start >= ft_strlen(s)) ? malloc(1)
		: malloc(len + 1)))
		return (NULL);
	if ((int)start < ft_strlen(s))
		while (s[start] && len--)
			dest[i++] = (char)s[start++];
	dest[i] = '\0';
	return (dest);
}

char		*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
		if (!*str++)
			return (NULL);
	return (str);
}

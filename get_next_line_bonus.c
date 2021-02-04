/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:05:36 by kmacquet          #+#    #+#             */
/*   Updated: 2021/02/03 14:25:29 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = c;
	return (s);
}

int					ft_memdel(char **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE + (r = 1)];
	static char	*p_l[FD_SIZE];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	p_l[fd] == NULL ? p_l[fd] = ft_memalloc(1) : NULL;
	while (!ft_strchr(p_l[fd], '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(p_l[fd], bf);
		ft_memdel(&p_l[fd]);
		p_l[fd] = tmp;
	}
	if (r == 0)
		*line = ft_strdup(p_l[fd]);
	else if (r > 0)
		*line = ft_substr(p_l[fd], 0, (ft_strchr(p_l[fd], '\n') - p_l[fd]));
	else
		return (-1);
	tmp = ft_strdup(p_l[fd] + (ft_strlen(*line) + (r > 0 ? +1 : +0)));
	ft_memdel(&p_l[fd]);
	p_l[fd] = tmp;
	return (r == 0 ? 0 * ft_memdel(&p_l[fd]) : 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:04:19 by oespion           #+#    #+#             */
/*   Updated: 2018/06/09 13:33:51 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_n(char *str)
{
	int	r;

	r = 0;
	while (str[r])
	{
		if (str[r] == '\n')
			return (r + 1);
		r++;
	}
	return (-1);
}

void	ft_strleft(t_struct *lst, char **line)
{
	int	r;

	r = 0;
	while (lst->str[r])
	{
		if (lst->str[r] == '\n')
		{
			*line = ft_strnew(BUFF_SIZE);
			*line = ft_memmove(*line, lst->str, find_n(lst->str) - 1);
			lst->str = ft_strsub(lst->str, find_n(lst->str),
				ft_strlen(lst->str) - find_n(lst->str));
			return ;
		}
		r++;
	}
}

int		ft_read(t_struct *lst, char **line, const int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		i;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(*line))
		{
			if (!lst->str)
				*line = ft_strnew(0);
			else
				*line = lst->str;
		}
		buff[ret] = '\0';
		if (find_n(buff) == -1)
			*line = ft_strfjoin(*line, buff);
		else
		{
			i = 0;
			*line = ft_strfjoin(*line, buff);
			while ((*line)[i] != '\n')
				i++;
			(*line)[i] = '\0';
			lst->str = ft_strsub(buff, find_n(buff), BUFF_SIZE - find_n(buff));
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_struct	*lst;

	if (fd < 0 || fd > OPEN_MAX || fd == 1 || fd == 2)
		return (-1);
	if (!lst)
	{
		if (!(lst = (t_struct*)malloc(sizeof(t_struct))))
			return (-1);
		lst->str = 0;
	}
	if (lst->str)
		ft_strleft(lst, line);
	if (ft_read(lst, line, fd) == 1)
		return (1);
	if (!(*line))
		return (0);
	return (1);
}

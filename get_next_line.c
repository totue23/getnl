/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseminat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:25:59 by tseminat          #+#    #+#             */
/*   Updated: 2019/11/15 20:44:06 by tseminat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *str, unsigned int size)
{
	int		i;
	char	*up;

	i = 0;
	while (str[i] && i < size)
		i++;
	if (!(up = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		up[i] = str[i];
		i++;
	}
	up[i] = '\0';
	return (up);
}

/*void	ft_lst_push(t_list *li, char str)
{
	
}*/

int ft_check_buffer(char *str, int *line_l, int *rest_l)
{
	int i;
	int is_rest;

	i = 0;
	is_rest = 0;
	while (str[i])
	{
		if (is_rest)
			*rest_l += 1;
		else
			*line_l += 1;
		if (str[i] == '\n')
			is_rest++;
		i++;
	}
	return (is_rest);
}

void	ft_rest(char *buff, int line_l , int rest_l)
{
	static char *rest;
	int			nb_bn;
	
	if (rest)
	{
		
	}
	if (!(rest = malloc(sizeof(char) * rest_l + 1)))
		return ;
	nb_bn = ft_check_buffer(buf, &line_len, &rest_len);
	
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			is_el;
	int			line_len;
	int			rest_len;

	line_len = 0;
	is_el = 0;
	rest_len = 0;
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (is_el == 0)
	{
		if (!is_el)
			if (read(fd, buf, BUFFER_SIZE) == 0)
				is_el = -1;
		is_el = ft_rest((buf, rest_len));
	}
	*line = ft_strndup(buf, line_len);
	return (1);
}

int main(void)
{
	int fd = open("test", O_RDONLY);
	char **content;
	get_next_line(fd, content);

	printf("%s", *content);
	close(fd);
	
	return (0);
}

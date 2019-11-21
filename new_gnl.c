/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseminat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:07:09 by tseminat          #+#    #+#             */
/*   Updated: 2019/11/20 20:16:20 by tseminat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_check_bn(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

//Enter if buff has \n
char	*rest_lenloc(char *rest, char *next_line)
{
	int		i;
	char	*current;

	i = 0;
	i = ft_check_bn(rest);
	//printf("Len - current = %d\n", i);
	if (!(current = malloc(sizeof(char) * i + 1)))
			return (NULL);
	i = 0;
	while (rest[i] != '\n' && rest[i])
	{
		current[i] = rest[i];
		i++;
	}
	current[i] = '\0';
	//printf("string - current = %s\n", current);
	i = ft_strlen(ft_strchr(rest, '\n'));
	//printf("Len - next = %d\n", i);i
	if (!(next_line = malloc(sizeof(char) * i + 1)))
		return (NULL);
	next_line = ft_strchr(rest, '\n');
	//printf("string - current = %s\n", next_line);
	return (current);
}

void manage_rest(char *buff, char *rest, char **line)
{

}

void manage_buff(char *buff, int *is_el, char **line)
{
	static char *rest;
	char		*current;
	char		*new_rest;
	char		*tmp;

	if (ft_check_bn(buff))
	{
		*is_el = 1;
		current = rest_lenloc(buff, new_rest);
	}
	else
		current = ft_strdup(buff);
	if (rest)
	{
		if (*is_el)
		{
			printf("%s\n", rest);
			*line  = (char *)ft_strjoin(rest, current);
		}	
		else
		{
			tmp = ft_strjoin(rest, current);
			free(rest);
			rest = ft_strdup(tmp);
		}
	}
	else
		rest = ft_strdup(current);
}

int	get_next_line(int fd, char **line)
{
	char	*buff;
	int		is_el;
	int		is_eof;
	int		i;

	is_el = 0;
	is_eof = 1;
	i = 0;
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	buff[BUFFER_SIZE] = '\0';
	while (!is_el && is_eof)
	{
		if (i > 0)
		{
			free(buff);
			if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
				return (-1);
		}
		is_eof = read(fd, buff, BUFFER_SIZE);
		manage_buff(buff, &is_el, line);
		//printf("%d\n", is_el);
		i++;
	}
	return (1);
}

int main(void)
{
	int fd = open("test", O_RDONLY);
	char **content;
	char **test;
	get_next_line(fd, content);
	printf("%s\n", *content);
	get_next_line(fd, test);
	printf("%s\n", *test);

	return (0);
}

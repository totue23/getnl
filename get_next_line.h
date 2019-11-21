/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseminat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:27:59 by tseminat          #+#    #+#             */
/*   Updated: 2019/11/20 18:42:19 by tseminat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 4

/*typedef struct	s_list
{
	char			*buf;
	struct s_list	*next;
}				t_list;*/

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *str);



#endif

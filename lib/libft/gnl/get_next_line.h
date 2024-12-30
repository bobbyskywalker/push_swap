/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:55:57 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 17:57:41 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// an sll node structure built to effectively 
// store multiple fd's and their contents
typedef struct s_fd_content_storage
{
	int		fd;
	char	*content;
	void	*next;
}			t_fd_cs;

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *str);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strdup_gnl(const char *s);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);

#endif
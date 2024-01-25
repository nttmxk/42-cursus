/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:19:35 by jinoh             #+#    #+#             */
/*   Updated: 2022/01/29 00:54:41 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50000
# endif

char	*get_next_line(int fd);
int		ft_strchr_g(const char *s);
char	*ft_substr_g(char const *s, size_t len);
void	*ft_memmove_g(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_g(char *s1, char const *s2);

#endif

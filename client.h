/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:48:21 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 15:57:17 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# define PID_MAX 132768

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_error(void);
void	ft_check_input(char *s);

void	ft_send(int pid, char *s);

#endif

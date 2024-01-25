/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:58:26 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 20:00:46 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# define PID_MAX 100000

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_error(void);
void	ft_check_input(char *s);

void	sig_handler(int signo);
void	ft_send(int pid, char *s);

#endif

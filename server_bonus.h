/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:58:10 by jinoh             #+#    #+#             */
/*   Updated: 2022/02/03 16:15:48 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		check_pid(siginfo_t *info, int *pid);
void	ft_error(void);
void	sig_handler(int signo, siginfo_t *info, void *context);
void	set_sig(struct sigaction *act);

void	ft_error(void);
void	print_pid(void);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif

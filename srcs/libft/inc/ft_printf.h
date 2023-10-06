/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:51:08 by rbenjami          #+#    #+#             */
/*   Updated: 2023/05/05 14:55:54 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_hexbase16lc(unsigned int n, long int *count);
void	ft_hexbase16uc(unsigned int n, long int *count);
void	ft_printadress(unsigned long long int n, int check, long int *count);
void	ft_putchar(char c, long int *count);
void	ft_putnbr(int n, long int *count);
void	ft_putstr(char *s, long int *count);
void	ft_unsdec10(unsigned int n, long int *count);

#endif

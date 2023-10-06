/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:51:03 by rbenjami          #+#    #+#             */
/*   Updated: 2023/05/05 14:52:47 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printadress(unsigned long long int n, int check, long int *count)
{
	if (!n)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	if (check == 0)
	{
		ft_putstr("0x", count);
	}
	if (n >= 16)
		ft_printadress(n / 16, ++check, count);
	ft_putchar("0123456789abcdef"[n % 16], count);
}

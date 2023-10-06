/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexbase16lc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:50:56 by rbenjami          #+#    #+#             */
/*   Updated: 2023/05/05 14:55:27 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexbase16lc(unsigned int n, long int *count)
{
	if (n >= 16)
		ft_hexbase16lc(n / 16, count);
	ft_putchar("0123456789abcdef"[n % 16], count);
}

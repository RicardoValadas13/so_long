/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexbase16uc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:50:59 by rbenjami          #+#    #+#             */
/*   Updated: 2023/05/05 14:55:16 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexbase16uc(unsigned int n, long int *count)
{
	if (n >= 16)
		ft_hexbase16uc(n / 16, count);
	ft_putchar("0123456789ABCDEF"[n % 16], count);
}

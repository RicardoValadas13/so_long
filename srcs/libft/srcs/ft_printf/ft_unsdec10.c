/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsdec10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:51:22 by rbenjami          #+#    #+#             */
/*   Updated: 2023/05/05 14:52:31 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsdec10(unsigned int n, long int *count)
{
	if (n >= 10)
		ft_unsdec10(n / 10, count);
	ft_putchar(n % 10 + '0', count);
}

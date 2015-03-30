/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:54:02 by psaint-j          #+#    #+#             */
/*   Updated: 2014/11/15 16:28:07 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*s;
	unsigned char	ch;

	ch = (unsigned char)c;
	s = (char*)b;
	i = 0;
	while (i != len)
	{
		s[i] = ch;
		i++;
	}
	return (s);
}

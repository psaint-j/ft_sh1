/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:18:16 by psaint-j          #+#    #+#             */
/*   Updated: 2014/11/19 17:40:28 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	n1;
	size_t	n2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n1 = 0;
	n2 = 0;
	while (s1[n1] != '\0')
		n1++;
	while (s2[n2] != '\0' && n2 < n)
	{
		s1[n1] = s2[n2];
		n1++;
		n2++;
	}
	s1[n1] = '\0';
	return (s1);
}

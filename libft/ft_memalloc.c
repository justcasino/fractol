/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 03:34:45 by jcasino           #+#    #+#             */
/*   Updated: 2016/11/18 01:01:30 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"


void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void*)malloc(size);
	if (mem == NULL)
		return (NULL);
	else
		return (ft_memset(mem, 0, size));
}

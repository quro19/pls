/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:14:43 by qbackaer          #+#    #+#             */
/*   Updated: 2019/06/12 18:02:57 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 

void	ft_freetab(char **tab)
{
	char **roam;

	if (!tab)
		return ;
	roam = tab;
	while (*roam)
	{
		free(*roam);
		roam++;
	}
	free(tab);
}

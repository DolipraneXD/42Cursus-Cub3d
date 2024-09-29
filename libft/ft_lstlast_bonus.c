/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:26 by moel-fat          #+#    #+#             */
/*   Updated: 2023/11/21 17:46:09 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*last;

	if (!lst)
		return (NULL);
	current = lst;
	last = NULL;
	while (current != NULL)
	{
		last = current;
		current = current -> next;
	}
	return (last);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_making.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-mora <mal-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:32:47 by moel-fat          #+#    #+#             */
/*   Updated: 2024/09/22 10:39:31 by mal-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_lstsizemap(t_data *lst)
{
	int		i;
	t_data	*current;

	if (!lst)
		return (0);
	current = lst;
	i = 0;
	while (current != NULL)
	{
		current = current -> next;
		i++;
	}
	return (i);
}

t_data	*ft_lstlastmap(t_data *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_data	*ft_lstnewmap(char *data)
{
	t_data	*newnode;

	newnode = (t_data *)malloc(sizeof(t_data));
	if (newnode == NULL)
		return (NULL);
	newnode -> data = data;
	newnode -> next = NULL;
	return (newnode);
}

void	ft_lstadd_backmap(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlastmap(*lst);
	last -> next = new;
}

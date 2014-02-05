/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:54:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/05 21:01:47 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add_elem(t_list **list, char c, t_data *data)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *list;
	new = (t_list *)malloc(sizeof(t_list));
	new->c = c;
	new->printed = 0;
	new->next = NULL;
	new->prev = NULL;
	if (*list == NULL)
	{
		*list = new;
		data->charly = new;
		return ;
	}
	if (data->charly->next != NULL)
	{
		new->next = data->charly->next;
		data->charly->next->prev = new;
	}
	new->prev = data->charly;
	data->charly->next = new;
	data->charly = new;
}

void	ft_print_list(t_list *list)
{
	t_list	*tmp;

	/* if (list == NULL) */
	/* 	return ; */
	tmp = list;
	tputs(tgetstr("dl", NULL), 1, tputs_putchar);
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	while (tmp != NULL)
	{
		ft_putchar(tmp->c);
		tmp->printed = 1;
		tmp = tmp->next;
	}
}

t_list *del_elem(t_list *list, t_data *data)
{
	t_list	*tmp;

	data->i = 0;
	if (list)
	{
		if (list->prev == NULL)
			return (list);
		tmp = list;
		if (list->prev != NULL)
			list->prev->next = list->next;
		if (list->next != NULL)
			list->next->prev = list->prev;
		if (list->prev != NULL)
			list = list->prev;
		free(tmp);
		data->cursor--;
		data->real_cursor--;
		ft_print_list(data->list);
	}
	return (list);
}

t_li	*add_list(t_li *list, t_data *data)
{
	t_li	*tmp;
	t_li	*new;
	t_list	*tmp2;
	t_li	*tmp3;

	tmp = list;
	tmp2 = data->list;
	new = (t_li *)malloc(sizeof(t_li));
	new->ptr = tmp2;
	new->next = NULL;
	new->prev = NULL;
	if (list == NULL)
		return (new);
	while (tmp->next != NULL)
	{
		tmp3 = tmp;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
	tmp->prev = tmp3;
	data->list = NULL;
	data->charly2 = tmp;
	data->charly2->prev = tmp->prev;
	data->charly2->next = tmp->next;
	return (list);
}

void	ft_print_history(t_li *list)
{
	t_li	*tmp;

	tmp = list;
	while (tmp)
	{
		tputs(tgetstr("dl", NULL), 1, tputs_putchar);
		ft_print_list(tmp->ptr);
		tmp = tmp->next;
	}
}

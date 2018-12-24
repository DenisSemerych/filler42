/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:24:57 by dsemeryc          #+#    #+#             */
/*   Updated: 2018/11/01 19:23:19 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*crawler;
	t_list	*tmp;

	if (!*alst || !del)
		return ;
	crawler = *alst;
	while (crawler->next)
	{
		del(crawler->content, crawler->content_size);
		tmp = crawler;
		crawler = crawler->next;
		free(tmp);
	}
	del(crawler->content, crawler->content_size);
	free(crawler);
	*alst = NULL;
}

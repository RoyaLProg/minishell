/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:00:40 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/22 12:50:31 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**env_to_tab(t_minishell *ms)
{
	char	**ret_v;
	char	*s_tmp;
	size_t	nb_element;
	size_t	i;
	t_env	*tmp;

	nb_element = count_env(ms->e_head);
	ret_v = ft_malloc(sizeof(char *) * (nb_element + 1), ms);
	if (!ret_v)
		return (ret_v);
	i = 0;
	tmp = ms->e_head;
	while (tmp != NULL)
	{
		s_tmp = ft_strjoin(tmp->key, "=", ms);
		ret_v[i] = ft_strjoin(s_tmp, tmp->value, ms);
		ft_free(s_tmp, ms);
		tmp = tmp->next;
		i++;
	}
	ret_v[i] = NULL;
	return (ret_v);
}

char	**args_to_tab(t_token *token, t_minishell *ms)
{
	char	**ret_v;
	size_t	nb_element;
	size_t	i;
	t_arg	*arg;

	arg = token->arg_head;
	if (!arg)
		return (NULL);
	nb_element = count_arg(token->arg_head);
	ret_v = ft_malloc(sizeof(char *) * (nb_element + 1), ms);
	if (!ret_v)
		return (ret_v);
	i = 0;
	while (arg != NULL)
	{
		ret_v[i] = arg->value;
		arg = arg->next;
		i++;
	}
	ret_v[i] = NULL;
	return (ret_v);
}

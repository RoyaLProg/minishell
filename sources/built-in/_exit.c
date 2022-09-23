/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:14:18 by gbertin           #+#    #+#             */
/*   Updated: 2022/09/23 11:37:02 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void exec_child(t_token *token, t_minishell *ms)
{
	if (init_execute(token))
		{
			free_all(ms);
			exit(1);
		}
		redir_out(token);
		if (token->arg_head)
		{
			if (!check_arg(token, ms))
			{
				free_all(ms);
				exit (ft_atoll(token->arg_head->value) % 256);
			}
		}
}

static int	exec_in_child(t_token *token, t_minishell *ms)
{
	int ret_v;
	
	if (token->next)
	{
		if (pipe(token->pipefd))
			return (1);
	}
	token->pid = fork();
	if (token->pid == 0)
	{
		exec_child(token, ms);
		ret_v = ms->l_retv;
		free_all(ms);
		exit(ret_v);
	}
	return (1);
}

int	b_exit(t_token *token, t_minishell *ms)
{
	int	ret_v;

	if (count_token(ms->t_head) > 1)
	{
		exec_in_child(token, ms);
	}
	else
	{
		ret_v = ms->l_retv;
		printf("exit\n");
		if (token->arg_head)
		{
			if (!check_arg(token, ms))
				ret_v = ft_atoll(token->arg_head->value) % 256;
			else
				ret_v = ms->l_retv;
		}
		rl_clear_history();
		free_all(ms);
		exit(ret_v);
	}
	return (0);
}

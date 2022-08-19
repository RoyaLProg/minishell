/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:17:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/19 13:48:06 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	next_var(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '$')
		i++;
	return (i);
}

static void	expand_arg(t_token *token, t_minishell *ms)
{
	t_arg	*arg;
	size_t	i;
	char	*tmp;

	arg = token->arg_head;
	while (arg)
	{
		if (arg->apos == 1 || !arg->value)
		{
			arg = arg->next;
			continue ;
		}
		i = next_var(arg->value);
		while (arg->value[i])
		{
			tmp = arg->value;
			arg->value = replace_var(arg->value, i, ms);
			if (!arg->value)
				arg->value = tmp;
			else
				ft_free(tmp, ms);
			i = next_var(arg->value);
		}
		arg = arg->next;
	}
}

static void	expand_file(t_token *token, t_minishell *ms)
{
	t_file	*file;
	size_t	i;
	char	*tmp;

	file = token->file_head;
	while (file)
	{
		if (file->apos == 1 || !file->path)
		{
			file = file->next;
			continue ;
		}
		i = next_var(file->path);
		while (file->path[i])
		{
			tmp = file->path;
			file->path = replace_var(file->path, i, ms);
			if (!file->path)
				file->path = tmp;
			else
				ft_free(tmp, ms);
			i = next_var(file->path);
		}
		file = file->next;
	}
}

static void	expand_cmd(t_token *token, t_minishell *ms)
{
	char	*tmp;
	size_t	i;

	printf("%s\n", token->cmd);
	if (token->cmd == NULL)
		return ;
	i = next_var(token->cmd);
	while (token->cmd[i])
	{
		if (token->cmd[i] == 0)
			return ;
		tmp = token->cmd;
		token->cmd = replace_var(token->cmd, i, ms);
		if (!token->cmd)
			token->cmd = tmp;
		else
			ft_free(tmp, ms);
		i = next_var(token->cmd);
	}
}

void	expand(t_minishell *ms)
{
	t_token	*token;

	token = ms->t_head;
	while (token)
	{
		expand_cmd(token, ms);
		expand_arg(token, ms);
		expand_file(token, ms);
		token = token->next;
	}
}

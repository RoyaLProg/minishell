/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:41:34 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/30 10:05:41 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_if_file_usable(t_token *token)
{
	if (token->have_in)
	{
		if (token->inputfile->usable)
			return (1);
	}
	if (token->have_out)
	{
		if (token->outputfile->usable)
			return (1);
	}
	return (0);
}

int	exec_first_cmd(t_exec *exec, t_minishell *ms)
{
	exec->path = make_path(exec, ms);
	exec->token->pid = fork();
	if (exec->token->pid < 0)
		return (1);
	if (exec->token->pid == 0)
	{
		if (init_execute(exec->token))
			return (1);
		if (check_if_file_usable(exec->token))
			exit(1);
		if (exec->token->have_in)
		{
			if (dup2(exec->token->inputfile->fd, 0) == -1)
				perror("minishell ");
		}
		redir_out(exec->token);
		if (exec->path)
			execve(exec->path, exec->args, exec->env);
		perror("minishell ");
		exit (127);
	}
	return (0);
}

int	exec_middle(char **args, t_exec *exec, t_minishell *ms)
{
	char	*path;

	path = make_path(exec, ms);
	if (pipe(exec->token->pipefd))
		perror("minishell ");
	exec->token->pid = fork();
	if (exec->token->pid < 0)
		return (1);
	if (exec->token->pid == 0)
	{
		if (init_execute(exec->token))
			return (1);
		redir_in(exec->token, exec->last);
		redir_out(exec->token);
		if (path)
			execve(path, args, exec->env);
		perror("minishell ");
		exit (127);
	}
	return (0);
}

int	exec_last(char **args, t_exec *exec, t_minishell *ms)
{
	char	*path;

	path = make_path(exec, ms);
	exec->token->pid = fork();
	if (exec->token->pid < 0)
		return (1);
	if (exec->token->pid == 0)
	{
		init_execute(exec->token);
		redir_in(exec->token, exec->last);
		if (exec->token->have_out)
		{
			if (dup2(exec->token->outputfile->fd, 1) == -1)
				perror("minishell ");
		}
		if (path)
			execve(path, args, exec->env);
		perror("minishell ");
		exit (127);
	}
	return (0);
}

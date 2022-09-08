/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:58:16 by ccambium          #+#    #+#             */
/*   Updated: 2022/09/08 16:58:21 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

char	_cd(t_token *token, t_minishell *ms);
int		_env(t_minishell *ms);
int		_export(t_token *token, t_minishell *ms);
int		check_append_export(char *export);
t_env	*get_node_env(char *key, t_minishell *ms);
int		append_export(t_arg *arg, t_minishell *ms);
int		_pwd(t_token *token);
int		_unset(char *key, t_minishell *ms);
int		_echo(t_token *token);
int		b_exit(t_token *token, t_minishell *ms);

int		check_is_built_in(t_token *token);
int		exec_builtin(t_token *token, t_minishell *ms);
int		exec_env(t_token *token, t_minishell *ms);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:09:49 by ccambium          #+#    #+#             */
/*   Updated: 2022/10/25 17:54:41 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	expand_arg_multi2(char **argv, t_minishell *ms,
			t_arg **first, t_arg **last)
{
	size_t	i;
	t_arg	*a;

	i = 0;
	a = ft_malloc(sizeof(t_arg), ms);
	if (!a)
		return (1);
	while (argv[++i])
	{
		a->value = ft_strdup(argv[i], ms);
		if (i == 1)
			*first = a;
		if (argv[i + 1])
		{
			a->next = ft_malloc(sizeof(t_arg), ms);
			if (!a->next)
				return (1);
			a = a->next;
			continue ;
		}
		else
			*last = a;
	}
	return (0);
}

static char	expand_arg_multi(t_arg *arg, char **argv, char *w, t_minishell *ms)
{
	t_arg	*first;
	t_arg	*last;
	char	*tmp;

	arg->value = replace_var_multi(arg->value, (size_t)(w - arg->value),
			argv[0], ms);
	if (!arg->value)
		return (1);
	tmp = ft_substr(arg->value, (size_t)(w - arg->value), ft_strlen(w), ms);
	if (!tmp)
		return (1);
	arg->value = ft_substr(arg->value, 0, (size_t)(w - arg->value), ms);
	if (!arg->value)
		return (1);
	if (expand_arg_multi2(argv, ms, &first, &last))
		return (EXIT_FAILURE);
	last->value = ft_strjoin(last->value, tmp, ms);
	if (!last->value)
		return (1);
	last->next = arg->next;
	arg->next = first;
	return (0);
}

static char	expand_arg2(t_arg *arg, char *i, t_minishell *ms)
{
	char	*tmp;
	char	**arg_value;
	char	*key;

	key = read_var(++i, ms);
	tmp = get_env_value(key, ms);
	ft_free(key, ms);
	if (!tmp)
		tmp = ft_strdup("", ms);
	arg_value = ft_split_set(tmp, " \n\r\v\t\f", ms);
	if (count_tab(arg_value) == 1)
	{
		if (arg_value)
			arg->value = replace_var_multi(arg->value, --i - arg->value,
					arg_value[0], ms);
	}
	else if (count_tab(arg_value) > 1)
	{
		if (expand_arg_multi(arg, arg_value, --i, ms))
			return (free_split(arg_value, ms), 1);
	}
	else
		arg->value = replace_var_multi(arg->value, --i - arg->value,
				"", ms);
	return (free_split(arg_value, ms), 0);
}

char	expand_arg(t_token *token, t_minishell *ms)
{
	t_arg	*arg;
	char	*i;

	arg = token->arg_head;
	if (!arg || !arg->value)
		return (0);
	i = ft_strchr(arg->value, '$');
	while (arg)
	{
		if (!i || !*i || i[1] == '\0' || is_space(i[1]) || i[1] == '$')
		{
			arg = arg->next;
			continue ;
		}
		if (between_quote(arg->value, (i - arg->value)))
		{
			i = ft_strchr(i + 1, '$');
			continue ;
		}
		if (expand_arg2(arg, i, ms))
			return (1);
		i = ft_strchr(arg->value, '$');
	}
	return (0);
}

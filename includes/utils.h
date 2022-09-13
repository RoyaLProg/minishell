/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:07:10 by ccambium          #+#    #+#             */
/*   Updated: 2022/09/13 13:29:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

size_t		count_arg(t_arg *ptr);
size_t		count_env(t_env *ptr);
size_t		count_tab(char **tab);
size_t		count_file(t_file *ptr);
size_t		count_token(t_token *ptr);
size_t		size_t_ternary(char condition, size_t a, size_t b);

char		**env_to_tab(t_minishell *ms);
char		**args_to_tab(t_token *token, t_minishell *ms);

char		*get_pwd(t_minishell *ms);
char		*ft_superjoin(char **s, t_minishell *ms);
char		*get_env_value(char *key, t_minishell *ms);
char		*string_ternary(char condition, char *true, char *false);
char		*check_cd_path(char *path, char **all_cdpath, t_minishell *ms);

void		free_all(t_minishell *ms);
void		free_tokens(t_minishell *ms);
void		init_minishell(t_minishell *ms);
void		ft_free(void *ptr, t_minishell *ms);
void		add_end_arg(t_arg *head, t_arg *obj);
void		add_end_obj(t_obj *head, t_obj *obj);
void		add_end_file(t_token *token, t_file *obj);
void		add_end_token(t_token *obj, t_minishell *ms);
void		modify_env(char *key, char *value, t_minishell *ms);
void		replace_env_value(char *key, char *value, t_minishell *ms);
void		add_env_key_value(char *key, char *value, t_minishell *ms);

long long	ft_atoll(const char *str);
long long	get_size_of_cmd(char *cmd);
long long	ft_lliota(long long n, t_minishell *ms);
long long	next_arg(char *s, t_token *token, t_minishell *ms);

char		is_space(char c);
char		token_is_empty(t_token *t);
char		between_quote(char *s, size_t x);
char		do_env_key_exist(char *key, t_minishell *ms);
char		char_ternary(char condition, char true, char false);

int			ft_error(char *msg);
int			check_key_env(char *s);
int			ft_strcmp(char *str1, char *str2);
int			add_key_with_empty_value(char *s, t_minishell *ms);

void		*ft_malloc(size_t size, t_minishell *ms);

#endif

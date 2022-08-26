/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_type_file_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:59:20 by gbertin           #+#    #+#             */
/*   Updated: 2022/08/26 12:22:50 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	have_infile(t_token *token)
{
	t_file	*file;

	file = token->file_head;
	while (file)
	{
		if (file->type == 0)
			return (1);
		file = file->next;
	}
	return (0);
}

int	have_outfile(t_token *token)
{
	t_file	*file;

	file = token->file_head;
	while (file)
	{
		if (file->type == 1)
			return (1);
		file = file->next;
	}
	return (0);
}

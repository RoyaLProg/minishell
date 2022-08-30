/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:17:12 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/30 11:59:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H
//# include "../includes/minishell.h"
# include "../includes/structures.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>

size_t	count_arg(t_arg *ptr);

# define LINK "─"
# define TOP_LEFT "┌"
# define TOP_RIGHT "┐"
# define VLINK "│"
# define T_SHAPE "┬"
#endif

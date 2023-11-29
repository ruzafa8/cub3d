/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:48:31 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/29 20:48:34 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error
{
	NO_ERROR,
	FILE_EXTENSION_ERROR,
	NUM_ARGS_ERROR,
	FILE_OPEN_ERROR,
	MEMORY_ERROR,
	PARSER_ERROR,
}	t_error;

#endif
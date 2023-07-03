/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:01:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/03 22:56:11 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H
# define OPEN_FILE_ERROR "Error\nFile can not open\n"
# define COUNT_ERROR "Error\nOnly one file allowed\n"
# define FILE_EXTENSION_ERROR "Error\nOnly files with the '.rt' \
extension allowed\n"
# define INVALID_LINE "Error\nYour file have an invalid line.\n"
# define INTERFACE_ERROR "Error\nNo graphical interface.\n"
# define WRONG_RESOLUTION "Error\n The Resolution parameter should be \
in the following format: 'R HEIGHT WIDTH'."
# define MAX_RESOLUTION "Error\nThe Resolution parameter must adhere to the MAX_HEIGHT \
and MAX_WIDTH macros. You can redefine these macros during \
compilation using the '-D' flag.\n"

#endif
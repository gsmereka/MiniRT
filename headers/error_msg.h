/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:01:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/07/06 22:12:48 by gsmereka         ###   ########.fr       */
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
# define REPEATED "Error\nThe parameters R (Resolution), A \
(Ambient Lighting), and C (Camera) cannot be repeated.\n"
# define NEED_ALL_COMPONENTS "Error\nYou need light, camera and \
ambient lighting!\n"

// Is Ambient Lighting
# define AMBIENT_ERROR "Error\nThe 'A' (Ambient Lighting) parameter, should be \
in the following format: 'A RATIO COLOR'.\n"
# define AMBIENT_RATIO_ERROR "Error\nThe 'A' (Ambient Lighting) ratio parameter should be \
in range [0,1],\n"
# define AMBIENT_COLOR_ERROR "Error\nThe 'A' (Ambient Lighting) color parameter should be \
in the following format: '0,0,0' in range [0-255].\n"

// Is Camera
# define CAMERA_ERROR "Error\nThe 'C' (Camera) parameter, should be \
in the following format: 'C COORDINATE 3D_NORMALIZED_VECTOR FOV'.\n"
# define CAMERA_COORDINATE_ERROR "Error\nThe 'C' (Camera) coordinate parameter should be \
in the following format: '0.0,0.0,0.0'.\n"
# define CAMERA_3D_NORMALIZED_VECTOR_ERROR "Error\nThe 'C' (Camera) 3d normalized normal vector \
parameter, should be in the following format: '0.0,0.0,0.0' in range [0-1].\n"
# define CAMERA_FOV_ERROR "Error\nThe 'C' (Camera) FOV parameter should be \
in range [0-180].\n"

// Is Light
# define LIGHT_ERROR "Error\nThe 'L' (Light) parameter, should be \
in the following format: 'L COORDINATE 3D_NORMALIZED_VECTOR BRIGHTNESS \
COLOR(BONUS ONLY)'.\n"
# define LIGHT_COORDINATE_ERROR "Error\nThe 'L' (Light) coordinate parameter should be \
in the following format: '0.0,0.0,0.0'.\n"
# define LIGHT_3D_NORMALIZED_VECTOR_ERROR "Error\nThe 'L' (Light) 3d normalized normal vector \
parameter, should be in the following format: '0.0,0.0,0.0' in range [0-1].\n"
# define LIGHT_BRIGHTNESS_ERROR "Error\nThe 'L' (Light) brightness \
parameter, should be in in range [0-1].\n"
# define LIGHT_COLOR_ERROR "Error\nThe 'L' (Light) color parameter should be \
in the following format: '0,0,0' in range [0-255].\n"

// Is Resolution
# define WRONG_RESOLUTION "Error\nThe Resolution parameter should be \
in the following format: 'R WIDTH HEIGHT'.\n"
# define MAX_RESOLUTION "Error\nThe Resolution parameter must adhere to the MAX_HEIGHT \
and MAX_WIDTH macros. You can redefine these macros during \
compilation using the '-D' flag.\n"

// Is Plane
# define PLANE_ERROR "Error\nThe 'pl' (Plane) parameter, should be \
in the following format: 'pl COORDINATE 3D_NORMALIZED_VECTOR COLOR'.\n"
# define PLANE_COORDINATE_ERROR "Error\nThe 'pl' (Plane) coordinate parameter should be \
in the following format: '0.0,0.0,0.0'.\n"
# define PLANE_3D_NORMALIZED_VECTOR_ERROR "Error\nThe 'pl' (Plane) 3d normalized normal vector \
parameter, should be in the following format: '0.0,0.0,0.0' in range [0-1].\n"
# define PLANE_COLOR_ERROR "Error\nThe 'pl' (Plane) color parameter should be \
in the following format: '0,0,0' in range [0-255].\n"

// Is Sphere
# define SPHERE_ERROR "Error\nThe 'sp' (Sphere) parameter, should be \
in the following format: 'sp COORDINATE DIAMETER COLOR'.\n"
# define SPHERE_COORDINATE_ERROR "Error\nThe 'sp' (Sphere) coordinate parameter should be \
in the following format: '0.0,0.0,0.0'.\n"
# define SPHERE_DIAMETER_ERROR "Error\nThe 'sp' (Sphere) diameter \
parameter, should be positive\n"
# define SPHERE_COLOR_ERROR "Error\nThe 'sp' (Sphere) color parameter should be \
in the following format: '0,0,0' in range [0-255].\n"

// Is Cylinder
# define CYLINDER_ERROR "Error\nThe 'cy' (Cylinder) parameter, should be \
in the following format: 'cy COORDINATE 3D_NORMALIZED_VECTOR DIAMETER \
HEIGHT COLOR'.\n"
# define CYLINDER_COORDINATE_ERROR "Error\nThe 'cy' (Cylinder) coordinate parameter should be \
in the following format: '0.0,0.0,0.0'.\n"
# define CYLINDER_3D_NORMALIZED_VECTOR_ERROR "Error\nThe 'cy' (Cylinder) 3d normalized normal vector \
parameter, should be in the following format: '0.0,0.0,0.0' in range [0-1].\n"
# define CYLINDER_DIAMETER_ERROR "Error\nThe 'cy' (Cylinder) diameter \
parameter, should be positive\n"
# define CYLINDER_HEIGHT_ERROR "Error\nThe 'cy' (Cylinder) height \
parameter, should be positive\n"
# define CYLINDER_COLOR_ERROR "Error\nThe 'cy' (Cylinder) color parameter should be \
in the following format: '0,0,0' in range [0-255].\n"

#endif
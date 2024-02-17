/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:06 by gsmereka          #+#    #+#             */
/*   Updated: 2024/02/17 18:21:44 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

// double	calculate_discriminant(t_intersect *intersect,
// 	t_token *cylinder, t_ray *ray)
// {
// 	double	d;
// 	t_tuple	distance_to_center;
// 	t_tuple	cylinder_center;

// 	cylinder_center = cylinder->coordinate;
// 	distance_to_center = subtract_tuples(&ray->origin, &cylinder_center);
// 	intersect->a = dot_product(&ray->direction, &ray->direction);
// 	intersect->b = dot_product(&ray->direction, &distance_to_center) * 2.0; //ao contrario as tuplas? --n fez diferença
// 	intersect->c = dot_product(&distance_to_center, &distance_to_center) - \
// 		pow(cylinder->diameter/2, 2);
// 	d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
// 	return (d);
// }

// double	calculate_cylinder_distance(t_token *cylinder, t_ray *ray)
// {
// 	t_intersect	intersect;
// 	double		discriminant;
// 	double		distance;

// 	intersect = (t_intersect){0};
// 	discriminant = calculate_discriminant(&intersect, cylinder, ray);
// 	if (discriminant <= 0)
// 		return (0);
// 	intersect.solutions[0]
// 		= (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
// 	intersect.solutions[1]
// 		= (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);

// 	//fmin e fmax?

// 	if (intersect.solutions[0] <= 0 && intersect.solutions[1] <= 0)
// 		return (0);
// 	// if (intersect.solutions[0] < intersect.solutions[1])
// 	// 	distance = intersect.solutions[0];
// 	// else
// 	// 	distance = intersect.solutions[1];
// 	if (intersect.solutions[0] >= 0)
// 		distance = intersect.solutions[0];
// 	else
// 		distance = intersect.solutions[1];
// 	return (distance);
// }

// t_hit	*intersect_cylinder(t_token *cylinder, t_ray *ray)
// {
// 	double	distance;
// 	t_tuple	hit_point;
// 	t_tuple	normal;
// 	t_hit	*hit;

// 	distance = calculate_cylinder_distance(cylinder, ray);
// 	if (!distance)
// 		return (NULL);
// 	hit_point = ray_position(ray, distance);  
// 	normal = cylinder->normalized_3d_direction;
// 	hit = init_hit(cylinder, &normal, distance, &hit_point);
// 	return (hit);
// }



// altura do cilindro????? ----ver como os shapes são salvos

t_tuple calculate_normal_cylinder(t_token *cylinder, t_tuple *hit_point)
{
    // O cálculo da normal depende da posição do ponto de interseção no cilindro
    // e da orientação do cilindro (vertical ou horizontal).
    // Se o cilindro é vertical, a normal é a direção do ponto de interseção para o eixo do cilindro.
    // Se for horizontal, a normal é a direção perpendicular à superfície do cilindro no ponto de interseção.
    // Aqui, supomos que estamos lidando com um cilindro vertical para simplificar o exemplo.

    t_tuple normal;
    t_tuple axis_point;
    t_tuple hit_to_axis;

    axis_point = cylinder->coordinate; // Supondo que esta seja a posição central do cilindro
    hit_to_axis = subtract_tuples(hit_point, &axis_point);
    normalize_tuple(&hit_to_axis);
    normal = hit_to_axis;
    return (normal);
}

double  calculate_discriminant_cylinder(t_intersect *intersect,
    t_token *cylinder, t_ray *ray)
{
    double  d;
    t_tuple distance_to_axis;
    t_tuple axis_point;
    t_tuple cylinder_direction;
    double  r;

    // Para um cilindro, o eixo é definido pela direção do cilindro.
    // Se o cilindro é vertical, o eixo será paralelo ao eixo y, por exemplo.
    // Se for horizontal, o eixo será paralelo ao eixo z, por exemplo.
    cylinder_direction = cylinder->direction;
    // Calcula a distância do ponto inicial do raio ao eixo do cilindro
    axis_point = cylinder->coordinate; // Supondo que esta seja a posição central do cilindro
    distance_to_axis = subtract_tuples(&ray->origin, &axis_point);
    // Calcula o discriminante como no caso da esfera, mas com um ajuste para a direção do cilindro
    intersect->a = dot_product(&ray->direction, &ray->direction)
                 - pow(dot_product(&ray->direction, &cylinder_direction), 2);
    intersect->b = 2 * (dot_product(&ray->direction, &distance_to_axis)
                       - dot_product(&ray->direction, &cylinder_direction)
                       * dot_product(&distance_to_axis, &cylinder_direction));
    r = cylinder->diameter / 2.0; // Raio do cilindro
    intersect->c = dot_product(&distance_to_axis, &distance_to_axis)
                 - pow(dot_product(&distance_to_axis, &cylinder_direction), 2)
                 - r * r;
    d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
    return (d);
}

double  calculate_distance_cylinder(t_token *cylinder, t_ray *ray)
{
    t_intersect intersect;
    double      discriminant;
    double      distance;

    intersect = (t_intersect){0};
    discriminant = calculate_discriminant_cylinder(&intersect, cylinder, ray);
    if (discriminant <= 0)
        return (0);
    intersect.solutions[0]
        = (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
    intersect.solutions[1]
        = (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);
    // Verificamos se os pontos de interseção estão dentro do cilindro
    // A lógica específica para isso depende do tipo de cilindro (infinito ou limitado)
    // e da orientação do cilindro (vertical ou horizontal).
    // Se for um cilindro infinito, você pode simplesmente verificar se os pontos de interseção estão na altura do cilindro.
    // Se for um cilindro limitado, você também precisa verificar se os pontos de interseção estão dentro do intervalo de altura do cilindro.
    // A orientação do cilindro também afeta como você verifica a interseção.
    // Por exemplo, para um cilindro vertical, a interseção é determinada pela distância do raio ao eixo central do cilindro.
    // Já para um cilindro horizontal, a interseção é determinada pela distância do raio ao plano que contém o cilindro.
    // Aqui, supomos que estamos lidando com um cilindro infinito e vertical para simplificar o exemplo.
    if (intersect.solutions[0] <= 0 && intersect.solutions[1] <= 0)
        return (0);
    if (intersect.solutions[0] < intersect.solutions[1])
        distance = intersect.solutions[0];
    else
        distance = intersect.solutions[1];
    return (distance);
}

t_hit   *intersect_cylinder(t_token *cylinder, t_ray *ray)
{
    double      distance;
    t_tuple     hit_point;
    t_tuple     normal;
    t_hit       *hit;

    distance = calculate_distance_cylinder(cylinder, ray);
    if (!distance)
        return (NULL);
    hit_point = ray_position(ray, distance);
    normal = calculate_normal_cylinder(cylinder, &hit_point);
    hit = init_hit(cylinder, &normal, distance, &hit_point);
    return (hit);
}

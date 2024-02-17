/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:29:10 by gde-mora          #+#    #+#             */
/*   Updated: 2024/02/17 19:03:21 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/miniRT.h"

t_tuple calculate_normal_cylinder(t_token *cylinder, t_tuple *hit_point)
{
	(void)hit_point; //precisa do hit_point?
    // Normal é a direção do ponto de interseção para o eixo do cilindro
    t_tuple axis_direction = subtract_tuples(&cylinder->endpoint2, &cylinder->endpoint1);
    normalize_tuple(&axis_direction);
    return axis_direction;
}

int is_inside_cylinder(t_token *cylinder, t_tuple *point)
{
    // Verificar se o ponto está entre as extremidades do cilindro
    return (point->x >= cylinder->endpoint1.x && point->x <= cylinder->endpoint2.x &&
            point->y >= cylinder->endpoint1.y && point->y <= cylinder->endpoint2.y &&
            point->z >= cylinder->endpoint1.z && point->z <= cylinder->endpoint2.z);
}

double  calculate_discriminant_cylinder(t_intersect *intersect,
    t_token *cylinder, t_ray *ray)
{
    double  d;
    t_tuple distance_to_axis;
    t_tuple axis_point;
    t_tuple cylinder_direction;
    double  r;

    // Calcular o vetor direção do cilindro
    cylinder_direction = subtract_tuples(&cylinder->endpoint2, &cylinder->endpoint1);
    normalize_tuple(&cylinder_direction);

    // Calcular a distância entre a origem do raio e o eixo do cilindro
    axis_point = cylinder->endpoint1;
    distance_to_axis = subtract_tuples(&ray->origin, &axis_point);

    // Calcular os coeficientes do discriminante
    intersect->a = dot_product(&ray->direction, &ray->direction) - pow(dot_product(&ray->direction, &cylinder_direction), 2);
    intersect->b = 2 * (dot_product(&ray->direction, &distance_to_axis) - dot_product(&ray->direction, &cylinder_direction) * dot_product(&distance_to_axis, &cylinder_direction));
    r = cylinder->diameter / 2.0; // Raio do cilindro
    intersect->c = dot_product(&distance_to_axis, &distance_to_axis) - pow(dot_product(&distance_to_axis, &cylinder_direction), 2) - r * r;

    d = (intersect->b * intersect->b) - (4 * intersect->a * intersect->c);
    return d;
}

double  calculate_distance_cylinder(t_token *cylinder, t_ray *ray)
{
    t_intersect intersect;
    double      discriminant;
    // double      distance;

    intersect = (t_intersect){0};
    discriminant = calculate_discriminant_cylinder(&intersect, cylinder, ray);
    if (discriminant < 0) {
        return -1; // Raio não intercepta o cilindro
    }

    double t1 = (-intersect.b - sqrt(discriminant)) / (2 * intersect.a);
    double t2 = (-intersect.b + sqrt(discriminant)) / (2 * intersect.a);

    // Verificar se as interseções estão dentro do cilindro
    t_tuple hit_point1 = ray_position(ray, t1);
    t_tuple hit_point2 = ray_position(ray, t2);

    // Aqui supomos que o cilindro seja infinito. Você pode adicionar mais verificações
    // se o cilindro for limitado.
    if (is_inside_cylinder(cylinder, &hit_point1) || is_inside_cylinder(cylinder, &hit_point2)) {
        // Encontrou uma interseção dentro do cilindro
        return (t1 < t2) ? t1 : t2; // Retornar a distância do ponto de interseção mais próximo
    }

    return -1; // Raio não intercepta o cilindro
}

t_hit   *intersect_cylinder(t_token *cylinder, t_ray *ray)
{
    double      distance;
    t_tuple     hit_point;
    t_tuple     normal;
    t_hit       *hit;

    distance = calculate_distance_cylinder(cylinder, ray);
    if (distance < 0) {
        return NULL; // Raio não intercepta o cilindro
    }

    hit_point = ray_position(ray, distance);
    normal = cylinder->normalized_3d_direction; //calculate_normal_cylinder(cylinder, &hit_point);
    hit = init_hit(cylinder, &normal, distance, &hit_point);
    return hit;
}

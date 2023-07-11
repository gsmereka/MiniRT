/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:42 by gde-mora          #+#    #+#             */
/*   Updated: 2023/07/11 21:50:27 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/miniRT.h"

#					 include <signal.h> //Enqunto fazemos os testes
t_data	*g_aux_data; //Enqunto fazemos os testes

static void	test_handler(int signal); //Enqunto fazemos os testes

void	signals_handling(t_data *data) //Enqunto fazemos os testes
{
	struct sigaction	test;

	g_aux_data = data;
	ft_bzero(&test, sizeof(struct sigaction));
	test.sa_handler = test_handler;
	sigaction(SIGTERM, &test, NULL);
}

static void	test_handler(int signal) //Enqunto fazemos os testes
{
	(void)signal;
	g_aux_data->debug_exit = 1;
}


typedef struct s_projectil
{
	struct s_tuple	position; //ponto
	struct s_tuple	velocity; //vetor
}	t_projectil;

typedef struct s_ambient
{
	struct s_tuple	gravity; //vetor
	struct s_tuple	wind; //vetor
}	t_ambient;

void	pass_tuple_values(t_tuple *dest, t_tuple *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
	dest->w = src->w;
}

void	tick(t_projectil *projectil, t_ambient *ambient)
{
	t_tuple	*position;
	t_tuple *aux;
	t_tuple	*velocity;
	
	position = sum_tuples(&projectil->position, &projectil->velocity);
	aux = sum_tuples(&projectil->velocity, &ambient->gravity);
	velocity = sum_tuples(aux, &ambient->wind);
	free(aux);
	pass_tuple_values(&projectil->position, position);
	pass_tuple_values(&projectil->velocity, velocity);
	free(position);
	free(velocity);
}

#include <stdio.h>

void	create_tuplas(t_data *data)
{
	t_projectil	projectil;
	t_ambient	ambient;
	t_tuple		*velocity;

	projectil.position = (t_tuple){0, 1, 0, 1};  //ponto é 1    -- w é pra verificar se a gente n somou um ponto sem querer?
	projectil.velocity = (t_tuple){1, 1.8, 0, 0}; //vetor é 0
	normalize_tuple(&projectil.velocity);
	velocity = multiply_tuple(&projectil.velocity, 8.0);
	pass_tuple_values(&projectil.velocity, velocity);
	free(velocity);
	ambient.gravity = (t_tuple){0, -0.1, 0, 0}; //vetor é 0
	ambient.wind = (t_tuple){-0.01, 0, 0, 0}; //vetor é 0
	
	printf("Projectil position before tick: %lf %lf %lf %lf\n", projectil.position.x, projectil.position.y, projectil.position.z, projectil.position.w);
	while (projectil.position.y >= 0)
	{
		tick(&projectil, &ambient);
		paint_pixel(projectil.position.x, projectil.position.y, RED + GREEN, data);
		printf("Projectil position after tick: %lf %lf %lf %lf\n", projectil.position.x, projectil.position.y, projectil.position.z, projectil.position.w);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(data)); //
	ft_printf("Iniciando\n"); //
	signals_handling(&data); // //Enqunto fazemos os testes
	validate_scene_file(argc, argv, &data); //
	read_scene_file(argv[1], &data); //
	get_scene_info(data.tokens, &data);
	render(&data);
	return (0);
}

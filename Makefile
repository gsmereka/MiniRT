# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:26:17 by gde-mora          #+#    #+#              #
#    Updated: 2023/12/04 20:58:13 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	miniRT

# comando pra encontrar arquivos .c
#  find . -type f -name "*.c"

SRC 	=	./src/matrix_tools/transposing_matrix.c \
			./src/matrix_tools/get_determinant.c \
			./src/matrix_tools/matrices_have_diff.c \
			./src/matrix_tools/multiply_matrices.c \
			./src/matrix_tools/copy_matrix.c \
			./src/matrix_tools/get_submatrix.c \
			./src/matrix_tools/init_idmatrices.c \
			./src/matrix_tools/create_matrix.c \
			./src/matrix_tools/get_cofactor.c \
			./src/matrix_tools/inverting_matrix.c \
			./src/matrix_tools/str_to_matrix.c \
			./src/matrix_tools/multiply_matrix_with_tuple.c \
			./src/tools/dtoi.c \
			./src/tools/atod.c \
			./src/tools/are_floats_equal.c \
			./src/tools/free_array.c \
			./src/exit.c \
			./src/main.c \
			./src/define_scene/define_scene.c \
			./src/define_scene/init_camera.c \
			./src/render/colors_operations.c \
			./src/render/colors_operations_2.c \
			./src/render/paint_pixel.c \
			./src/render/render_scene.c \
			./src/ray_tools/calculate_ray_direction.c \
			./src/ray_tools/normalize_ray.c \
			./src/ray_tools/closest_hit.c \
			./src/ray_tools/light_at.c \
			./src/ray_tools/init_hit.c \
			./src/ray_tools/trace_ray.c \
			./src/ray_tools/ray_position.c \
			./src/ray_tools/intersect_sphere.c \
			./src/ray_tools/intersect_cylinder.c \
			./src/ray_tools/intersect_plane.c \
			./src/render/minilibx_handlers.c \
			./src/render/render.c \
			./src/tuple_tools/tuples_operations.c \
			./src/tuple_tools/tuple_magnitude.c \
			./src/tuple_tools/dot_product.c \
			./src/tuple_tools/cross_product.c \
			./src/tuple_tools/are_tuples_equal.c \
			./src/tuple_tools/normalize_tuple.c \
			./src/tuple_tools/create_tuple.c \
			./src/tuple_tools/pass_tuple_values.c \
			./src/matrix_transformations/shearing.c \
			./src/matrix_transformations/rotation.c \
			./src/matrix_transformations/translation.c \
			./src/matrix_transformations/scaling.c \
			./src/parsing/validate_scene_file.c \
			./src/parsing/get_scene_info.c \
			./src/parsing/check_shapes.c \
			./src/parsing/check_configs.c \
			./src/parsing/add_config.c \
			./src/parsing/add_shape.c \
			./src/parsing/check_utils.c \
			./src/parsing/read_scene_file.c \
			./src/parsing/token_utils.c \

OBJ 	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR	=	./obj

# MAKEFILE UTILS 
LIBFT_A =	./libft/libft.a

HEADERS =	./headers/miniRT.h

CCFLAGS =	-Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11 -lm

RM		=	rm -f

# RULES
all: $(NAME) ascii_draw

ascii_draw:
	@echo "\033[1;33m"
	@echo "                    _______________________________________________"
	@echo "                   /   __          o                               \\"
	@echo "                  /   (__)     .            _       o      .       (\\"
	@echo "                 |         .         o     (_)   o     ____    ()    |"
	@echo "                 |)     .     .   .                   /    \         |"
	@echo "                 |                     o       .    . |    |         |"
	@echo "                 |   o   ()     .        .    .       \____/    . o  |"
	@echo "                 |                              ()                   |"
	@echo "           ?     |    .    o        ()    .         .       o       (|"
	@echo "                 |     _   .   ()        _               .     ()  . |"
	@echo "          o_o    |    (_)          .    (_)  .  .    ()              |"
	@echo "          (\")    |)                                         __       |"
	@echo "         \/'\/    \    ()   .   o    .    ()     .     o   (__)     /"
	@echo "  ___(___(,_,)_____\_______________________________________________/________"
	@echo "\033[0m"

ascii_draw_fclean:
	@echo "\033[1;33m"
	@echo "                    _______________________________________________"
	@echo "                   /   __          o                               \\"
	@echo "                  /   (__)     .            _       o      .       (\\"
	@echo "                 |         .         o     (_)   o     ____    ()    |"
	@echo "                 |)     .     .   .                   /    \         |"
	@echo "                 |                     o       .    . |    |         |"
	@echo "                 |   o   ()     .        .    .       \____/    . o  |"
	@echo "                 |                              ()                   |"
	@echo "                 |    .    o        ()    .         .       o       (|"
	@echo "                 |     _   .   ()         _              .     ()  . |"
	@echo "                  \_  (_)                (_)  .  .    ()             |"
	@echo "               o__o )_                                        __     |"
	@echo "               ('o') _)   ()   .   o        ()     .     o   (__)   /"
	@echo "  _________(__(,_,)_)______________________________________________/________"
	@echo "\033[0m"

$(OBJ_DIR)/%.o: %.c
	make create_obj_dir
	cc $(CCFLAGS) -c $< -o $@

# LIBFT COMPILE
$(LIBFT_A):
	make -C libft

# MANDATORY COMPILE
$(NAME): $(OBJ) $(HEADERS) $(LIBFT_A)
	cc $(CCFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_A) 

# RULES CLEAN FCLEAN AND RE
clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)
	make clean -C libft

fclean: clean
	rm -f vgcore.*
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)
	make ascii_draw_fclean


re: fclean all

# CREATE OBJECTS DIR
create_obj_dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/src/define_scene
	@mkdir -p $(OBJ_DIR)/src/parsing
	@mkdir -p $(OBJ_DIR)/src/render
	@mkdir -p $(OBJ_DIR)/src/ray_tools
	@mkdir -p $(OBJ_DIR)/src/tools
	@mkdir -p $(OBJ_DIR)/src/tuple_tools
	@mkdir -p $(OBJ_DIR)/src/matrix_tools
	@mkdir -p $(OBJ_DIR)/src/matrix_transformations

## FULL CLEAN ALL OBJECTS
git: fclean
	git add . && clear && git status

RT_FILE = ./debug.rt

run: $(NAME)
	clear && ./miniRT $(RT_FILE)

valgrind: $(NAME)
	clear && valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes ./miniRT $(RT_FILE)

.PHONY: all clean fclean re create_obj_dir git ascii_draw ascii_draw_fclean valgrind test run

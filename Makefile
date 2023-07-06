# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:26:17 by gde-mora          #+#    #+#              #
#    Updated: 2023/07/06 00:01:18 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	miniRT

RT_FILE =	rato.rt

SRC 	=	src/main.c \
			src/init_data.c \
			src/exit.c \
			src/render.c \
			src/atod.c \
			src/free_shapes.c \
			src/free_configs.c \
			src/parsing/validate_scene_file.c \
			src/parsing/read_scene_file.c \
			src/parsing/gnl_token_utils.c \
			src/parsing/get_scene_info.c \
			src/parsing/check_configs.c \
			src/parsing/check_shapes.c \
			src/parsing/check_utils.c \
			src/parsing/add_config.c \
			src/parsing/add_shape.c 

OBJ 	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR	=	./obj

# MAKEFILE UTILS 
LIBFT_A =	./libft/libft.a

HEADERS =	./headers/miniRT.h

CCFLAGS =	-Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11

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

fclean: clean ascii_draw_fclean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)

# 	Limpa o tester.
	cd test && ./test.sh clean


re: fclean all

# CREATE OBJECTS DIR
create_obj_dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/src/parsing

## FULL CLEAN ALL OBJECTS
git: fclean
	git add . && clear && git status

rt: $(NAME)
	./miniRT $(RT_FILE)

valgrind: $(NAME)
	valgrind  --leak-check=full --show-leak-kinds=all ./miniRT $(RT_FILE)

# Executa o tester.
test: $(NAME)
	clear && cd test && ./test.sh

.PHONY: all clean fclean re create_obj_dir git ascii_draw valgrind rt test

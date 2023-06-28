# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:26:17 by gde-mora          #+#    #+#              #
#    Updated: 2023/06/28 16:08:01 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	miniRT

RT_FILE =	rato.rt

SRC 	=	src/main.c \
			src/validate.c \
			src/init_mlx.c \
			src/error_msg.c \
			src/exit_error.c \

OBJ 	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR	=	./obj

# MAKEFILE UTILS 
LIBFT_A =	./libft/libft.a

HEADERS =	./headers/miniRT.h

CCFLAGS =	-Wall -Wextra -Werror

RM		=	rm -f

# RULES
all: $(NAME) ascii_draw

ascii_draw:
	@echo "\033[1;35m"
	@echo "░░┌──┐░░░░░░░░░░┌──┐░░░░░░┌──┐░░░░░░░░░░┌──┐░░░░░░┌──┐░░░░░░░░░░┌──┐░░"
	@echo "░╔╡▐▐╞╝░░┌──┐░░╔╡▐▐╞╝░░░░╔╡▐▐╞╝░░┌──┐░░╔╡▐▐╞╝░░░░╔╡▐▐╞╝░░┌──┐░░╔╡▐▐╞╝░"
	@echo "░░└╥╥┘░░╚╡▌▌╞╗░░└╥╥┘░░░░░░└╥╥┘░░╚╡▌▌╞╗░░└╥╥┘░░░░░░└╥╥┘░░╚╡▌▌╞╗░░└╥╥┘░░"
	@echo "░░░╚╚░░░░└╥╥┘░░░░╚╚░░░░░░░░╚╚░░░░└╥╥┘░░░░╚╚░░░░░░░░╚╚░░░░└╥╥┘░░░░╚╚░░░"
	@echo "░░░░░░░░░░╝╝░░░░░░░░░░░░░░░░░░░░░░╝╝░░░░░░░░░░░░░░░░░░░░░░╝╝░░░░░░░░░░"
	@echo "\033[0m"

$(OBJ_DIR)/%.o: %.c
	make create_obj_dir
	cc $(CCFLAGS) -c $< -o $@

# LIBFT COMPILE
$(LIBFT_A):
	make -C libft

# MANDATORY COMPILE
$(NAME): $(OBJ) $(HEADERS) $(LIBFT_A)
	cc $(CCFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) 

# RULES CLEAN FCLEAN AND RE
clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)

re: fclean all

# CREATE OBJECTS DIR
create_obj_dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src

## FULL CLEAN ALL OBJECTS
git: fclean
	git add . && clear && git status

rt: $(NAME)
	./miniRT $(RT_FILE)

valgrind: $(NAME)
	valgrind  --leak-check=full --show-leak-kinds=all ./miniRT $(RT_FILE)

.PHONY: all clean fclean re create_obj_dir git ascii_draw valgrind rt

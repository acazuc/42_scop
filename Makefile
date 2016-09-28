# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/09/28 17:16:33 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast -g

INCLUDES_PATH = include/ -I glfw/include

SRCS_PATH = src/

SRCS_NAME = main.c \
			window_init.c \
			error_quit.c \
			obj_load.c \
			read_next_line.c \
			obj_read.c \
			obj_read_face.c \
			obj_read_vertex.c \
			obj_read_smooth.c \
			obj_read_usemtl.c \
			obj_read_mtllib.c \
			obj_read_mtllib_read.c \
			obj_read_mtllib_read_ka.c \
			obj_read_mtllib_read_kd.c \
			obj_read_mtllib_read_ks.c \
			obj_read_mtllib_read_ni.c \
			obj_read_mtllib_read_ns.c \
			obj_read_mtllib_read_tr.c \
			obj_read_mtllib_read_d.c \
			obj_read_mtllib_read_illum.c \
			obj_read_mtllib_read_newmtl.c \
			parse_valid_number.c \
			free_array.c \
			read_file.c \
			shader_create.c \
			matrix_create_identity.c \
			matrix_create_translation.c \
			matrix_create_scale.c \
			matrix_create_rotate.c \
			matrix_create_projection.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft -L glfw/src -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir

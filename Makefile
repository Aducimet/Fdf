# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 16:45:37 by aducimet     #+#   ##    ##    #+#        #
#    Updated: 2019/01/28 15:34:29 by aducimet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = FDF

SRCS = 	srcs/main.c \
		srcs/struct_utils.c \
		srcs/struct_utils2.c \
		srcs/wnds.c \
		srcs/wnds_utils.c \
		srcs/events_keys.c \
		srcs/events_keys2.c \
		srcs/events_mouse.c \
		srcs/parsing.c \
		srcs/define_fdf.c \

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

CC = gcc $(FLAG)

RM = /bin/rm -f

OPENGL = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJ) 
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) -o $(NAME)  $(SRCS) minilibx_macos/libmlx.a libft/libft.a $(OPENGL)
	@echo "Make executable $(NAME):\033[0;32m DONE !\033[0m"

%.o: %.c
	@$(CC) -o $@ -c $< -I./

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@$(RM) $(OBJ) 

fclean: clean
	@make fclean -C libft/
	@make fclean -C minilibx_macos/
	@$(RM) $(NAME)
	@echo "Executable $(NAME) clean :\033[0;32m DONE !\033[0m"

re:	fclean all
	@make re -C minilibx_macos/

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 16:45:37 by aducimet     #+#   ##    ##    #+#        #
#    Updated: 2018/12/21 16:06:50 by aducimet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = FDF

SRCS = 	srcs/main.c \
		srcs/struct_utils.c \
		srcs/wnds.c \

FLAG = -Wall -Wextra -Werror

CC = gcc $(FLAG)

RM = /bin/rm -f

OPENGL = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) -o $(NAME) $(SRCS) minilibx_macos/libmlx.a libft/libft.a $(OPENGL)
	@echo "Make executable $(NAME):\033[0;32m DONE !\033[0m"

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@$(RM) *.o 

fclean: clean
	@make fclean -C libft/
	@make fclean -C minilibx_macos/
	@$(RM) $(NAME)
	@echo "Executable $(NAME) clean :\033[0;32m DONE !\033[0m"

re:	fclean all
	@make re -C minilibx_macos/

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/11 16:32:18 by tclaudel     #+#   ##    ##    #+#        #
#    Updated: 2019/11/07 13:44:10 by tclaudel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS_NAME	=	ft_d_converter.c ft_p_converter.c ft_s_converter.c ft_upx_converter.c ft_c_converter.c ft_i_converter.c \
				ft_u_converter.c ft_x_converter.c ft_pourcent_converter.c ft_printf.c ft_is_flag.c ft_is_option.c ft_is_pourcent.c\
				ft_analyser.c ft_set_flags.c ft_set_width.c ft_apply_flags.c ft_apply_convert.c ft_router.c

SRC_PATH = ./

SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

HEADER	=	./libftprintf.h

OBJ_NAME	=	${SRCS_NAME:.c=.o}

OBJ = $(OBJ_NAME)

NAME	= libftprintf.a

CC		= cc

RM		= rm -rf

FLAG	= -Wall -Werror -Wextra -g3 #-fsanitize=address

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C Libft/
	ar rcs $(NAME) $(OBJ)
	@echo "$'[32m\nCompiling effected successfully!"

%.o: $(SRC_PATH)%.c $(HEADER)
	@echo "$'[31mCompiling :$'[0m $<$'[0m"
	@gcc $(FLAG) -I ./includes  -c $< -o $@

clean:
	@make -C libft/ clean
	${RM} ${OBJ}

fclean: clean
	@make -C libft/ fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus


# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/11 16:32:18 by tclaudel     #+#   ##    ##    #+#        #
#    Updated: 2019/11/09 17:37:23 by coscialp    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


SRCS_NAME	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
				ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c ft_strnlen.c ft_strndup.c ft_itoa_u_base.c \
				ft_itoa_ll_base.c ft_itoa_base.c ft_char_in_string.c\
				ft_strfjoin.c ft_strdel.c ft_putchar.c ft_putstr.c

SRC_PATH = ./

SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

HEADER	=	./libft.h

OBJ_NAME	=	${SRCS_NAME:.c=.o}

OBJ = $(OBJ_NAME)

NAME	= libft.a

CC		= cc

RM		= rm -rf

FLAG	= -Wall -Werror -Wextra -g3 #-fsanitize=address

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ)
	@echo "$'[32m\nCompiling effected successfully!"

%.o: $(SRC_PATH)%.c $(HEADER)
	@echo "$'[31mCompiling :$'[0m $<$'[0m"
	@gcc $(FLAG) -g3 -I ./includes  -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:38:27 by abelarif          #+#    #+#              #
#    Updated: 2021/06/22 12:55:35 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex

PIPEX_SRCS=		main.c\
				pipex.c\

PARSING_SRCS=	./parsing/args_checker.c\
				./parsing/cmd_checker.c\
				./parsing/file_checker.c\

EXECUTION_SRCS=	./execution/to_execution.c\

UTILS_SRCS=		./utils/ft_error.c\

LIBFT_SRCS=		./libft/ft_strncmp.c\
				./libft/ft_split.c\
				./libft/ft_strjoin.c\
				./libft/ft_strdup.c\
				./libft/ft_putstr_fd.c\
				./libft/ft_putchar_fd.c\
				./libft/ft_strlen.c\

SRCS=			$(PARSING_SRCS)\
				$(EXECUTION_SRCS)\
				$(UTILS_SRCS)\
				$(LIBFT_SRCS)\
				$(PIPEX_SRCS)\

OBJS=			$(SRCS:.c=.o)

FLAGS=			-Wall -Werror -Wextra

$(NAME): $(OBJS)
		clang-9 $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

fsanitize: fclean $(OBJS)
		clang-9 $(FLAGS) -g3 -fsanitize=address $(OBJS) -o $(NAME)

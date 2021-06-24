# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:38:27 by abelarif          #+#    #+#              #
#    Updated: 2021/06/24 12:23:08 by abelarif         ###   ########.fr        #
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
				./utils/ft_strncmp.c\
				./utils/ft_split.c\
				./utils/ft_strjoin.c\
				./utils/ft_strdup.c\
				./utils/ft_putstr_fd.c\
				./utils/ft_putchar_fd.c\
				./utils/ft_strlen.c\
				./utils/free_data.c\

SRCS=			$(PARSING_SRCS)\
				$(EXECUTION_SRCS)\
				$(UTILS_SRCS)\
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

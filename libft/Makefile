# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 15:53:49 by msanjuan          #+#    #+#              #
#    Updated: 2022/02/08 20:19:05 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c	\
	   ft_isalnum.c		\
	   ft_isalpha.c		\
	   ft_isascii.c		\
	   ft_isdigit.c		\
	   ft_isprint.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_strncmp.c		\
	   ft_strchr.c		\
	   ft_strrchr.c		\
	   ft_atoi.c		\
	   ft_strlcpy.c		\
	   ft_strnstr.c		\
	   ft_strlcat.c		\
	   ft_strdup.c		\
	   ft_memset.c		\
	   ft_bzero.c		\
	   ft_calloc.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_memcpy.c		\
	   ft_memccpy.c		\
	   ft_memmove.c 	\
	   ft_substr.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_strmapi.c		\
	   ft_itoa.c 		\
	   ft_putchar_fd.c 	\
	   ft_putstr_fd.c 	\
	   ft_putendl_fd.c 	\
	   ft_putnbr_fd.c	\
	   ft_split.c 		\
	   ft_strncat.c 	\
	   ft_strcmp.c 		\
	   ft_lstnew.c		\
	   ft_lstadd_front.c\
	   ft_lstsize.c		\
	   ft_lstadd_back.c	\
	   ft_lstlast.c		\
	   ft_lstdelone.c	\
	   ft_lstclear.c	\
	   ft_lstiter.c		\

OBJS = ${SRCS:.c=.o}

BOBJS = ${BONUS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CREATE = ar rcs

RM = rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}				

${NAME}: ${OBJS}
		@echo "Creating the libft wih the .o files..."
		${CREATE} ${NAME} ${OBJS}
		
bonus:	${OBJS} ${BOBJS}
		@echo "Creating the libft wih the .o bonus files..."
		${CREATE} ${NAME} ${OBJS} ${BOBJS}
		@touch bonus

all:	${NAME}

clean:
		${RM} ${OBJS} ${BOBJS} ${NAME} bonus

fclean: clean
		${RM} ${OBJS} ${BOBJS} ${NAME} bonus

re: 	fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 17:27:18 by gmastroc          #+#    #+#              #
#    Updated: 2024/05/26 17:09:12 by gmastroc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES #
NAME	=	libft.a
CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror
LIBCMP	=	ar -rcs
INC		=	-I./includes
RM		=	rm -f
MNDT	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c  ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_tolower.c ft_toupper.c \
			ft_strjoin.c ft_substr.c  get_next_line.c get_next_line_utils.c \
			ft_printf.c ft_putptr.c ft_putnbr_base.c
			

MNDT_OBJ	=	$(MNDT:.c=.o)

#	RULES	#
%.o: %.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(MNDT_OBJ)
		$(LIBCMP) $(NAME) $(MNDT_OBJ)

clean:
		$(RM) $(MNDT_OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
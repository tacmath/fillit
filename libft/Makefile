# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lperron <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/13 13:17:34 by lperron      #+#   ##    ##    #+#        #
#    Updated: 2018/11/02 16:15:07 by lperron     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


FILES= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strclr.c ft_strdel.c  ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsub.c ft_strtrim.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_realloc.c ft_sort_integer_table.c ft_split_whitespaces.c ft_str_is_alpha.c ft_str_is_numeric.c ft_swap.c ft_max.c ft_min.c ft_abs.c
INC= libft.h
INCDIR= .
OBJ= $(FILES:.c=.o)
NAME= libft.a
CFLAGS= -Wall -Werror -Wextra
CC= gcc

all: $(NAME)

%.o: %.c $(INC)
	$(CC) -c -o $@ $< -I $(INCDIR) $(CFLAGS)

$(NAME): $(OBJ) $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)	

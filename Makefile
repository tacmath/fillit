# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lperron <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/26 10:28:46 by lperron      #+#   ##    ##    #+#        #
#    Updated: 2018/11/02 16:19:41 by lperron     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCDIR= ./
LIBDIR= ./libft/
INCDIR= ./
LIBFILE= libft.a
INCFILES= fillit.h
FILES= utils.c main.c input.c output.c resolve.c check.c get_next_lineb.c
SRC= $(addprefix $(SRCDIR),$(FILES))
LIB= $(addprefix $(LIBDIR),$(LIBFILE))
INC= $(addprefix $(INCDIR),$(INCFILES))
OBJ= $(SRC:.c=.o)
NAME= fillit
CFLAGS= -Wall -Werror -Wextra  -I $(LIBDIR)
LDFLAGS= -Wall -Werror -Wextra -L ./libft/ -lft
CC= gcc

all: $(NAME)

%.o: %.c $(INC)
	$(CC) -c -o $@ $< -I $(INCDIR) $(CFLAGS)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ) $(INC)
	$(CC) -o $@ $(LIB) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
re: fclean $(NAME)	

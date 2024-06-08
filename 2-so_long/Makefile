NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(INCFLAGS)

INCDIR	=	./includes
INC	=	includes/so_long.h
INCFLAGS = -I/includes

SRCDIR = ./srcs
SRCS	=	srcs/check_map.c \
			srcs/check_map_utils.c \
			srcs/game.c \
			srcs/main.c \
			srcs/map.c \
			srcs/object.c \
			srcs/player.c
OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBDIR)

clean:
		$(MAKE) fclean -C $(LIBDIR)
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re bonus norm debug

NAME = libft.a

CC = cc
INCDIR = ../includes ./ft_printf
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

LIBDIR	=	. ./ft_printf

SRCS = $(shell find $(LIBDIR) -name "*.c" -type f | xargs)

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
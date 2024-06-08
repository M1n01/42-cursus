NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

INCDIR	=	../include
INC		=	$(INCDIR)/libft.h

SRCDIR	=	.
SRCS	=	$(SRCDIR)/ft_atoi.c \
			$(SRCDIR)/ft_isdigit.c \
			$(SRCDIR)/ft_memcpy.c \
			$(SRCDIR)/ft_printf.c \
			$(SRCDIR)/ft_putchar.c \
			$(SRCDIR)/ft_putnbr.c \
			$(SRCDIR)/ft_realloc.c \
			$(SRCDIR)/ft_strchr.c \
			$(SRCDIR)/ft_strcmp.c \
			$(SRCDIR)/ft_strjoin.c \
			$(SRCDIR)/ft_strlcpy.c \
			$(SRCDIR)/ft_strlen.c \
			$(SRCDIR)/ft_free.c \
			$(SRCDIR)/ft_error.c \
			$(SRCDIR)/get_next_line.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
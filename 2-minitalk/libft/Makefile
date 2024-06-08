NAME = libft.a

CC = cc
INCDIR = -I./ft_printf  -I./
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

SRCDIR = ./ft_printf

LIBDIR	=	./
SRCS	=	$(LIBDIR)/ft_atoi.c \
			$(LIBDIR)/ft_bzero.c \
			$(LIBDIR)/ft_calloc.c \
			$(LIBDIR)/ft_error.c \
			$(LIBDIR)/ft_free.c \
			$(LIBDIR)/ft_isalnum.c \
			$(LIBDIR)/ft_isalpha.c \
			$(LIBDIR)/ft_isascii.c \
			$(LIBDIR)/ft_isdigit.c \
			$(LIBDIR)/ft_isprint.c \
			$(LIBDIR)/ft_itoa.c \
			$(LIBDIR)/ft_memchr.c \
			$(LIBDIR)/ft_memcmp.c \
			$(LIBDIR)/ft_memcpy.c \
			$(LIBDIR)/ft_memmove.c \
			$(LIBDIR)/ft_memset.c \
			$(LIBDIR)/ft_putchar.c \
			$(LIBDIR)/ft_putendl.c \
			$(LIBDIR)/ft_putnbr.c \
			$(LIBDIR)/ft_putstr.c \
			$(LIBDIR)/ft_realloc.c \
			$(LIBDIR)/ft_strchr.c \
			$(LIBDIR)/ft_strcmp.c \
			$(LIBDIR)/ft_strdup.c \
			$(LIBDIR)/ft_striteri.c \
			$(LIBDIR)/ft_strjoin.c \
			$(LIBDIR)/ft_strlcat.c \
			$(LIBDIR)/ft_strlcpy.c \
			$(LIBDIR)/ft_strlen.c \
			$(LIBDIR)/ft_strncmp.c \
			$(LIBDIR)/ft_strnlen.c \
			$(LIBDIR)/ft_strnstr.c \
			$(LIBDIR)/ft_strrchr.c \
			$(LIBDIR)/ft_strtrim.c \
			$(LIBDIR)/ft_substr.c \
			$(LIBDIR)/ft_tolower.c \
			$(LIBDIR)/ft_toupper.c \
			$(LIBDIR)/get_next_line.c \
			$(SRCDIR)/ft_printf.c \
			$(SRCDIR)/process_ascii.c \
			$(SRCDIR)/process_ptr.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
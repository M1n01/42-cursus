NAME = libft.a

CC = cc
INCDIR = -I include
CFLAGS = -Wall -Wextra -Werror $(INCDIR)
LFLAGS = 

MANDATORY = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS = $(MANDATORY)
B_SRCS = $(BONUS)

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS += $(B_OBJS)
endif


$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus:
		@make all WITH_BONUS=1

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm:
		@norminette -R CheckForbiddenSourceHeader $(SRCS)
		@norminette -R CheckForbiddenSourceHeader $(B_SRCS)
		@norminette -R CheckDefine *.h

.PHONY: all clean fclean re bonus norm

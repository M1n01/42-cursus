NAME = libft.a

CC = cc
INCDIR = -I include
CFLAGS = -Wall -Wextra -Werror $(INCDIR)
LFLAGS = 

MANDATORY = $(shell find . -name '*.c')

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

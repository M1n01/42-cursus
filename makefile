NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread $(addprefix -I,$(INCDIR))
CFLAGS += -g -fsanitize=thread

INCDIR = ./includes
INC = $(shell find $(INCDIR) -name "*.h" -type f | xargs)

SRCDIR = ./srcs
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re bonus norm debug

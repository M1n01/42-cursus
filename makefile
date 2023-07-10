NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread $(addprefix -I,$(INCDIR))
CFLAGS += -g -fsanitize=thread

INCDIR = ./includes
INC	=	$(INCDIR)/philo.h

SRCDIR = ./srcs
SRCS	=	$(SRCDIR)/actions.c \
			$(SRCDIR)/data.c \
			$(SRCDIR)/error.c \
			$(SRCDIR)/exit.c \
			$(SRCDIR)/log.c \
			$(SRCDIR)/monitor.c \
			$(SRCDIR)/philosophers.c \
			$(SRCDIR)/thread.c \
			$(SRCDIR)/time.c \
			$(SRCDIR)/utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re bonus norm debug

NAME = libftprintf.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -MMD -MP

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj

INCS = $(shell find $(INCDIR) -name "*.h")
SRCS = $(shell find $(SRCDIR) -name '*.c')
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -g -fsanitize=address,undefined
debug: re

.PHONY: all clean fclean re debug
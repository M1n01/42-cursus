NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -I$(INCDIR) -MMD -MP


INCDIR = ./inc
SRCDIR = ./src
OBJDIR = ./obj

INCS = $(shell find $(INCDIR) -name "*.hpp")
SRCS = $(shell find $(SRCDIR) -name '*.cpp')
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) -r $(OBJDIR) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re debug
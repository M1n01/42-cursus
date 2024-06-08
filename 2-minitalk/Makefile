CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))

NAME = minitalk

SERVER = server
CLIENT = client

SRCDIR = ./src

SERVER_SRC	=	$(SRCDIR)/server.c \
				$(SRCDIR)/server_utils.c
SERVER_OBJ	=	$(SERVER_SRC:%.c=%.o)

CLIENT_SRC	=	$(SRCDIR)/client.c
CLIENT_OBJ	=	$(CLIENT_SRC:%.c=%.o)

BONUSDIR	=	./bonus

B_SERVER_SRC	=	$(BONUSDIR)/server_bonus.c \
					$(BONUSDIR)/server_utils_bonus.c
B_SERVER_OBJ	=	$(B_SERVER_SRC:%.c=%.o)

B_CLIENT_SRC	=	$(BONUSDIR)/client_bonus.c
B_CLIENT_OBJ	=	$(B_CLIENT_SRC:%.c=%.o)

INCDIR	=	./include
INC		=	$(INCDIR)/minitalk.h

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

ifdef WITH_BONUS
	SERVER_SRC = $(B_SERVER_SRC)
	CLIENT_SRC = $(B_CLIENT_SRC)
endif

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

bonus:
		$(MAKE) WITH_BONUS=1

$(SERVER): $(SERVER_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

clean:
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(B_SERVER_OBJ) $(B_CLIENT_OBJ)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug bonus
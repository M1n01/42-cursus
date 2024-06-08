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

LIBFTDIR = ../0-libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ../1-printf
PRINTF = $(PRINTFDIR)/libftprintf.a

ifdef WITH_BONUS
	SERVER_SRC = $(B_SERVER_SRC)
	CLIENT_SRC = $(B_CLIENT_SRC)
endif

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

bonus:
		$(MAKE) WITH_BONUS=1

$(SERVER): $(SERVER_OBJ) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT) $(PRINTF)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT) $(PRINTF)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

$(PRINTF):
		$(MAKE) -C $(PRINTFDIR)

clean:
		$(MAKE) fclean -C $(LIBFTDIR) $(PRINTFDIR)
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(B_SERVER_OBJ) $(B_CLIENT_OBJ)

fclean: clean
		$(RM) $(SERVER) $(CLIENT) $(LIBFT) $(PRINTF)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,undefined
debug: re

.PHONY: all clean fclean re debug bonus

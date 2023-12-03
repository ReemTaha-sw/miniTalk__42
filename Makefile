NAME	=
CLIENT	=	client
SERVER	=	server
LIBFTPRINTF	= ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SERVER_SRC = server.c  \
			 utilities.c
CLIENT_SRC = client.c \
			 utilities.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

$(CLIENT): $(CLIENT_OBJ)
	cd ft_printf && make
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(LIBFTPRINTF)
	
$(SERVER): $(SERVER_OBJ)
	cd ft_printf && make 
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) $(LIBFTPRINTF)


all: $(CLIENT) $(SERVER) $(LIBFTPRINTF)

clean:
	cd ft_printf &&  make clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean:
	cd ft_printf && make fclean
	rm -f $(SERVER) $(CLIENT) $(SERVER_OBJ) $(CLIENT_OBJ)

re: fclean all
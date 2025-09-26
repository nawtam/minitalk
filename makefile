# noms des exécutables
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

# compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# fichiers source
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
SRCS_SERVER_BONUS = server_bonus.c utils.c
SRCS_CLIENT_BONUS = client_bonus.c utils.c

# fichiers objets .c devient .o
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

# compiler tout
all: $(NAME_SERVER) $(NAME_CLIENT)

# compiler les bonus
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

# compiler le serveur
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

# compiler le client
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)
	
# compiler le serveur bonus
$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS)

# compiler le client bonus
$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS)

# nettoyer les fichiers objets
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

# supprimer aussi les exécutables
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

# tout recompiler
re: fclean all

.PHONY: all bonus clean fclean re
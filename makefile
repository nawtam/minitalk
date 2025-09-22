# noms des exécutables
NAME_SERVER = server
NAME_CLIENT = client

# compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# fichiers source
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c

# fichiers objets .c devient .o
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# compiler tout
all: $(NAME_SERVER) $(NAME_CLIENT)

# compiler le serveur
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

# compiler le client
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

# nettoyer les fichiers objets
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

# supprimer aussi les exécutables
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

# tout recompiler
re: fclean all
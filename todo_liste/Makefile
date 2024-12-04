
# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11 -g

# Nom de l'exécutable
EXEC = programme

# Fichiers sources
SRCS = main.c malib.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Fichiers en-tête
HEADERS = malib.h

# Cible par défaut
all: $(EXEC)

# Règle pour l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour compiler les fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Cible pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

# Cible pour exécuter le programme
run: $(EXEC)
	./$(EXEC)

# Indiquer que les cibles ne sont pas des fichiers
.PHONY: all clean run

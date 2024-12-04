
# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11 -g

# Noms des exécutables
EXEC = log_program
TEST_EXEC = tests

# Fichiers sources
SRCS = main.c lib_log.c tests.c
TEST_SRCS = tests.c lib_log.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Fichiers en-tête
HEADERS = lib_log.h tests.h

# Cible par défaut
all: $(EXEC) $(TEST_EXEC)

# Règle pour l'exécutable principal
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour l'exécutable des tests
$(TEST_EXEC): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour compiler les fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Cible pour nettoyer les fichiers objets et les exécutables
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(EXEC) $(TEST_EXEC)

# Cible pour nettoyer tout (y compris les fichiers temporaires)
distclean: clean

# Cible pour exécuter le programme principal
run: $(EXEC)
	./$(EXEC)

# Cible pour exécuter les tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Indique que les cibles ne sont pas des fichiers
.PHONY: all clean distclean run test

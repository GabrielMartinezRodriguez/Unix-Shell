NAME = -o dogSHell
LIB = lib/libTx.a
COMPILA = GCC
CFLAGS = -Wall -Wextra -Werror
FUNSHELL = hola.c
MAIN = main.c

.PHONY all clean fclean f re

all:
	$(COMPILA) $(CFLAGS) $(MAIN) $(LIB) $(FUNSHELL) $(NAME)
clean:
	/bin/rm -rf *.o
fclean: clean
	/bin/rm -rf dogSHell
f: fclean
re: f all
NAME = -o dogSHell
BNAME = -o ./beta/BdogSHell
LIB = lib/libTx.a
COMPILA = GCC
CFLAGS = -Wall -Wextra -Werror

BMAIN = ./beta/main.c
MAIN = main.c

.PHONY all clean fclean f re

pruebas:
	$(COMPILA) $(CFLAGS) $(BMAIN) $(LIB) $(BNAME)
all:
	$(COMPILA) $(CFLAGS) $(MAIN) $(LIB) $(NAME)
clean:
	/bin/rm -rf *.o
fclean: clean
	/bin/rm -rf dogSHell
f: fclean
re: f all
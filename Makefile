CC= gcc 
CCFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic -g3
SRC= list.c main.c read_file.c tree.c huffman.c write_file.c
EXEC= huffman 

all : $(EXEC)

$(EXEC): $(SRC)
	@$(CC) $(CCFLAGS) $^ -o $@

clean: 
	@rm -rf $(EXEC) *.dSYM

.PHONY: clean all 

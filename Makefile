CFLAGS := -Wall -g
CC := gcc
LN := gcc

OBJ = error.o graphics.o main.o

all: sc

sc: $(OBJ)
	$(LN) $(CFLAGS) -o sc $(addprefix bin/, $(OBJ)) -lsdl -lsdlmain -lopengl32

%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o bin/$@

clean:
	rm -f $(addprefix bin/, $(OBJ))
	rm -f bin/sc

gprof: CFLAGS += -pg -O3
gprof: sc

release: CFLAGS += -O3
release: sc


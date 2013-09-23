CFLAGS := -Wall -g -Ienet/include -Lenet/.libs
CC := gcc
LN := gcc

OBJ = error.o graphics.o main.o world.o sim.o net.o

all: sc

sc: $(OBJ)
	$(LN) $(CFLAGS) -o sc $(addprefix bin/, $(OBJ)) -lsdl -lsdlmain -lopengl32 -lenet -lws2_32 -lwinmm

%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o bin/$@

clean:
	rm -f $(addprefix bin/, $(OBJ))
	rm -f bin/sc

gprof: CFLAGS += -pg -O3
gprof: sc

release: CFLAGS += -O3
release: sc


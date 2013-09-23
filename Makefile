CFLAGS := -Wall -g -Ienet/include -Lenet/.libs
CC := gcc
LN := gcc

CLIENTOBJ = error.o graphics.o world.o sim.o net.o main.o
SERVEROBJ = error.o net.o server.o

all: sc

sc: $(CLIENTOBJ)
	$(LN) $(CFLAGS) -o sc $(addprefix bin/, $(CLIENTOBJ)) -lsdl -lsdlmain -lopengl32 -lenet -lws2_32 -lwinmm

%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o bin/$@

clean:
	rm -f $(addprefix bin/, $(OBJ))
	rm -f bin/sc

gprof: CFLAGS += -pg -O3
gprof: sc

release: CFLAGS += -O3
release: sc

server: $(SERVEROBJ)
	$(LN) $(CFLAGS) -o server $(addprefix bin/, $(SERVEROBJ)) -lenet -lws2_32 -lwinmm

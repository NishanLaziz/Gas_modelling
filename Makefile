CC = gcc
LFLAGS = -lSDL3

SOURCES_1 = src/Maxwell_gas.c src/lib.c

TARGET_1 = build/Maxwell_gas

.PHONY: all Maxwell clean

all: Maxwell_gas

Maxwell_gas:
	$(CC) -o $(TARGET_1) $(SOURCES_1) $(LFLAGS)

clean:
	rm -f $(TARGET_1)

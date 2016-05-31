CC = gcc
TARGET = libfoo.so
SRC = lib.c
OBJ = $(SRC:.c=.o)
LIBS =
LFLAGS = 
CFLAGS = -Werror -std=gnu99

all: $(OBJ)
	$(CC) -shared -o $(TARGET) $(OBJ) $(CFLAGS) $(LFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(LIBS) -fpic $(OS)

debug: CFLAGS += -Wall -Werror
debug: CFLAGS += -g -DDEBUG
debug: all

strip: all
	strip -s $(TARGET)

clean:
	@echo Removing old files...
	rm -rf $(TARGET) *.o

CC = gcc
TARGET = main
SRC = main.c
OBJ = $(SRC:.c=.o)
LIBS = 
LIBSPATH = 
CFLAGS = -W -std=gnu99

all: $(OBJ)
	$(CC) $(LIBSPATH) -o $(TARGET) $(OBJ) $(CFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(LIBSPATH) -c $< $(CFLAGS) $(LIBS) $(OS)

debug: CFLAGS += -Wall -Werror
debug: CFLAGS += -g -DDEBUG
debug: all

strip: all
	strip -s $(TARGET)

clean:
	@echo Removing old files...
	rm -rf $(TARGET) *.o

CC = gcc
CFLAG = -std=c11 -O2 -Wall
TARGET = assignment2
SRCS = assignment2.c
OBJS = assignment2.o
SRC_FILE = source.txt
DST_FILE = result.txt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(DST_FILE)

run:
	./assignment2 $(SRC_FILE) $(DST_FILE)
	diff $(SRC_FILE) $(DST_FILE)

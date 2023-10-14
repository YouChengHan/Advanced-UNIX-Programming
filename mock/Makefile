CC = gcc
CFLAG = -std=c11 -O2 -Wall
TARGET = uniq
SRCS = uniq.c
OBJS = uniq.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

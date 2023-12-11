CC = gcc
CFLAG = -std=c11 -O2 -Wall
TARGET = assignment11
SRCS = assignment11.c daemonize.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(TARGET).txt

run:
	./$(TARGET)

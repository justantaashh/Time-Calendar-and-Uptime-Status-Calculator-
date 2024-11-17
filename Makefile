CC = gcc
CFLAGS = -Wall

all: date cal uptime main

date: date.c
	$(CC) $(CFLAGS) -o date date.c

cal: cal.c
	$(CC) $(CFLAGS) -o cal cal.c

uptime: uptime.c
	$(CC) $(CFLAGS) -o uptime uptime.c

main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f date cal uptime main

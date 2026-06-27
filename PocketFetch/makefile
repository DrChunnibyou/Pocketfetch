CC = gcc
CFLAGS = -Wall -Iinclude

out: fetch.c modules/ram_usage.c modules/hostandterm.c modules/OSfind.c modules/kernelfind.c
	$(CC) $(CFLAGS) -o pocketfetch fetch.c modules/ram_usage.c modules/hostandterm.c modules/OSfind.c modules/kernelfind.c

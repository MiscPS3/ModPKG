CC=gcc
CFLAGS=-Wall -fno-strict-aliasing -std=c99
LDFLAGS=-static -lz
SOURCES=tools.c aes.c sha1.c paged_file.c pkg.c pkgtool.c
OUTPUT=pkgtool

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(OUTPUT)
clean:
	rm -rf $(OUTPUT)

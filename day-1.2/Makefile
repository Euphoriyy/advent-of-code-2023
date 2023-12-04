CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-O3 -s -Wall -Werror -Wpedantic
LDFLAGS=-Iinclude

SRCDIR=src
OUTDIR=out

.PHONY: run clean

all: $(OUTDIR) $(OUTDIR)/main

$(OUTDIR):
	mkdir -p $@

$(OUTDIR)/main: src/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $?

run: $(OUTDIR) $(OUTDIR)/main
	$(OUTDIR)/main

clean:
	$(RM) $(OUTDIR)/*

CC=gcc
CFLAGS=-Wall -pedantic

all: main

main: main.c opencl_target.h
	$(CC) $(CFLAGS) -I. -o main main.c -lOpenCL

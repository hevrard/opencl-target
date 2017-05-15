all: main

main: main.c opencl_target.h
	cc -I. -o main main.c -lOpenCL

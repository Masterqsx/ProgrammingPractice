make:
	gcc -Wno-deprecated-declarations -m32 -pg -o EqualMyMalloc -g *MyMalloc.c
run:
	./*MyMalloc 50000

estimate: 
	gprof *MyMalloc gmon.out -p|less
clean:
	rm -r *MyMalloc *dSYM .*

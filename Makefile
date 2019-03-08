CC=g++
CFLAGS=-c -Wall
Objects=main.o

main.out: $(Objects)
	$(CC) $(Objects) -o main.out
$(Objects) : %.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -fv *.o *.out

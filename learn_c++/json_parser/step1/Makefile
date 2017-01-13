CC = g++
CFLAGS = -Wall -Werror -std=c++11
TARGET = test
SRC = test.cpp my_json.cpp

$(TARGET) : $(SRC)
	$(CC) $(CFLAGS) -o $@ -g $^

remake:
	make clean
	make

clean:
	rm -rf test test.dSYM

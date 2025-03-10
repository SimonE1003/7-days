map_storage.o: map_storage.cpp map_head.h
	g++ -c $^
map_main.o: map_main.cpp map_head.h
	g++ -c $^

map_main: map_main.o map_storage.o
	g++ $^ -o $@ -lncurses

run: map_main
	./map_main

clean:
	rm -f *.o map_main

.PHONY: run clean
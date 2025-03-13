play_story.o: play_story.cpp map_head.h
	g++ -std=c++11 -c $^
map_storage.o: map_storage.cpp map_head.h
	g++ -std=c++11 -c $^
map_main.o: map_main.cpp map_head.h
	g++ -std=c++11 -c $^

map_main: map_main.o map_storage.o play_story.o
	g++ -std=c++11 $^ -o $@ -lncurses

run: map_main
	./map_main

clean:
	rm -f *.o map_main *.gch

.PHONY: run clean
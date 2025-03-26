game_state.o: game_state.cpp ../include/game_state.h
	g++ -std=c++11 -c $^
story_storage.o: story_storage.cpp ../include/map_head.h
	g++ -std=c++11 -c $^
play_story.o: play_story.cpp ../include/map_head.h
	g++ -std=c++11 -c $^
map_storage.o: map_storage.cpp ../include/map_head.h
	g++ -std=c++11 -c $^
map_main.o: map_main.cpp ../include/map_head.h ../include/game_state.h
	g++ -std=c++11 -c $^
exploration.o: exploration.cpp ../include/map_head.h
	g++ -std=c++11 -c $^
game_file: exploration.o map_main.o map_storage.o play_story.o story_storage.o game_state.o
	g++ -std=c++11 $^ -o $@ -lncurses

run: game_file
	./game_file

clean:
	rm -f *.o game_file *.gch

.PHONY: run clean
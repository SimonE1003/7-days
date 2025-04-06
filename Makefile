F = -std=c++11 -c -w

menu_map.o: src/menu_map.cpp include/map_head.h
	g++ $(F) $^
game_state.o: src/game_state.cpp include/game_state.h
	g++ $(F) $^
story_storage.o: src/story_storage.cpp include/map_head.h
	g++ $(F) $^
play_story.o: src/play_story.cpp include/map_head.h
	g++ $(F) $^
map_storage.o: src/map_storage.cpp include/map_head.h
	g++ $(F) $^
map_main.o: src/map_main.cpp include/map_head.h include/game_state.h
	g++ $(F) $^
exploration.o: src/exploration.cpp include/map_head.h
	g++ $(F) $^
game_start.o: src/game_start.cpp include/game_start.h
	g++ $(F) $^
save_load.o: src/save_load.cpp include/save_load.h include/game_start.h include/game_state.h
	g++ $(F) $^
init.o: src/init.cpp include/init.h
	g++ $(F) $^
main.o: main.cpp include/init.h include/exploration.h
	g++ $(F) $^
game_file: main.o exploration.o game_start.o map_main.o map_storage.o play_story.o story_storage.o game_state.o menu_map.o save_load.o init.o
	g++ -std=c++11 -w $^ -o $@ -lncurses

run: game_file
	./game_file

clean:
	rm -f *.o game_file *.gch include/*.gch

delsave:
	rm -f save/*.save

.PHONY: run clean delsave
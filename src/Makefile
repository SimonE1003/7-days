F = -std=c++11 -c -w

menu_map.o: menu_map.cpp ../include/map_head.h
	g++ $(F) $^
game_state.o: game_state.cpp ../include/game_state.h
	g++ $(F) $^
story_storage.o: story_storage.cpp ../include/map_head.h
	g++ $(F) $^
play_story.o: play_story.cpp ../include/map_head.h
	g++ $(F) $^
map_storage.o: map_storage.cpp ../include/map_head.h
	g++ $(F) $^
map_main.o: map_main.cpp ../include/map_head.h ../include/game_state.h
	g++ $(F) $^
exploration.o: exploration.cpp ../include/map_head.h
	g++ $(F) $^
game_start.o: game_start.cpp ../include/game_start.h
	g++ $(F) $^
save_load.o: save_load.cpp ../include/save_load.h ../include/game_start.h ../include/game_state.h
	g++ $(F) $^
init.o: init.cpp ../include/init.h
	g++ $(F) $^
game_file: exploration.o game_start.o map_main.o map_storage.o play_story.o story_storage.o game_state.o menu_map.o save_load.o init.o
	g++ -std=c++11 -w $^ -o $@ -lncurses

run: game_file
	./game_file

clean:
	rm -f *.o game_file *.gch ../include/*.gch

delsave:
	rm -f ../save/*.save

.PHONY: run clean delsave
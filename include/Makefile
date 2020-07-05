gcc_options = -std=c++17 -Wall

all.h.gch: all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

.PHONY: clean
clean:
	rm -f ./all.h.gch
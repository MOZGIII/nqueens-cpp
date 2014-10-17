all: build

build:
	g++ -Wall --std=gnu++11 -lm -I"." impl/main.cpp -o main

hillclimbing:
	g++ -Wall --std=gnu++11 -lm -I"." impl/main_hill_climbing.cpp -o hillclimbing

test:
	g++ -Wall --std=gnu++11 -lm -I"." impl/queens-test-main.cpp -o queens-test-main

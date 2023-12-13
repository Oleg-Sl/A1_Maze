BUILD_DIR = build
VIEW_DIR = view
MODEL_DIR = model

CXX = g++
CFLAGS = 

OS = $(shell uname -s)
MACOS = Darwin

.PHONY: all autoformat

all: install
	
autoformat:
	find . -type f -name "*.cc" -o -name "*.h" | xargs clang-format -style=Google -i

%.o: %.cc
	$(CXX) $(CFLAGS) -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

tests: $(MODEL_DIR)/filereader.o $(MODEL_DIR)/maze.o $(MODEL_DIR)/mazegenerator.o
	cd tests && g++ maze_test.cc ../filereader.o ../maze.o ../mazegenerator.o -lgtest
	tests/a.out
	

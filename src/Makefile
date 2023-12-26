PROJECT_NAME = maze
BUILD_DIR = build
DOCS_DIR = docs
TEXI2DVI = texi2dvi


FILES = $(wildcard source/adapter/*.h source/adapter/*.cc source/model/*.h source/model/*.cc source/model/cave/*.h source/model/cave/*.cc source/view/*.h source/view/*.cc source/common/*.h source/common/*.cc tests/*.h tests/*.cc source/*.cc)
OS = $(shell uname -s)
MACOS = Darwin

ifeq ($(OS), $(MACOS))
MEMORY_TEST = leaks -atExit --
else 
MEMORY_TEST = valgrind --trace-children=yes --leak-check=yes --track-origins=yes
endif


all: install

install: $(BUILD_DIR)
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) --target Maze
	$(BUILD_DIR)/source/Maze

uninstall:
	rm -rf $(BUILD_DIR)

clean:
	rm -rf $(DOCS_DIR)/*.aux $(DOCS_DIR)/*.log $(DOCS_DIR)/*.dvi $(DOCS_DIR)/*.pdf $(DOCS_DIR)/*.toc $(DOCS_DIR)/*.html
	rm -rf $(PROJECT_NAME).tar

dvi: $(DOCS_DIR)/$(PROJECT_NAME).texi
	cd $(DOCS_DIR) && $(TEXI2DVI) $(PROJECT_NAME).texi --pdf
	open $(DOCS_DIR)/$(PROJECT_NAME).pdf

dist:
	mkdir -p $(PROJECT_NAME)
	cp -r Makefile CMakeLists.txt docs source tests  $(PROJECT_NAME)
	tar -cf $(PROJECT_NAME).tar $(PROJECT_NAME)
	rm -rf $(PROJECT_NAME)

tests: $(BUILD_DIR)
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) --target MazeTests
	$(BUILD_DIR)/tests/MazeTests

install: $(BUILD_DIR)
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) --target Maze
	$(BUILD_DIR)/source/Maze

leaks: tests
	$(MEMORY_TEST) $(BUILD_DIR)/tests/MazeTests --gtest_filter=-*Throw.*

check:
	clang-format --style=Google -n --verbose $(FILES)
	cppcheck --check-config --enable=all --suppress=missingIncludeSystem $(FILES)

format:
	clang-format --style=Google -i --verbose $(FILES)


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

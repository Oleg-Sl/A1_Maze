PROJECT_NAME = maze
BUILD_DIR = build
DOCS_DIR = docs
TEXI2DVI = texi2dvi

OS = $(shell uname -s)
MACOS = Darwin

ifeq ($(OS), $(MACOS))
MEMORY_TEST = leaks -atExit --
GEN_REPORT = cd $(DOCS_DIR) && makeinfo $(PROJECT_NAME).texi --force --html
OPEN_REPORT = open $(DOCS_DIR)/$(PROJECT_NAME)/index.html
else 
MEMORY_TEST = valgrind --trace-children=yes --leak-check=yes --track-origins=yes
GEN_REPORT = cd $(DOCS_DIR) && $(TEXI2DVI) $(PROJECT_NAME).texi --pdf
OPEN_REPORT = open $(DOCS_DIR)/$(PROJECT_NAME).pdf
endif


all: install

install: build
	cmake --build $(BUILD_DIR) --target Maze
	$(BUILD_DIR)/source/Maze

uninstall:
	rm -rf $(BUILD_DIR)

build:
	cmake -B $(BUILD_DIR)

clean:
	rm -rf $(DOCS_DIR)/*.aux $(DOCS_DIR)/*.log $(DOCS_DIR)/*.dvi $(DOCS_DIR)/*.pdf $(DOCS_DIR)/*.toc $(DOCS_DIR)/*.html $(DOCS_DIR)/$(PROJECT_NAME)
	rm -rf $(PROJECT_NAME).tar

dvi: $(DOCS_DIR)/$(PROJECT_NAME).texi
	$(GEN_REPORT)
	$(OPEN_REPORT)

dist:
	mkdir -p $(PROJECT_NAME)
	cp -r Makefile CMakeLists.txt docs source tests $(PROJECT_NAME)
	tar -cf $(PROJECT_NAME).tar $(PROJECT_NAME)
	rm -rf $(PROJECT_NAME)

tests: build
	cmake --build $(BUILD_DIR) --target MazeTests
	$(BUILD_DIR)/tests/MazeTests

leaks: tests
	$(MEMORY_TEST) $(BUILD_DIR)/tests/MazeTests --gtest_filter=-*.Throw*

stylecheck: build
	cmake --build $(BUILD_DIR) --target stylecheck

cppcheck: build
	cmake --build $(BUILD_DIR) --target cppcheck

format: build
	cmake --build $(BUILD_DIR) --target format
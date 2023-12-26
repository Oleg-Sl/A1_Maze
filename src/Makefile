PROJECT_NAME = maze
BUILD_DIR = build
DOCS_DIR = docs
TEXI2DVI = texi2dvi


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

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

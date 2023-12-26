BUILD_DIR = build
DOCS_DIR = docs
TEXI2DVI = texi2dvi
# TEXI2DVI = texi2html
# TEXI2DVI = texi2pdf

all: install

install: $(BUILD_DIR)
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) --target Maze
	$(BUILD_DIR)/source/Maze

uninstall:
	rm -rf $(BUILD_DIR)

clean:
	rm  -rf $(DOCS_DIR)/*.aux $(DOCS_DIR)/*.log $(DOCS_DIR)/*.dvi $(DOCS_DIR)/*.pdf $(DOCS_DIR)/*.toc $(DOCS_DIR)/*.html

dvi: $(DOCS_DIR)/maze.texi
	cd $(DOCS_DIR) && $(TEXI2DVI) maze.texi --pdf

dist:

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
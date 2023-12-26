BUILD_DIR = build

test: $(BUILD_DIR)
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) --target MazeTests
	$(BUILD_DIR)/tests/MazeTests

install: $(BUILD_DIR)
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR) --target Maze
	$(BUILD_DIR)/source/Maze

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
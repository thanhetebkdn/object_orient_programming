CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
BIN_DIR = bin

# Automatically find all .cpp files in src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Convert source files to object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target executable
TARGET = $(BIN_DIR)/output

# Rule to create necessary directories if they don't exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Rule to link object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Rule to compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean up build artifacts (object files and executable)
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Optional rule to run the program after building
run: $(TARGET)
	./$(TARGET)

# Optional rule to recompile everything (useful when adding/removing files)
rebuild: clean $(TARGET)

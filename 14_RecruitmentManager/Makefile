CXX = g++   
CXXFLAGS = -std=c++17 -Wall -g

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build

# Automatically find all .cpp files in the source directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Convert source files to object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET = output

# Rule to create the build directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

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

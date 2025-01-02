CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
BIN_DIR = bin

# List source files and automatically convert them to object files
SRC_FILES = $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/Book.cpp \
            $(SRC_DIR)/Magazine.cpp \
            $(SRC_DIR)/Document.cpp \
            $(SRC_DIR)/DocumentManager.cpp \
            $(SRC_DIR)/Newspaper.cpp

# Convert source files to object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/output
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

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/output

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

rebuild: clean $(TARGET)

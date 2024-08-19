# Compiler
CC = g++

# Directories
BIN_DIR = bin
INCLUDE_DIR = include
OBJ_DIR = obj
SRC_DIR = src

# Source and Object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR)

# Final executable
EXECUTABLE = $(BIN_DIR)/tp3.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: clean

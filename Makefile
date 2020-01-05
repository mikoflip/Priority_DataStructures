INC_DIR  = include
OBJ_DIR  = obj
SRC_DIR  = src
TARGET   = Priority
CC       = g++
CFLAGS   = $(addprefix -I, $(INC_DIR)) -std=c++11 -g -Wall -Wextra -pedantic

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(OBJ_DIR) Priority *.dis

$(TARGET): $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $(TARGET) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

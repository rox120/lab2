SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
LIB_DIR := lib

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

STATIC_LIB := $(LIB_DIR)/libcalculator.a
SHARED_LIB := $(LIB_DIR)/libcalculator.so

CC := gcc
CFLAGS := -fPIC -I$(SRC_DIR)
LDFLAGS := -L$(LIB_DIR) -lcalculator

.PHONY: all clean directories

all: directories $(BIN_DIR)/main_static $(BIN_DIR)/main_shared $(BIN_DIR)/main_dynamic

directories:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR) $(LIB_DIR)

$(STATIC_LIB): $(OBJ_FILES)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJ_FILES)
	$(CC) -shared -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/main_static: $(BUILD_DIR)/main.o $(STATIC_LIB)
	$(CC) -o $@ $(BUILD_DIR)/main.o -L$(LIB_DIR) -lcalculator

$(BIN_DIR)/main_shared: $(BUILD_DIR)/main.o $(SHARED_LIB)
	$(CC) -o $@ $(BUILD_DIR)/main.o $(LDFLAGS)

$(BIN_DIR)/main_dynamic: $(SRC_DIR)/main.c $(SHARED_LIB)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c -o $@ -ldl

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(LIB_DIR)



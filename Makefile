# === BEGIN DECLARING VARIABLES FOR USE IN MAKEFILE
# COMPILER
CC = gcc
CFLAGS = -Wall -Werror -c 

# DIRECTORIES
RELEASE_DIR = build/release
DEBUG_DIR = build/debug
OBJECTS_DIR = $(BUILD_DIR)/objects
# set to release by default, changed in "debug" target
BUILD_DIR = $(RELEASE_DIR)

# SRC AND OBJ FILES
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(patsubst src/%.c,$(OBJECTS_DIR)/%.o,$(SRC_FILES))

# ARCHIVING
ARCHIVER = ar
ARCHIVE_FLAGS = rc

INDEXER = ranlib

LIBRARY_NAME = $(BUILD_DIR)/libaglm.a
# === END DECLARING VARIABLES FOR USE IN MAKEFILE

# === BEGIN DEFAULT BUILD
all: $(LIBRARY_NAME)
# === END DEFAULT BUILD

# === BEGIN DEBUG TARGET
debug: CFLAGS += -g
debug: BUILD_DIR = $(DEBUG_DIR)
debug: all
# === END DEBUG TARGET

# === BEGIN MAIN LIBRARY TARGET
$(LIBRARY_NAME): $(OBJ_FILES)
	$(ARCHIVER) $(ARCHIVE_FLAGS) $(LIBRARY_NAME) $(OBJ_FILES)
	$(INDEXER) $(LIBRARY_NAME)

$(OBJECTS_DIR)/%.o: src/%.c include/%.h $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

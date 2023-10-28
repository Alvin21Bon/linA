# === BEGIN DECLARING VARIABLES FOR USE IN MAKEFILE
# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 

# DIRECTORIES
RELEASE_DIR = build/release
DEBUG_DIR = build/debug
OBJECTS_DIR = objects
# set to release by default, changed in "debug" target
BUILD_DIR = $(RELEASE_DIR)

# SRC AND OBJ FILES
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(patsubst src/%.c,$(BUILD_DIR)/$(OBJECTS_DIR)/%.o,$(SRC_FILES))

# ARCHIVING
ARCHIVER = ar
ARCHIVE_FLAGS = rc

INDEXER = ranlib

LIBRARY_NAME = libaglm.a
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
$(LIBRARY_NAME): $(BUILD_DIR)/$(OBJECTS_DIR)

$(LIBRARY_NAME): $(OBJ_FILES)
	@echo $(OBJ_FILES)

$(BUILD_DIR)/$(OBJECTS_DIR)/%.o:
	@echo whatever

$(BUILD_DIR)/$(OBJECTS_DIR):
	@mkdir -p $(BUILD_DIR)/$(OBJECTS_DIR)

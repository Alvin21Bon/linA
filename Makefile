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
RELEASE_OBJ_FILES = $(patsubst src/%.c,$(RELEASE_DIR)/objects/%.o,$(SRC_FILES))
DEBUG_OBJ_FILES = $(patsubst src/%.c,$(DEBUG_DIR)/objects/%.o,$(SRC_FILES))

# ARCHIVING
ARCHIVER = ar
ARCHIVE_FLAGS = rc

INDEXER = ranlib

LIBRARY_NAME = libaglm.a
# === END DECLARING VARIABLES FOR USE IN MAKEFILE

.phony: all debug release

all: release

debug: CFLAGS += -g
debug: $(DEBUG_DIR)/$(LIBRARY_NAME) 

release: $(RELEASE_DIR)/$(LIBRARY_NAME)

$(RELEASE_DIR)/$(LIBRARY_NAME): $(RELEASE_OBJ_FILES)
	$(ARCHIVER) $(ARCHIVE_FLAGS) $@ $?
	$(INDEXER) $@

$(RELEASE_DIR)/objects/%.o: src/%.c include/%.h | $(RELEASE_DIR)/objects
	$(CC) $(CFLAGS) $< -o $@

$(RELEASE_DIR)/objects:
	@mkdir -p $(RELEASE_DIR)/objects 

#
#
#

$(DEBUG_DIR)/$(LIBRARY_NAME): $(DEBUG_OBJ_FILES)
	$(ARCHIVER) $(ARCHIVE_FLAGS) $@ $?
	$(INDEXER) $@

$(DEBUG_DIR)/objects/%.o: src/%.c include/%.h | $(DEBUG_DIR)/objects
	$(CC) $(CFLAGS) $< -o $@

$(DEBUG_DIR)/objects:
	@mkdir -p $(DEBUG_DIR)/objects

clean:
	rm -rf build

# # === BEGIN DEFAULT BUILD
# all: $(LIBRARY_NAME)
# # === END DEFAULT BUILD
#
# # === BEGIN DEBUG TARGET
# debug: CFLAGS += -g
# debug: BUILD_DIR = $(DEBUG_DIR)
# debug: all
# # === END DEBUG TARGET
#
# # === BEGIN MAIN LIBRARY TARGET
# $(LIBRARY_NAME): $(OBJ_FILES)
# 	$(ARCHIVER) $(ARCHIVE_FLAGS) $(LIBRARY_NAME) $(OBJ_FILES)
# 	$(INDEXER) $(LIBRARY_NAME)
#
# $(OBJECTS_DIR)/%.o: src/%.c include/%.h | $(OBJECTS_DIR)
# 	$(CC) $(CFLAGS) $< -o $(OBJECTS_DIR)/$(@F)
#
# $(OBJECTS_DIR):
# 	@mkdir -p $(OBJECTS_DIR)

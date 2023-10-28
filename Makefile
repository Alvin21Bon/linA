# === BEGIN DECLARING VARIABLES FOR USE IN MAKEFILE
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 

RELEASE_DIR = build/release
DEBUG_DIR = build/debug
OBJECTS_DIR = objects
# set to release by default, changed in "debug" target
BUILD_DIR = $(RELEASE_DIR)

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

$(LIBRARY_NAME): $(BUILD_DIR)/$(OBJECTS_DIR)/%.o
	@echo hi

$(BUILD_DIR)/$(OBJECTS_DIR)/%.o:
	@echo whatever

$(BUILD_DIR)/$(OBJECTS_DIR):
	@mkdir -p $(BUILD_DIR)/$(OBJECTS_DIR)

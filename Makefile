# === BEGIN DECLARING VARIABLES FOR USE IN MAKEFILE
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 

RELEASE_DIR = build/release
DEBUG_DIR = build/debug
OBJECTS_DIR = objects
BUILD_DIR = $(RELEASE_DIR) # set to release by default, changed in "debug" target

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

debug: $(DEBUG_DIR)/$(OBJECTS_DIR)
$(DEBUG_DIR)/$(OBJECTS_DIR):
	@mkdir -p $(DEBUG_DIR)/$(OBJECTS_DIR)

debug: all
# === END DEBUG TARGET



# === BEGIN DECLARING VARIABLES FOR USE IN MAKEFILE
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 

RELEASE_DIR = build/release
DEBUG_DIR = build/debug
BUILD_DIR = $(RELEASE_DIR) # set to release by default, changed in "debug" target

ARCHIVER = ar
ARCHIVE_FLAGS = rc

INDEXER = ranlib

LIBRARY_NAME = libaglm.a
# === END DECLARING VARIABLES FOR USE IN MAKEFILE

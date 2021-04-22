CC= gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I src -I thirdparty -MP -MMD
LDFLAGS =
LDLIBS =

APP_GEO = geometry
LIB_GEO = libgeometry
TEST_GEO = geometry-test

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_GEO)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_GEO)/$(LIB_GEO).a
TEST_PATH = $(BIN_DIR)/$(TEST_GEO)

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_GEO) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/$.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

all: $(APP_PATH)

test: $(TEST_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/$(SRC_DIR)/$(APP_GEO)/%.o: $(SRC_DIR)/$(APP_GEO)/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(OBJ_DIR)/$(SRC_DIR)/$(LIB_GEO)/%.o: $(SRC_DIR)/$(LIB_GEO)/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.$(SRC_EXT)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;

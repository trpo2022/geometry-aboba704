APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = test

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
CPPFLAGST = -I thirdparty -MP -MMD
MYFLAG = -lm

APP_PATH = bin/$(APP_NAME)
LIB_PATH = obj/src/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = bin/$(TEST_NAME)

APP_SOURCES = $(shell find src/$(APP_NAME) -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/%.c=obj/src/%.o)

LIB_SOURCES = $(shell find src/$(LIB_NAME) -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:src/%.c=obj/src/%.o)

TEST_SOURCES = $(shell find $(TEST_NAME) -name '*.c')
TEST_OBJECTS = $(TEST_SOURCES:test/%.c=obj/test/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $(CPPFLAGS) $^ $(MYFLAG) -o $@
	
$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^
	
obj/%.o: %.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< $(MYFLAG) -o $@
	
.PHONY: test
test: $(TEST_PATH)
	./bin/test
	
-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $(CPPFLAGS) $(CPPFLAGST) $^ $(MYFLAG) -o $@
	
obj/test/%.o: $(TEST_PATH)/%.c $(LIB_PATH)
	gcc -c $(CFLAGS) $(CPPFLAGS) $(CPPFLAGST) $< $(MYFLAG) -o $@
	
.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find obj -name '*.o' -exec $(RM) '{}' \;
	find obj -name '*.d' -exec $(RM) '{}' \;
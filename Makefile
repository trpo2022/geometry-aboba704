APP_NAME = geometry
LIB_NAME = libgeometry

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
MYFLAG = -lm

APP_PATH = bin/$(APP_NAME)
LIB_PATH = obj/src/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(shell find src/$(APP_NAME) -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/%.c=obj/src/%.o)

LIB_SOURCES = $(shell find src/$(LIB_NAME) -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:src/%.c=obj/src/%.o)

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
	
.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
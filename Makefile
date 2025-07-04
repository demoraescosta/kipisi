# kipisi

PROJ := kipisi

CC  := gcc

BIN := bin
LIB := lib
INC := include
SRC := src

all: $(PROJ)

run: $(PROJ)
	./$<
	
clean:
	rm -rf $(BIN)

#---------------------------------------------------------------------------------- 
# lipu mute
#---------------------------------------------------------------------------------- 

# raylib

RAYLIB_OPTS += PLATFORM=PLATFORM_DESKTOP

$(BIN)/libraylib.a:
	cd $(LIB)/raylib/src/; \
		$(MAKE) $(RAYLIB_OPTS)
	mkdir -p include/raylib
	mkdir -p $(BIN)
	cp $(LIB)/raylib/src/libraylib.a $(BIN)/        # install lib

$(INC)/raylib/raylib.h:
	cp $(LIB)/raylib/src/raylib.h $(INC)/raylib # install headers

build-raylib: $(BIN)/libraylib.a
install-raylib: $(INC)/raylib/raylib.h 

build-libs: build-raylib
install-headers:

#---------------------------------------------------------------------------------- 
# pali e ilo lipu  
#---------------------------------------------------------------------------------- 

CFLAGS += -I$(INC)
CFLAGS += -Wall
LFLAGS += -L.
LFLAGS += -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SOURCES += src/main.c
SOURCES += src/draw.c

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

$(BIN)/$(PROJ): $(OBJECTS) 
	mkdir -p $(BIN)
	cd $(BIN); \
		$(CC) $(notdir $^) $(CFLAGS) $(LFLAGS) -o $(notdir $@)

$(OBJECTS): %.o : %.c
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c $< -o $(BIN)/$(notdir $@)

$(PROJ): $(BIN)/$(PROJ)
	mv $(BIN)/$(PROJ) ./


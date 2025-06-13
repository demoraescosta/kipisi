# kipisi

PROJ := kipisi

CC  := gcc

BIN := bin
LIB := lib
INC := include
SRC := src

all: $(PROJ)

run: $(BIN)/$(PROJ)
	./$<
	
clean:
	rm -rf $(BIN)

#---------------------------------------------------------------------------------- 
# lipu mute
#---------------------------------------------------------------------------------- 

# Raylib

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

$(PROJ): build-libs install-headers $(BIN)/$(PROJ) 

CFLAGS += -I$(INC)
CFLAGS += -Wall
LFLAGS += 

SOURCES += src/main.c

OBJECTS := $(notdir $(patsubst %.c, %.o, $(SOURCES)))

$(BIN)/$(PROJ): $(OBJECTS) 
	mkdir -p $(BIN)
	$(CC) $(BIN)/$(notdir $^) $(CFLAGS) $(LFLAGS) -o $@

$(OBJECTS): %.o : $(SOURCES)
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c $^ -o $(BIN)/$@


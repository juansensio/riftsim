DEBUG ?= 1
ifeq ($(OS),Windows_NT)
    INCLUDES = -I./include
    LDFLAGS = -L./lib
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
else
    INCLUDES = -I/usr/local/include -I./include
    LDFLAGS = -L/usr/local/lib -L./lib
    # Add rpath for macOS
    ifeq ($(shell uname),Darwin)
        LDFLAGS += -Wl,-rpath,/usr/local/lib
    endif
    LIBS = -lraylib
endif

CC = g++
CFLAGS = -Wall -std=c++20 -O3 -Wno-unused-result
ifeq ($(DEBUG),1)
    CFLAGS += -D_DEBUG -g
endif

TARGET = main$(EXT)

# Recursive wildcard function to find all .cpp files in src/ directory and subdirectories
rwildcard = $(foreach d,$(wildcard $1*), \
	$(if $(wildcard $d/),$(call rwildcard,$d/,$2),) \
	$(filter $(subst *,%,$2),$d))

# Define the source files by finding all .cpp files recursively
SRCS := $(call rwildcard,src/,*.cpp)

# Generate object files from source files
OBJS := $(SRCS:.cpp=.o)

# Create output directories
OBJDIRS := $(sort $(dir $(OBJS)))
$(shell mkdir -p $(OBJDIRS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LIBS)

# Pattern rule for object files
%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET) 
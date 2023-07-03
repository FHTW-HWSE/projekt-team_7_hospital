# Compiler
CC=g++

# Compiler flags
CFLAGS=-c -Wall -Wextra

# Include path
INCLUDES=-Iinclude

# Sources
SOURCES=src/main.cpp src/functions.cpp
OBJECTS=$(SOURCES:.cpp=.o)


# Executable name
EXECUTABLE=HWSE_HOSPITAL

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf o $(EXECUTABLE) $(TEST_EXECUTABLE) src/*.o test/*.o
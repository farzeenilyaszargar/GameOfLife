# Compiler
CXX = clang++

# Your source files
SRC = lol.cpp

# Output binary name
TARGET = lol

# SDL2 flags (use sdl2-config to get the right ones)
CXXFLAGS = $(shell sdl2-config --cflags)
LDFLAGS  = $(shell sdl2-config --libs)

INCLUDES = -I/opt/homebrew/include/SDL2 -I/opt/homebrew/Cellar/sdl3/3.2.22/include/SDL3/SDL.h -I/opt/homebrew/Cellar/sdl2/2.32.10/include/SDL2/SDL.h -I/opt/homebrew/Cellar/sdl12-compat/1.2.68/include/SDL/SDL.h

LIBS     = -L/opt/homebrew/lib -lSDL2

# Build rule
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)

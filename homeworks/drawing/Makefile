CXX = g++
SDL = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf
CXXFLAGS = -Wall -c -std=c++11 $(shell sdl2-config --cflags) -D_THREAD_SAFE
LDFLAGS = $(SDL)
DEPS = $(wildcard *.h)
SRCS = $(wildcard *.cpp draw/*.cpp)
OBJS = $(patsubst %.cpp, $(builddir)%.o, $(SRCS))

# Set the build directory
builddir = build/

# Define the target executable name
TARGET = draw_program

all: $(builddir)$(TARGET)

# Link the final executable
$(builddir)$(TARGET): $(OBJS)
	@mkdir -p $(builddir)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

# Compile each source file into an object file
$(builddir)%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Clean up build directory
clean:
	rm -rf $(builddir)

run: $(builddir)$(TARGET)
	./$(builddir)$(TARGET)

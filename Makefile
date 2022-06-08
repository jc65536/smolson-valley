src_dir = src
build_dir = build
exe_name = smolson-valley

CXXFLAGS = -std=c++17 -g
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

headers = $(shell find $(src_dir) -name "*.h")

.PHONY: all test clean

all: $(build_dir)/$(exe_name)

test: all
	gdb -ex run $(build_dir)/$(exe_name)

$(build_dir)/$(exe_name): $(build_dir)/main.o \
$(build_dir)/Game.o \
$(build_dir)/TileMap.o
	$(CXX) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(build_dir)/%.o: $(src_dir)/%.cpp $(headers)
	mkdir -p $(dir $@)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(build_dir)/*

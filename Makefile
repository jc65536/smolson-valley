src_dir = src
build_dir = build
exe_name = smolson-valley

CPPFLAGS = -I$(src_dir)
CXXFLAGS = -std=c++17 -g
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all test clean

all: $(build_dir)/$(exe_name)

test: all
	$(build_dir)/$(exe_name)

$(build_dir)/$(exe_name): $(build_dir)/main.o
	$(CXX) $(LDFLAGS) $< $(LOADLIBES) $(LDLIBS) -o $@

$(build_dir)/%.o: $(src_dir)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(build_dir)/*

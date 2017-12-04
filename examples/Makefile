CXX=g++
RM=rm -f
CXXFLAGS=-I./ -I../ -I../imgui/ $(shell pkg-config --cflags glfw3 glu gl) -Wall -Wformat -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++11 -w -g
CFLAGS = $(CXXFLAGS)
LDFLAGS=-g -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++11 $(shell pkg-config --libs glfw3 glu gl)

OBJS=../imgui/imgui.o ../imgui/imgui_draw.o ../imgui/imgui_demo.o ../imgui/imgui_impl_glfw.o \
     ../imgui_dock.o ../imgui_widgets.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: widgets container rootcontainer
	@true

widgets: widgets.o $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(LDFLAGS) $@.o $(OBJS)

container: container.o $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(LDFLAGS) $@.o $(OBJS)

rootcontainer: rootcontainer.o $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(LDFLAGS) $@.o $(OBJS)

clean:
	$(RM) *.o $(BINS)


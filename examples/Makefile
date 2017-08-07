# void SlidingBar(const char* label, ImGuiWindow* window, ImVec2 *pos, ImVec2 size, 
#                 float minx, float maxx, int direction);
# bool ButtonWithX(const char* label, const ImVec2& size, bool activetab, bool scrollbarcol,
#                  bool *p_open, bool *dragged, bool *dclicked, bool *closeclicked, 
#                  float alpha = 1.f);
# void ResizeGripOther(const char *label, ImGuiWindow* window, ImGuiWindow* cwindow, bool *dclicked=nullptr);
# bool LiftGrip(const char *label, ImGuiWindow* window);

CXX=g++
RM=rm -f
CPPFLAGS=-I./ -I../ -I../imgui/ $(shell pkg-config --cflags glfw3 glu gl) -Wall -Wformat -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++11 -w -g
LDFLAGS=-g -D_GLIBCXX_USE_CXX11_ABI=0 -std=c++11 $(shell pkg-config --libs glfw3 glu gl)
BINS=widgets container rootcontainer

OBJS=../imgui/imgui.o ../imgui/imgui_draw.o ../imgui/imgui_demo.o ../imgui/imgui_impl_glfw.o \
     ../imgui_dock.o ../imgui_widgets.o

all: $(BINS) $(OBJS)
	@true

$(BINS): %: %.o
	$(CXX) $(LDFLAGS) -o $@ $(LDFLAGS) $@.o $(OBJS)

clean:
	$(RM) *.o $(BINS)


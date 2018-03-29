/*
  Copyright (c) 2017 Alberto Otero de la Roza
  <aoterodelaroza@gmail.com>.

  imgui-goodies is free software: you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  imgui-goodies is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_dock.h>
#include <imgui_widgets.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace ImGui;

static void error_callback(int error, const char* description){
  fprintf(stderr, "Error %d: %s\n", error, description);
}

int main(int argc, char *argv[]){
  // Initialize
  glfwSetErrorCallback(error_callback);
  if (!glfwInit()) exit(EXIT_FAILURE);

  // Set up window
  GLFWwindow* rootwin = glfwCreateWindow(1280, 720, "gcritic2", nullptr, nullptr);
  assert(rootwin!=nullptr);
  glfwMakeContextCurrent(rootwin);

  // Setup ImGui binding
  ImGui_ImplGlfwGL2_Init(rootwin, true);

  // GUI settings
  ImGuiIO& io = GetIO();
  io.IniFilename = nullptr;

  // Main loop
  while (!glfwWindowShouldClose(rootwin)){
    // New frame
    glfwPollEvents();
    ImGui_ImplGlfwGL2_NewFrame();
    ImGuiContext *g = GetCurrentContext();

    // Main menu bar
    if (BeginMainMenuBar()){
      if (BeginMenu("File")){
        if (MenuItem("Quit","Ctrl+Q"))
          glfwSetWindowShouldClose(rootwin, GLFW_TRUE);
        EndMenu();
      }
      SameLine(0, GetWindowSize().x-250.);
      Text("%.3f ms/frame (%.1f FPS)", 1000.0f / GetIO().Framerate, GetIO().Framerate);
    }
    EndMainMenuBar();

    // Sliding bar example
    SetNextWindowPos(ImVec2(20.f,40.f),ImGuiSetCond_FirstUseEver);
    SetNextWindowSize(ImVec2(200.f,200.f),ImGuiSetCond_FirstUseEver);
    if (Begin("Sliding bar example")){
      ImGuiWindow* win = GetCurrentWindow();
      static float xbar = 0.5f;
      ImVec2 pos, size;
      pos = win->Pos;
      size = win->Size;
      size.x = 8.f;
      pos.y += win->TitleBarHeight();
      size.y -= win->TitleBarHeight();

      float x0 = win->Pos.x;
      float x1 = win->Pos.x+win->Size.x-size.x;
      pos.x = x0 + xbar * (x1-x0);

      SlidingBar("slider", win, &pos, size, x0, x1, 1);
      xbar = (pos.x - x0 ) / (x1-x0);
    }
    End();
    
    // ButtonWithX example
    SetNextWindowPos(ImVec2(270.f,40.f),ImGuiSetCond_FirstUseEver);
    SetNextWindowSize(ImVec2(200.f,200.f),ImGuiSetCond_FirstUseEver);
    if (Begin("Button with X example")){
      bool p_open = true, dragged, dclicked, closeclicked;
      bool clicked = ButtonWithX("Click me!", ImVec2(80.f,20.f), false, &p_open, &dragged, &dclicked);
      if (clicked)
        printf("Clicked!\n");
      if (!p_open)
        printf(">X< clicked!\n");
      if (dragged)
        Text("Dragged!\n");
      if (dclicked)
        printf("Double clicked!\n");
    }
    End();

    // ButtonWithX example
    SetNextWindowPos(ImVec2(520.f,40.f),ImGuiSetCond_FirstUseEver);
    SetNextWindowSize(ImVec2(200.f,200.f),ImGuiSetCond_FirstUseEver);
    if (Begin("Lift grip example")){
      ImGuiWindow* win = GetCurrentWindow();
      bool lifted = LiftGrip("Liftgrip", win);
      if (lifted)
        Text("Lifted!\n");
    }
    End();

    // ResizeGripOther example.
    SetNextWindowPos(ImVec2(20.f,290.f),ImGuiSetCond_FirstUseEver);
    SetNextWindowSize(ImVec2(200.f,200.f),ImGuiSetCond_FirstUseEver);
    if (Begin("Controlled window",nullptr,ImGuiWindowFlags_NoResize))
      Text("Resize me!\n");
      TextWrapped("Use this other window's grip ----->\n");
    ImGuiWindow* win1 = GetCurrentWindow();
    End();

    // ResizeGripOther example.
    SetNextWindowPos(ImVec2(270.f,290.f),ImGuiSetCond_FirstUseEver);
    SetNextWindowSize(ImVec2(200.f,200.f),ImGuiSetCond_FirstUseEver);
    if (Begin("Parent window",nullptr,ImGuiWindowFlags_NoResize)){
      ImGuiWindow* win2 = GetCurrentWindow();
      TextWrapped("Use this grip to resize the left window.\n");
      ResizeGripOther("resizegrip", win2, win1);
    }
    End();

    // ToolTip example.
    SetNextWindowPos(ImVec2(520.f,290.f),ImGuiSetCond_FirstUseEver);
    SetNextWindowSize(ImVec2(200.f,200.f),ImGuiSetCond_FirstUseEver);
    if (Begin("Delayed tooltips example")){
      const float delay = 1.5f;
      const float maxwidth = 450.f;

      ImGuiWindow* win2 = GetCurrentWindow();
      PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f,0.f));
      PushStyleColor(ImGuiCol_Button, ImVec4(1.f, 0.5f, 0.f, 1.f));
      PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.f, 1.f, 1.f));
      Button("A",ImVec2(20.f,20.f)); SameLine();
      AttachTooltip("A is for Apple",delay,maxwidth,io.FontDefault);
      Button("B",ImVec2(20.f,20.f)); SameLine();
      AttachTooltip("B is for Ball",delay,maxwidth,io.FontDefault);
      Button("C",ImVec2(20.f,20.f));
      AttachTooltip("C is for Cat",delay,maxwidth,io.FontDefault);
      Button("D",ImVec2(20.f,20.f)); SameLine();
      AttachTooltip("D is for Dog",delay,maxwidth,io.FontDefault);
      Button("E",ImVec2(20.f,20.f)); SameLine();
      AttachTooltip("E is for Elephant",delay,maxwidth,io.FontDefault);
      Button("F",ImVec2(20.f,20.f));
      AttachTooltip("F is for Fish",delay,maxwidth,io.FontDefault);
      PopStyleColor(2);
      PopStyleVar();
    }
    End();
    
    // Draw the current scene
    int w, h;
    glfwGetFramebufferSize(rootwin,&w,&h);
    glViewport(0,0,w,h);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Render and swap
    Render();
    glfwSwapBuffers(rootwin);
  }

  // Cleanup
  ShutdownDock();
  ImGui_ImplGlfwGL2_Shutdown();
  glfwTerminate();

  return 0;
}


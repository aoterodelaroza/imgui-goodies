# ImGui Goodies

This is a collection of widgets and utilities for the
[immediate mode GUI (imgui)](https://github.com/ocornut/imgui) that I
am developing for the critic2 GUI. Currently, the contents of this
repo are: 

* `imgui_widget.cpp`: a collection of small independent widgets,
  including:
  
  + `SlidingBar`: a bar widget that slides when it is grabbed with the
  mouse.

  + `ButtonWithX`: a button with an X at the end. Useful for tabs.
  
  + `ResizeGripOther`: a resize grip that resizes a window other than
  the one on which it is drawn.
  
  + `LiftGrip`: a grip on the bottom left part of the window rendered in
  a different color. Responds to grabbing.
  
  + `AttachTooltip`: a function that provides delayed
  tooltips. Tooltips are shown if: i) the mouse hovers over the
  element for longer than a certain time, passed as argument to the
  function, ii) the mouse goes from one tooltip element to another,
  and the tooltip is being shown, or iii) the mouse hovers a tooltip
  element for longer than t seconds and less than t seconds have
  elapsed since the last tooltip was shown. See example below.

* `imgui_dock.cpp`: a window docking system. There are three types of
  windows: 
  
  + Docks (`BeginDock()`/`EndDock()`): like normal windows, except
    they can be docked to the other two window types.

  + Containers (`Container()`): a window to which docks can be
    attached as tabs. It has a behavior similar to a browser window.
	
  + Root containers (`RootContainer()`): a window to which both
    containers and docks can be attached. It splits into regions for
    the different attached windows depending on where they are
    dropped. 
	
  Most of the functionality of normal ImGui windows is
  preserved. `imgui_dock.cpp` uses the widgets in `imgui_widget.cpp`
  but is otherwise self-contained.
  
Some examples are given in the `examples` subdirectory. Use the
`compile.sh` script to build the whole directory tree.

## Examples

Docks, containers, and root containers:

![Example](images/dock_example.gif)

Delayed tooltips:

![Example](images/tooltip_example.gif)


//
//  graphics.h
//  Exam1_testing
//
//  Created by Lisa Dion on 2/19/16.
//  Copyright © 2016 Lisa Dion. All rights reserved.
//

#ifndef graphics_h
#define graphics_h

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Effects: Draws circle of specified pixel radius with center at pixel (x,y)
void drawCircle(int x, int y, int radius);

// Callback functions for GLUT */

// Draw the window - this is where all the GL actions are
void display(void);

// Called when window is resized,
// also when window is first created,
// before the first call to display().
void reshape(int w, int h);

// Refresh the display, called when system is idle
void refresh(void);

// Trap and process keyboard events
void kbd(unsigned char key, int x, int y);

// Handle "mouse cursor moved" events 
void cursor(int x, int y);

// Handle "mouse moved with button pressed" events
void drag(int x, int y);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

int graphicsPlay(int argc, char *argv[]);

#endif /* graphics_h */

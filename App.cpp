#include "App.h"

#ifdef __LINUX__
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#endif

#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define WINDOW_WIDTH	768
#define WINDOW_HEIGHT	768

App* App::_instance = 0;

App::App(int argc, char** argv)
  :_argc(argc),
   _argv(argv)
{
  _instance = this;
}

void App::run()
{
  glutInit(&_argc, _argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowPosition(5,5);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("Animation TP2 - Système masses-ressorts");

  glutIdleFunc(App::glutIdleCallback);
  glutDisplayFunc(App::glutDrawCallback);
  // glutKeyboardFunc(process_key_pressed);
  // glutSpecialFunc(process_specialkey_pressed);
  // glutMotionFunc(process_mouse_moved);

  glutMainLoop();
}

void App::draw()
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glFlush();
}

void App::glutIdleCallback()
{
  clock_t start = clock();
  _instance->draw();
  clock_t end = clock();

  if((end-start)/((double)CLOCKS_PER_SEC) < 0.020)
     usleep(20000.0 - 1000000.0 * (end - start) / ((double)CLOCKS_PER_SEC));
}
void App::glutDrawCallback()
{
  _instance->draw();
}

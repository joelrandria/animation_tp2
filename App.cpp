#include "App.h"

#ifdef __LINUX__
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#endif

#include <time.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "DynamicWorld.h"
#include "Particle.h"
#include "Vec3.h"

#define dimx 5
#define dimy 5

#define WINDOW_WIDTH	768
#define WINDOW_HEIGHT	768

using namespace std;

App* App::_instance = 0;

App::App(int argc, char** argv)
  :_argc(argc),
    _argv(argv)
{
  _obj.init(dimx,dimy);

  _instance = this;
}

void App::simul()
{
  _obj.computeOneStep(0.01);
  glutPostRedisplay ();
}

void App::run()
{
  glutInit(&_argc, _argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowPosition(5,5);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("Animation TP2 - Système masses-ressorts");

  //  glutIdleFunc(App::glutIdleCallback);
  winInit ();
  glutDisplayFunc(App::glutDrawCallback);
  glutIdleFunc(App::glutIdleCallback);

  // glutKeyboardFunc(process_key_pressed);
  // glutSpecialFunc(process_specialkey_pressed);
  // glutMotionFunc(process_mouse_moved);

  //  glutReshapeFunc(reshape);
  //  glutDisplayFunc(display);
  //  glutKeyboardFunc(keyboard);
  //  glutIdleFunc (idle);

  //  glutMainLoop();

  glutMainLoop();
}

void App::winInit()
{
  gluOrtho2D(-10, 30, -10, 10);
}

void App::draw()
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPointSize(5);

  glBegin(GL_POINTS);
  glColor3f(1,0,0);
  for(int i = 0; i < dimy; i++)
    {
      for(int j = 0; j < dimx; j++)
        _obj.DrawParticl(_obj.getParticl(j,i));
    }
  glEnd();
  /**/
  glBegin(GL_LINES);
  glColor3f(1,1,1);
  //    for(int i = 0; i < dimy-1 ; i++)
  //      {
  //        for(int j = 0; j < dimx-1; j++)
  //          {
  for(int n = 0; n < (((dimy-1)*dimx)*2)+((dimy-1)*(dimx-1)*2); n++ )
    {
      //            _obj.DrawSpring(_obj.getSpring(j, i, 1));
      _obj.DrawSpring(_obj.getSpring(n));

    }

glEnd();

glFlush();
}

void App::glutIdleCallback()
{
  clock_t start = clock();
  //_instance->draw();
  _instance->simul();
  clock_t end = clock();

  if((end-start)/((double)CLOCKS_PER_SEC) < 0.020)
    usleep(20000.0 - 1000000.0 * (end - start) / ((double)CLOCKS_PER_SEC));
}
void App::glutDrawCallback()
{
  _instance->draw();
}

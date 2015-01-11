#ifndef __APP_H__
#define __APP_H__

#include "DynamicWorld.h"

class App
{
 private:

  static App* _instance;

  int _argc;
  char** _argv;

  DynamicWorld _obj;

 public:

  App(int argc, char** argv);

  void run();

 private:
  void simul();
  void draw();
  void winInit ();

 public:

  static void glutDrawCallback();
  static void glutIdleCallback();

};

#endif

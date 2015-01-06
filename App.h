#ifndef __APP_H__
#define __APP_H__

class App
{
 private:

  static App* _instance;

  int _argc;
  char** _argv;

 public:

  App(int argc, char** argv);

  void run();

 private:

  void draw();

 public:

  static void glutDrawCallback();
  static void glutIdleCallback();

};

#endif

#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Team.h"
using namespace std;

struct stackNode {
   Team res_echipa;
   struct stackNode *next;
};


class Stack {
   protected:
      stackNode* top;
   public:
      Stack();
      void push(Team echipa);
      Team pop();
      void display(char *argv[]);
      int isEmpty();
};

#endif

#ifndef SERVICES_H
#define SERVICES_H

#include "people.h"

class Services{
  public:
    People* generate(int lenght);
    void print_peoples(People peoples[], int length);
};


#endif

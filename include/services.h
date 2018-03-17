#ifndef SERVICES_H
#define SERVICES_H

#include "people.h"

class Services{
  public:
    People* generate(int length);
    int generate_height();
    double generate_weight();
    std::string generate_name();
    void print_peoples(People peoples[], int length);
};


#endif

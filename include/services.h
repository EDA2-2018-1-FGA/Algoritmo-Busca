#ifndef SERVICES_H
#define SERVICES_H

#include "people.h"

class Services{
  private:
  public:
    static People* generate(const int length);
    static int generate_height();
    static double generate_weight();
    static std::string generate_name();
    static void print_peoples(People peoples[], const int length);
    static void print_peoples(People peoples[], const int length, const int *idx);
    static void print_peoples_g(People peoples[], const int length, const int *ordened, const int *idx);
    static int sequential_search(People peoples[], const int length, const std::string name);
};


#endif

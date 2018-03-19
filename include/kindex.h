#ifndef KINDEX_H
#define KINDEX_H

#include <bits/stdc++.h>
#include "people.h"

class Kindex{
  private:
    int* ordened;
    int** kindex;

  public:
    Kindex(People *people, const int size);
    int* get_ordened();

    //int find(const std::string name);
};


#endif

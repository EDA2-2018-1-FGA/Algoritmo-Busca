#ifndef KINDEX_H
#define KINDEX_H

#include <bits/stdc++.h>
#include "people.h"

class Kindex{
  private:
    int* ordened;
    int kindex[26];
 
    void generate_index(People *people, const int size);
    void shell_sort(People *people, const int size);

  public:
    Kindex(People *people, const int size);
    int* get_ordened();
    int* get_index();

    int find(const std::string name);

};

#endif

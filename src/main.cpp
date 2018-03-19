#include <bits/stdc++.h>
#include "people.h"
#include "services.h"
#include "kindex.h"

#define LENGTH 100

int main(){
  srand(time(NULL));
  People* xxx = Services::generate(LENGTH);
  Services::print_peoples(xxx, LENGTH);
  Kindex* k = new Kindex(xxx, LENGTH);
  Services::print_peoples(xxx, LENGTH, k->get_ordened());
  Services::print_peoples_g(xxx, LENGTH, k->get_ordened(), k->get_index());

  return 0;
}

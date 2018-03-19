#include <bits/stdc++.h>
#include "people.h"
#include "services.h"
#include "kindex.h"

int main(){
  People* xxx = Services::generate(100);
  Services::print_peoples(xxx, 100);
  Kindex* k = new Kindex(xxx, 100);
  Services::print_peoples(xxx, 100, k->get_ordened());

  return 0;
}

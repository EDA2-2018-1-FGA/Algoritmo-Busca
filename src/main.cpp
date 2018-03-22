#include <bits/stdc++.h>
#include <chrono>
#include "people.h"
#include "services.h"
#include "kindex.h"

#define LENGTH 100

int main(){
  srand(time(NULL));
  People* xxx = Services::generate(LENGTH);
  Services::print_peoples(xxx, LENGTH);
  Kindex* k = new Kindex(xxx, LENGTH);
//  Services::print_peoples(xxx, LENGTH, k->get_ordened());
//  Services::print_peoples_g(xxx, LENGTH, k->get_ordened(), k->get_index());

  std::string name;
  std::cout << "Search name: ";
  std::getline(std::cin, name);
  int indexed_search_return;
  int sequential_search_return;

  auto indexed_begin_timer = std::chrono::high_resolution_clock::now();
  indexed_search_return = k->find(name, xxx, LENGTH);
  auto indexed_end_timer = std::chrono::high_resolution_clock::now();
  std::cout << "Indexed search time: " <<  std::chrono::duration_cast<std::chrono::nanoseconds>(indexed_end_timer - indexed_begin_timer).count() << "ns" << std::endl;

	auto sequential_begin_timer = std::chrono::high_resolution_clock::now();
  sequential_search_return = Services::sequential_search(xxx, LENGTH, name);
  auto sequential_end_timer = std::chrono::high_resolution_clock::now();
  std::cout << "Sequential search time: " <<  std::chrono::duration_cast<std::chrono::nanoseconds>(sequential_end_timer - sequential_begin_timer).count() << "ns" << std::endl;

  std::cout << "(Indexed)Id:" << indexed_search_return << std::endl;
  std::cout << "(Sequential)Id:" << sequential_search_return << std::endl;

  return 0;
}

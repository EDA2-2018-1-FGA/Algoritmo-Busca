#include "services.h"

People*
Services::generate(int lenght){
  People* peoples = new People[lenght];


  return peoples;
}

void
Services::print_peoples(People peoples[], int length){
    std::cout << "Name | Weight | Height" << std::endl;
    for(int i = 0; i < length; i++){
        std::cout << peoples[i].get_name() << " | ";
        std::cout << peoples[i].get_weight() << " | ";
        std::cout << peoples[i].get_height() << std::endl;
    }
}

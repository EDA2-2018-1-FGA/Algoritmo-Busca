#include "kindex.h"
#include "people.h"

Kindex::Kindex(People* people, const int size){
  this->ordened = new int[size];
  /* copy index to ordened vector */ 
  for(int i = 0; i < size; i++)
    this->ordened[i] = i;

  /*shell sort*/
  int mid = size / 2;
  int aux_idx, current;
  
  while(mid > 0){
    for(int i = mid; i < size; i++){
      current = ordened[i];
      aux_idx = i;
      while(aux_idx >= mid && 
            people[ordened[aux_idx - mid]].get_name() > people[current].get_name()){
        ordened[aux_idx] = ordened[aux_idx - mid];
        aux_idx -= mid;
      }
      ordened[aux_idx] = current;
    }
    mid /= 2;
  }
}


int* 
Kindex::get_ordened(){
  return this->ordened;
}

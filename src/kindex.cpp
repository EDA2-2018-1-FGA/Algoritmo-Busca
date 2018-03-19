#include "kindex.h"
#include "people.h"

Kindex::Kindex(People* people, const int size){

  this->ordened = new int[size];
  /* copy index to ordened vector */ 
  for(int i = 0; i < size; i++){
    this->ordened[i] = i;
  }

  for(int i = 0; i < 26; i++){
    this->kindex[i] = INT_MAX;
  }

  /*shell sort*/
  this->shell_sort(people, size);
  this->generate_index(people, size);
}

void
Kindex::generate_index(People *people, const int size){
  for(int i = 0, j = 0; i < size; i++){
    if(people[this->ordened[i]].get_name()[0] == 'A' + j){
      this->kindex[j] = (i < this->kindex[j])? i : this->kindex[j];
      j++;
    } else if(people[this->ordened[i]].get_name()[0] > 'A' + j){
      j++;
      i--;
    }
  }
}

void
Kindex::shell_sort(People *people, const int size){
  int mid = size / 2;
  int aux_idx, current;
  
  while(mid > 0){
    for(int i = mid; i < size; i++){
      current = this->ordened[i];
      aux_idx = i;
      while(aux_idx >= mid && 
            people[this->ordened[aux_idx - mid]].get_name() > people[current].get_name()){
        this->ordened[aux_idx] = this->ordened[aux_idx - mid];
        aux_idx -= mid;
      }
      this->ordened[aux_idx] = current;
    }
    mid /= 2;
  }

}

int* 
Kindex::get_ordened(){
  return this->ordened;
}

int*
Kindex::get_index(){
  return this->kindex;
}

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


int 
Kindex::find(const std::string name, People *people, const int size){
  int id = -1;
  int start = this->kindex[name[0] - 'A']; 
  int end;

  if(start == INT_MAX){
    return id;
  }

  if(name[0] == 'Z'){
    end = size;
  } else {
    end = this->kindex[name[0] - 'A' + 1];
  }

  for(int i = start; i < end; i++){
    if(name == people[ordened[i]].get_name()){
      return ordened[i];
    }
  }

  return id;
}

int* 
Kindex::get_ordened(){
  return this->ordened;
}

int*
Kindex::get_index(){
  return this->kindex;
}

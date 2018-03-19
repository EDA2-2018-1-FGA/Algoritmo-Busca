#ifndef PEOPLE_H
#define PEOPLE_H

#include <bits/stdc++.h>

class People{

  private:
    std::string name;
    int weight;
    double height;

  public:
    People(){}
    People(const std::string name, 
           const int weight, 
           const double height): name(name),
                                 weight(weight),
                                 height(height){}

    void set_name(const std::string name);

    void set_weight(const int weight);

    void set_height(const double height);

    std::string get_name();

    int get_weight();

    double get_height();

};

#endif

#ifndef PEOPLE_H
#define PEOPLE_H

#include <bits/stdc++.h>

class People{

  private:
    std::string name;
    int weight;
    double height;

  public:
    People(std::string name, int weight, double height): name(name),
                                                         weight(weight),
                                                         height(height){}

    void set_name(std::string name);

    void set_weight(int weight);

    void set_height(double height);

    std::string get_name();

    int get_weight();

    double get_height();

};

#endif

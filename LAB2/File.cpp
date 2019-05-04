//
// Created by Lorenzo Del Sordo on 2019-05-04.
//

#include "File.h"
#include <iostream>

File::File(std::string name, uintmax_t dim) {
    this->name = name;
    this->dim = dim;
    type = 0;
}

int File::mType() const {return type;}
void File::ls(int indent) const{
    for (int i = indent; i != 0; i--)
        printf("\t");
    std::cout << File::getName()<< " "<< File::dim << std::endl;
}
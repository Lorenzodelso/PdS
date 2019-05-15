//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#include "Symbol.h"

Symbol::Symbol(char value, UniqueID* id, std::vector<int> pos):id(id){
    this->c = value;
    this->pos = pos;
}

Symbol::Symbol(const Symbol &s) {
    this->c = s.c;
    this->id = s.id;
    this->pos = s.pos;
}

std::vector<int> Symbol::getPos() {return pos;}

char Symbol::getValue() {return c;}

bool Symbol::equalId(Symbol &other) {
    return this->id->equals(*other.id);
}
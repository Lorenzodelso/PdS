//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#ifndef LAB3_1_SYMBOL_H
#define LAB3_1_SYMBOL_H

#include <vector>
#include "UniqueID.h"


class Symbol {
private:
    char c;
    UniqueID* id;
    std::vector<int> pos;

public:
    Symbol(char value, UniqueID* id, std::vector<int> pos);
    Symbol(const Symbol& s);
    std::vector<int> getPos();
    char getValue();
    bool equalId(Symbol& other);
};


#endif //LAB3_1_SYMBOL_H

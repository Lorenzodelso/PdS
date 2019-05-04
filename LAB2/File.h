//
// Created by Lorenzo Del Sordo on 2019-05-04.
//

#ifndef LAB2_FILE_H
#define LAB2_FILE_H


#include <cstdint>
#include <string>
#include "Base.h"

class File: public Base {
private:
    uintmax_t dim;
    int type;

public:
    File(std::string,uintmax_t dim);
    int mType() const override;
    void ls(int indent=0) const override;
};


#endif //LAB2_FILE_H

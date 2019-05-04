//
// Created by Lorenzo Del Sordo on 2019-05-03.
//

#ifndef LAB2_BASE_H
#define LAB2_BASE_H


#include <string>

class Base {
public:
    std::string name;

    std::string getName() const;
    virtual int mType() const = 0;
    virtual void ls(int indent = 0) const = 0;
};


#endif //LAB2_BASE_H

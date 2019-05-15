//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#ifndef LAB3_1_MESSAGE_H
#define LAB3_1_MESSAGE_H

#include "Symbol.h"

class Message {
    bool insert;
    int siteId;
    Symbol* s;

public:
    Message(bool insert, int siteId,Symbol* s);
    Message(const Message& m);

    bool isInsert();
    Symbol* getSymbol();
    int getSiteId();
};


#endif //LAB3_1_MESSAGE_H

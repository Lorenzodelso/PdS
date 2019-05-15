//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#ifndef LAB3_1_SHAREDEDITOR_H
#define LAB3_1_SHAREDEDITOR_H

#include "Message.h"
#include <string>
class NetworkServer; //to avoid circular dependencies


class SharedEditor {
    NetworkServer& _server;
    int _siteId;
    std::vector<Symbol> symbols;
    int _counter;

    std::vector<int> generatePos(int index);
    void insertInList(Symbol& s);

public:

    SharedEditor(NetworkServer& server);
    void process(Message& m);
    void localInsert(int index, char value);
    void localErase(int index);
    int getSiteId();
    std::string to_string();
};


#endif //LAB3_1_SHAREDEDITOR_H

//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#ifndef LAB3_1_NETWORKSERVER_H
#define LAB3_1_NETWORKSERVER_H


#include <queue>
#include "SharedEditor.h"

class NetworkServer {
private:
    std::vector<SharedEditor*> editor_list;
    std::vector<Message> message_list;
    int id;

public:
    NetworkServer();
    int connect(SharedEditor* sharedEditor);
    void disconnect(SharedEditor* sharedEditor);
    void send(const Message& m);
    void dispatchMessages();

};


#endif //LAB3_1_NETWORKSERVER_H

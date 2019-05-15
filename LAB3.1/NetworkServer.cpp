//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#include "NetworkServer.h"

NetworkServer::NetworkServer() {
    id = 0;
}

int NetworkServer::connect(SharedEditor *sharedEditor) {
    editor_list.insert(editor_list.cbegin(),sharedEditor);
    id++;
    return id;
}

void NetworkServer::disconnect(SharedEditor *sharedEditor) {
    auto pos = std::find(editor_list.cbegin(),editor_list.cend(),sharedEditor);
    if(pos!=editor_list.cend())
        editor_list.erase(pos);
}

void NetworkServer::send(const Message &m) {
    this->message_list.push_back(m);
}

void NetworkServer::dispatchMessages() {
    while (this->message_list.size()>0){
        for (auto it:editor_list){
            if (message_list.front().getSiteId()!=it->getSiteId())
                it->process(message_list.front());
        }
        message_list.erase(message_list.cbegin());
    }
}
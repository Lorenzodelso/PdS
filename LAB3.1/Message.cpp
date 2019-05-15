//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#include "Message.h"
Message::Message(bool insert, int siteId, Symbol* s): s(s),insert(insert),siteId(siteId) {}

Message::Message(const Message &m) {
    this->insert = m.insert;
    this->siteId = m.siteId;
    this->s = m.s;
}

bool Message::isInsert() { return insert;}

Symbol* Message::getSymbol(){ return s;}

int Message::getSiteId() { return siteId;}

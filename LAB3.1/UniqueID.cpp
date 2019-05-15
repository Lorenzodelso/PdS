//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#include "UniqueID.h"
UniqueID::UniqueID(int siteId, int siteCounter) {
    this->siteId = siteId;
    this->siteCounter = siteCounter;
}

bool UniqueID::equals(UniqueID &par) {
    if (siteId == par.siteId && siteCounter == par.siteCounter)
        return true;
    return false;
}
//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#ifndef LAB3_1_UNIQUEID_H
#define LAB3_1_UNIQUEID_H


class UniqueID {
private:
    int siteId;
    int siteCounter;

public:
    UniqueID(int siteId, int siteCounter);
    bool equals(UniqueID& par);
};


#endif //LAB3_1_UNIQUEID_H

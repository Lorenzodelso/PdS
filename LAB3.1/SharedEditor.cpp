//
// Created by Lorenzo Del Sordo on 2019-05-14.
//

#include "SharedEditor.h"
#include "NetworkServer.h"
#include <math.h>

SharedEditor::SharedEditor(NetworkServer& server) : _server(server) {
    _siteId = _server.connect(this);
    _counter = 0;
}

float calcFract(std::vector<int> pos){
    float f=0.0;
    int j=0;
    for (auto i : pos){
        f+=i*(pow(0.1,j));
        j++;
    }
    return f;
}

std::vector<int> calcPos(float fract){
    int i;
    i = fract;
    int j;
    j = (fract-i)*10;
    std::vector<int> pos;
    pos.push_back(i);
    pos.push_back(j);

    return pos;
}
//genera una posizione frazionaria compresa tra le posizioni frazionarie
//degli elementi agli indici index e index-1
std::vector<int> SharedEditor::generatePos(int index){
    std::vector<int> pos;
    //indice libero in cui inserire
    if (this->symbols.size()<(index+1) || this->symbols.size()==0){
        pos.push_back(index);
    } else if(index==0){ //indice uguale a 0, inserisco con frazionaria negativa
        pos.push_back(symbols[index].getPos()[0]-1);
    }else { //indice occupato, inserisco con frazionaria compresa tra i due
        float f1 = calcFract(symbols[index].getPos());
        float f2 = calcFract(symbols[index - 1].getPos());
        float res = (f1 - f2) / 2;
        //la posizione frazionaria viene presa a metà tra le due posizioni frazionarie
        f2 += res;
        pos = calcPos(f2);
    }
    return pos;
}

void SharedEditor::localInsert(int index, char value) {
    UniqueID* id = new UniqueID(this->_siteId,this->_counter);
    _counter++;
    std::vector<int> pos;
    pos = generatePos(index);

    Symbol* sym = new Symbol(value,id,pos);
    symbols.insert(symbols.cbegin()+index,*sym);

    Message* mex = new Message(true,this->_siteId,sym);
    this->_server.send(*mex);
}

void SharedEditor::insertInList(Symbol& s){
    if (this->symbols.size()==0)
        symbols.insert(symbols.cbegin(),s);
    else{
        int pos=0;
        for (auto i:symbols){
            if (calcFract(i.getPos())> calcFract(s.getPos()))
                break;
            else
                pos++;
        }
        symbols.insert(symbols.cbegin()+pos,s);
    }
}

void SharedEditor::process(Message &m) {
    if (m.isInsert()){ //caso di inserimento di un carattere
        insertInList(*m.getSymbol());
    }
    else{
        int pos=0;
        for (auto i:symbols){
            if(calcFract(i.getPos())==calcFract(m.getSymbol()->getPos()) && i.equalId(*m.getSymbol())){
                break;
            }else
                pos++;
        }
        symbols.erase(symbols.cbegin()+pos);
    }
}

int SharedEditor::getSiteId() {return _siteId;}

std::string SharedEditor::to_string() {
    std::string str;
    for(auto i:symbols){
        str.insert(str.cend(),i.getValue());
    }
    return str;
}

void SharedEditor::localErase(int index) {
    Symbol* sym = new Symbol(this->symbols[index]);
    Message* mex = new Message(false,this->_siteId,sym);
    symbols.erase(symbols.cbegin()+index);
    this->_server.send(*mex);
}
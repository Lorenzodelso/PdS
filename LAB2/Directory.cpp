//
// Created by Lorenzo Del Sordo on 2019-05-03.
//

#include "Directory.h"
#include <iostream>

std::shared_ptr<Directory> Directory::instance = nullptr;

int Directory::mType() const { return type;}

void Directory::ls(int indent) const {

    for (int i = indent; i != 0; i--) {
        printf("\t");
    }
    std::cout << "[+] "<<Directory::getName() << std::endl;
    for (auto s:list) {
        for (int i = indent; i != 0; i--) {
            printf("\t");
        }
        s->ls(indent + 1);
    }
}

Directory::Directory(std::string name) {
    this->name = name;
    this->type = 1;
}

std::shared_ptr<Directory> Directory::getRoot() {
    if(instance == nullptr){
        instance = std::shared_ptr<Directory>(new Directory("/"));
        instance->father = instance;
        instance->me = instance;
    }

    return instance;
}

std::shared_ptr<Directory> Directory::addDirectory(std::string name) {
    bool pres = false;

    for(auto s : Directory::list){
        if(s->getName() == name && s->mType()==1) pres= true;
    }

    if(!pres){
        std::shared_ptr<Directory> ptr1 (new Directory(name));
        list.insert(list.cend(),ptr1);
        ptr1->me = ptr1;
        ptr1->father = this->me;
        return ptr1;
    }else
        throw std::exception();
}

std::shared_ptr<File> Directory::addFile(std::string name, uintmax_t size) {
    bool pres = false;

    for(auto s : Directory::list){
        if(s->getName() == name && s->mType()==0) pres= true;
    }

    if(!pres){
        std::shared_ptr<File> ptr1(new File(name,size));
        list.insert(list.cend(),ptr1);
        return ptr1;
    } else
        throw std::exception();
}

std::shared_ptr<Base> Directory::get(std::string name){
    if(name == "..") return std::shared_ptr<Directory> (father);
    if (name == ".") return std::shared_ptr<Directory> (me);

    for(auto s : list){
        if (s->getName() == name) return s;
    }

    return std::shared_ptr<Base>(nullptr);
}

std::shared_ptr<Directory> Directory::getDir(std::string name) {
    return std::dynamic_pointer_cast<Directory> (Directory::get(name));
}

std::shared_ptr<File> Directory::getFile(std::string name) {
    return std::dynamic_pointer_cast<File>(Directory::get(name));
}

void Directory::remove(std::string name) {
    if(name == ".." | name== ".") throw std::exception();
    else {
        for (auto s = list.cbegin(); s!= list.cend();s++){
            if (s->get()->getName() == name) {
                list.erase(s);
                return;
            }
        }
    }
}


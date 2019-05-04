//
// Created by Lorenzo Del Sordo on 2019-05-03.
//

#ifndef LAB2_DIRECTORY_H
#define LAB2_DIRECTORY_H


#include <vector>
#include "Base.h"
#include "File.h"

class Directory: public Base {
protected:
    Directory(std::string name);

private:
    int type;
    std::vector<std::shared_ptr<Base>> list;
    std::weak_ptr<Directory> father;
    std::weak_ptr<Directory> me;

public:
    static std::shared_ptr<Directory> instance;

    Directory(Directory& source) = delete;
    void operator=(Directory& source) = delete;
    int mType() const override ;
    void ls(int indent = 0) const override;

    static std::shared_ptr<Directory> getRoot();
    std::shared_ptr<Directory> addDirectory(std::string name);
    std::shared_ptr<File> addFile(std::string name, uintmax_t size);
    std::shared_ptr<Base> get(std::string name);
    std::shared_ptr<Directory> getDir(std::string name);
    std::shared_ptr<File> getFile(std::string name);
    void remove(std::string name);
};


#endif //LAB2_DIRECTORY_H

//
// Created by fkris on 11/9/2026.
//

#ifndef CPP_2026_DIRECTORY_H
#define CPP_2026_DIRECTORY_H


#include "FileSystemItem.h"
#include <vector>

class Directory : public FileSystemItem {
private:
    std::vector<FileSystemItem*> children;

public:
    Directory(const std::string& name);
    ~Directory() override;

    Directory(const Directory& other);
    Directory& operator=(const Directory& other);

    void add(FileSystemItem* item);
    void remove(const std::string& name);
    FileSystemItem* find(const std::string& name);
    long getSize() const override;
    void display(std::ostream& os = std::cout, int depth = 0) const override;
    FileSystemItem* clone() const override;
    Directory& operator+=(FileSystemItem* item);
    Directory& operator-=(const std::string& name);
};

#endif //CPP_2026_DIRECTORY_H

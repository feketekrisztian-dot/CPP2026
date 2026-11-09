//
// Created by fkris on 11/9/2026.
//

#ifndef CPP_2026_FILESYSTEMITEM_H
#define CPP_2026_FILESYSTEMITEM_H

#include <iostream>
#include <string>

class FileSystemItem {
protected:
    std::string name;

public:

    FileSystemItem(const std::string& name);
    virtual ~FileSystemItem() = default;
    std::string getName() const;
    virtual void display(std::ostream& os = std::cout, int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;
    virtual long getSize() const = 0;
    bool operator<(const FileSystemItem& other) const;
    friend std::ostream& operator<<(std::ostream& os, const FileSystemItem& item);
};

#endif //CPP_2026_FILESYSTEMITEM_H

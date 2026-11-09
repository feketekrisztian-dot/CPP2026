//
// Created by fkris on 11/9/2026.
//

#ifndef CPP_2026_FILE_H
#define CPP_2026_FILE_H

#include "FileSystemItem.h"

class File : public FileSystemItem {
private:
    long size;

public:
    File(const std::string& name, long size);
    void display(std::ostream& os = std::cout, int depth = 0) const override;
    FileSystemItem* clone() const override;
    long getSize() const override;
};

#endif //CPP_2026_FILE_H

    //
// Created by fkris on 11/9/2026.
//

#include "File.h"

File::File(const std::string& name, long size)
    : FileSystemItem(name), size(size) {}

long File::getSize() const {
    return size;
}

void File::display(std::ostream& os, int depth) const {
    os << name << " (" << size << " bájt)\n";
}

FileSystemItem* File::clone() const
{
    return new File(*this);
}


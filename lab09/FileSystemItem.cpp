//
// Created by fkris on 11/9/2026.
//

#include "FileSystemItem.h"

FileSystemItem::FileSystemItem(const std::string& name) : name(name) {}

std::string FileSystemItem::getName() const {
    return name;
}

bool FileSystemItem::operator<(const FileSystemItem& other) const {
    return name < other.name;
}

std::ostream& operator<<(std::ostream& os, const FileSystemItem& item) {
    item.display(os);
    return os;
}
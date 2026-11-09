//
// Created by fkris on 11/9/2026.
//

#include "Directory.h"

Directory::Directory(const std::string& name) : FileSystemItem(name) {}
Directory::~Directory() { 
    for (auto child : children) {
        delete child; 
    }
    children.clear();
}
Directory::Directory(const Directory& other) : FileSystemItem(other.name) {
    for (const auto child : other.children) {
        if (child) {
            children.push_back(child->clone());
        }
    }
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        name = other.name;

        for (auto child : children) {
            delete child;
        }
        children.clear();

        for (const auto child : other.children) {
            if (child) {
                children.push_back(child->clone());
            }
        }
    }
    return *this;
}

FileSystemItem* Directory::clone() const {
    return new Directory(*this);
}



// Elem hozzáadása
void Directory::add(FileSystemItem* item) { 
    if (item) {
        children.push_back(item);
    }
}

void Directory::remove(const std::string& name) {

    auto it = std::find_if(children.begin(), children.end(), [&name](const FileSystemItem* item) {
        return item && item->getName() == name;
    });


    if (it != children.end()) {
        children.erase(it);
        delete *it;
    }
}

FileSystemItem* Directory::find(const std::string& name) { 
    for (auto child : children) {
        if (child->getName() == name) {
            return child;
        }
        Directory* subDir = dynamic_cast<Directory*>(child);
        if (subDir) {
            FileSystemItem* found = subDir->find(name);
            if (found) return found;
        }
    }
    return nullptr;
}

long Directory::getSize() const { 
    long totalSize = 0;
    for (const auto child : children) {
        if (child) {
            totalSize += child->getSize(); 
        }
    }
    return totalSize;
}

void Directory::display(std::ostream& os, int depth) const { 
    std::string indent(depth, ' '); 
    os << indent << name << "/ (" << getSize() << " bytes)\n"; 
    for (const auto child : children) {
        if (child) {
            child->display(os, depth + 2); 
        }
    }
}


Directory& Directory::operator+=(FileSystemItem* item) { 
    add(item);
    return *this;
}

Directory& Directory::operator-=(const std::string& name) { 
    remove(name);
    return *this;
}

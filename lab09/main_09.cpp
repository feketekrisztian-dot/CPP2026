#include <iostream>
#include "FileSystemItem.h"
#include "File.h"
#include "Directory.h"

using namespace std;

int main() {
    cout << "=== Fajlrendszer Szimulacio ===" << endl << endl;

    // 1. Gyökér könyvtár létrehozása (root)
    Directory* root = new Directory("root");

    // 2. Struktúra felépítése
    cout << "Fajlrendszer felepitese..." << endl;

    // Documents könyvtár és fájlok
    Directory* documents = new Directory("documents");
    documents->add(new File("report.txt", 1500));
    documents->add(new File("notes.txt", 800));

    // Pictures könyvtár és fájlok
    Directory* pictures = new Directory("pictures");
    pictures->add(new File("photo1.jpg", 2048000));
    pictures->add(new File("photo2.jpg", 1856000));

    // Elemek hozzáadása a gyökérhez a += operátor segítségével
    *root += documents;
    *root += pictures;
    *root += new File("readme.txt", 500);

    // 3. Teljes struktúra megjelenítése az operator<< segítségével
    cout << endl << "Teljes fajlrendszer:" << endl;
    cout << "=====================" << endl;
    cout << *root;

    // 4. Teljes méret kiírása
    cout << endl << "Teljes meret: " << root->getSize() << " bytes" << endl;

    // 5. Fájl keresése név alapján
    cout << endl << "Kereses: photo1.jpg" << endl;
    FileSystemItem* found = root->find("photo1.jpg");
    if (found) {
        cout << "Talalat!" << endl;
    } else {
        cout << "Nincs talalat!" << endl;
    }

    // 6. Elem eltávolítása a -= operátor segítségével
    cout << endl << "photo1.jpg torlese (-= operator)..." << endl;
    *root -= "photo1.jpg";

    cout << endl << "Torles utan:" << endl;
    root->display();

    // 7. Mély másolat (Deep Copy) készítése és megjelenítése
    cout << endl << "Konyvtar masolasa (clone / deep copy)..." << endl;
    Directory* rootCopy = dynamic_cast<Directory*>(root->clone());
    if (rootCopy) {
        cout << "Masolat tartalma:" << endl;
        rootCopy->display();
    }

    // 8. operator< demonstrációja (név szerinti összehasonlítás)
    cout << endl << "operator< tesztelese:" << endl;
    if (*documents < *pictures) {
        cout << "'" << documents->getName() << "' megelozi a nevsorban ezt: '" << pictures->getName() << "'" << endl;
    }

    // Dinamikusan lefoglalt objektumok felszabadítása
    delete root;
    delete rootCopy;

    return 0;
}
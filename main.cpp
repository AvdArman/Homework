#include "BinaryTree.h"
#include <iostream>

int main() {
    BinaryTree b;
    b.insert(30);
    b.insert(70);
    b.insert(100);
    b.insert(120);
    b.insert(40);
    b.insert(10);
    b.insert(50);

    std::cout << b.find(0) << std::endl;
    std::cout << b.height() << std::endl;
<<<<<<< HEAD
=======
    std::cout << b.size();
    std::cout << b.find(4);
>>>>>>> 438dbc39259f07265f9151bed7e491fd15ed8a70
    return 0;
}

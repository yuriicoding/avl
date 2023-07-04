#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
    BinarySearchTree<int> t1;
    for (int i = 0; i < 20; i++)
        t1.insert(i);
    cout << "t1 tree" << endl;
    t1.displayTree();
    cout << "12 depth: " << t1.depth(12) << endl;
    cout << "0 depth: " << t1.depth(0) << endl;
    cout << "28 depth: " << t1.depth(28) << endl;
    cout << endl;

    BinarySearchTree<char> t2;
    char keyboard[] = "qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i < 26; i++)
        t2.insert(keyboard[i]);
    cout << "t2 tree" << endl;
    t2.displayTree();
    cout << "g depth: " << t2.depth('g') << endl;
    cout << "m depth: " << t2.depth('m') << endl;
    cout << "w depth: " << t2.depth('w') << endl;
    cout << endl;

    BinarySearchTree<float> t3;
    srand(time(NULL));
    float rain[] = {61.9, 7.0, 6.4, 27.9, 69.7, 92.1, 94.6, 153.0,
    59.7, 131.7, 93.5, 312.4, 148.4, 155.0, 36.7, 0.0, 37.2, 30.2, 38.0,
    34.0, 75.0, 175.7, 182.2, 189.3, 87.5, 59.2};
    for (int i = 0; i < 26; i++)
        t3.insert(rain[i]);
    cout << "t3 tree" << endl;
    t3.displayTree();
    cout << "155.0 depth: " << t3.depth(155.0) << endl;
    cout << "59.2 depth: " << t3.depth(59.2) << endl;
    cout << "7.0 depth: " << t3.depth(7.0) << endl;
    cout << endl;

    return 0;
}
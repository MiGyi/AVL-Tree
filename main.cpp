#include <iostream>
#include <fstream>

using namespace std;

#include "AVL-Tree.h"

int main()
{
    ifstream fi("input.txt");
    ofstream fo("output.txt");

    int num;
    AVL_Tree Tree;

    while(fi >> num) Tree.Insert(num);

    Tree.Traversal(fo);

    fi.close();
    fo.close();
    return 0;
}

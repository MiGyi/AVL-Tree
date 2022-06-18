#pragma once

#include <fstream>

struct AVL_Node {
    int data = 0;
    int height = 0;

    AVL_Node *Left = nullptr, *Right = nullptr;

    AVL_Node (int x);
};

int GetHeight(AVL_Node *p);

struct AVL_Tree {

    AVL_Node *Root = nullptr;

    ~AVL_Tree();
    void Self_Destruct(AVL_Node* &Cur);
    int GetBF(AVL_Node *Cur);
    AVL_Node* LeftRotate(AVL_Node *cur);
    AVL_Node* RightRotate(AVL_Node *cur);
    AVL_Node *_Insert(AVL_Node *Cur, int &x);
    void Insert(int x);
    void _Traversal(AVL_Node *Root, std::ofstream &fo);
    void Traversal(std::ofstream &fo);
};

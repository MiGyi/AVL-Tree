#include "AVL-Tree.h"

#include <iostream>
#include <fstream>

using namespace std;

AVL_Node::AVL_Node (int x) {
    data = x;
    height = 1;
}

int GetHeight(AVL_Node *p) {
    if (!p) return 0;
    return p->height;
}


AVL_Tree::~AVL_Tree() {
    Self_Destruct(Root);
}

void AVL_Tree::Self_Destruct(AVL_Node* &Cur) {

    if (Cur == nullptr) return;
    Self_Destruct(Cur->Left);
    Self_Destruct(Cur->Right);
    delete Cur;
    Cur = nullptr;
}

int AVL_Tree::GetBF(AVL_Node *Cur) {
    if (!Cur) return 0;
    return GetHeight(Cur->Left) - GetHeight(Cur->Right);
}

AVL_Node* AVL_Tree::LeftRotate(AVL_Node *cur) {
    AVL_Node *R = cur->Right;

    cur->Right = R->Left;
    R->Left = cur;

    cur->height = max(GetHeight(cur->Left), GetHeight(cur->Right)) + 1;
    R->height = max(GetHeight(R), GetHeight(R)) + 1;

    return R;
}

AVL_Node* AVL_Tree::RightRotate(AVL_Node *cur) {
    AVL_Node *L = cur->Left;

    cur->Left = L->Right;
    L->Right = cur;

    cur->height = max(GetHeight(cur->Left), GetHeight(cur->Right)) + 1;
    L->height = max(GetHeight(L), GetHeight(L)) + 1;

    return L;
}

AVL_Node* AVL_Tree::_Insert(AVL_Node *Cur, int &x) {

    if (!Cur) return (new AVL_Node(x));

    if (Cur->data > x)
        Cur->Left = _Insert(Cur->Left, x);
    else if (Cur->data < x)
        Cur->Right = _Insert(Cur->Right, x);
    else
        return Cur;

    Cur->height = max(GetHeight(Cur->Left), GetHeight(Cur->Right)) + 1;

    int BF = GetBF(Cur);

    if (BF > 1) {
        if (x < Cur->Left->data)
            return RightRotate(Cur);
        else if (x > Cur->Left->data) {
            Cur->Left = LeftRotate(Cur->Left);
            return RightRotate(Cur);
        }
    }

    if (BF < -1) {
        if (x > Cur->Right->data) {
            return LeftRotate(Cur);
        }
        else if (x < Cur->Right->data) {
            Cur->Right = RightRotate(Cur->Right);
            return LeftRotate(Cur);
        }
    }

    return Cur;
}

void AVL_Tree::Insert(int x) {
    Root = _Insert(Root, x);
}

void AVL_Tree::_Traversal(AVL_Node *Root, ofstream &fo) {
    if (!Root) return;
    _Traversal(Root->Left, fo);
    fo << Root->data << ' ';
    _Traversal(Root->Right, fo);
}

void AVL_Tree::Traversal(ofstream &fo) {
    _Traversal(Root, fo);
}

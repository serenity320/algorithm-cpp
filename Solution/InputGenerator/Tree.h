#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>

using namespace std;

struct Node
{
    int data;

    Node* left;
    Node* right;
};

string ConvertTree(int nodeNum, int rootNum);

#endif // TREE_H

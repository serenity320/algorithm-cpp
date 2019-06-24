#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;

    Node* left;
    Node* right;
};

Node* CreateNode(int data, Node* left, Node* right);
void FreeNodes(vector<Node*>& tree);

Node* SearchNode_Recursion(Node* root, int findData);
Node* SearchNode_Iteration(Node* root, int findData);

int main()
{
    int size = 7;

    vector<Node*> tree(size, nullptr);
    Node* root = nullptr;

    Node* findNode = nullptr;
    int findData = 5;

    tree[6] = CreateNode(6, nullptr, nullptr);
    tree[5] = CreateNode(4, nullptr, nullptr);
    tree[4] = CreateNode(2, nullptr, nullptr);
    tree[3] = CreateNode(0, nullptr, nullptr);
    tree[2] = CreateNode(5, tree[5], tree[6]);
    tree[1] = CreateNode(1, tree[3], tree[4]);
    tree[0] = CreateNode(3, tree[1], tree[2]);

    root = tree[0]; // Root Node

    //findNode = SearchNode_Recursion(root, findData);
    findNode = SearchNode_Iteration(root, findData);
    if (findNode != nullptr)
    {
        printf("%d이(가) 있습니다.\n", findNode->data);
    }
    else
    {
        printf("%d이(가) 없습니다.\n", findData);
    }

    FreeNodes(tree);

    return 0;
}

Node* CreateNode(int data, Node* left, Node* right)
{
    Node* node = reinterpret_cast<Node*>(malloc(sizeof(Node)));

    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

void FreeNodes(vector<Node*>& tree)
{
    for (auto node : tree)
    {
        free(node);
    }

    tree.clear();
}

Node* SearchNode_Recursion(Node* root, int findData)
{
    Node* result = nullptr;

    if (root != nullptr)
    {
        if (root->data > findData)
        {
            result = SearchNode_Recursion(root->left, findData);
        }
        else if (root->data < findData)
        {
            result = SearchNode_Recursion(root->right, findData);
        }
        else // root->data == findData
        {
            result = root;
        }
    }

    return result;
}

Node* SearchNode_Iteration(Node* root, int findData)
{
    Node* result = nullptr;

    Node* current = root;

    while (current != nullptr)
    {
        if (current->data > findData)
        {
            current = current->left;
        }
        else if (current->data < findData)
        {
            current = current->right;
        }
        else // current->data == findData
        {
            result = current;
            break;
        }
    }

    return result;
}

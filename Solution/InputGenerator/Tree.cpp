#include "Tree.h"

Node* CreateNode(int data, Node* left, Node* right);
void FreeNodes(vector<Node*>& tree);

void OutputTree(Node* root, string& output);

string ConvertTree(int nodeNum, int rootNum)
{
    int size = 0;

    vector<Node*> tree;
    Node* root = nullptr;

    scanf("%d", &size);

    tree.resize(nodeNum + 1, nullptr);

    for (int i = 0; i < size; i++)
    {
        int patent = 0;
        int left = 0;
        int right = 0;

        scanf("%d %d %d", &patent, &left, &right);

        if (tree[patent] == nullptr)
        {
            tree[patent] = CreateNode(patent, nullptr, nullptr);
        }

        if (left > 0)
        {
            tree[left] = CreateNode(left, nullptr, nullptr);
            tree[patent]->left = tree[left];
        }

        if (right > 0)
        {
            tree[right] = CreateNode(right, nullptr, nullptr);
            tree[patent]->right = tree[right];
        }
    }

    root = tree[rootNum];

    string result = "";
    OutputTree(root, result);

    FreeNodes(tree);

    return result;
}

Node* CreateNode(int data, Node* left, Node* right)
{
    Node* node = (Node*)malloc(sizeof(Node));

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

void OutputTree(Node* root, string& output)
{
    if (root != nullptr)
    {
        output += "(" + to_string(root->data) + ", ";

        OutputTree(root->left, output);

        output += ", ";

        OutputTree(root->right, output);

        output += ")";
    }
    else
    {
        output += "None";
    }
}

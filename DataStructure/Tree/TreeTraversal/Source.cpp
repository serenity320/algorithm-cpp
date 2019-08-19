#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
    int data;

    Node* left;
    Node* right;

    //bool isVisited;
};

Node* CreateNode(int data, Node* left, Node* right);
void FreeNodes(vector<Node*>& tree);

// [Depth First Traversal]
// https://en.wikipedia.org/wiki/Tree_traversal
void PreorderTraversal_Recursion(Node* root);   // Root-Left-Right
void InorderTraversal_Recursion(Node* root);    // Left-Root-Right
void PostorderTraversal_Recursion(Node* root);  // Left-Right-Root

void PreorderTraversal_Stack(Node* root);   // Root-Left-Right
void InorderTraversal_Stack(Node* root);    // Left-Root-Right
void PostorderTraversal_Stack(Node* head);  // Left-Right-Root

// [Breadth First Traversal]
void LevelOrderTraversal_Queue(Node* root);

int main()
{
    int size = 7;

    vector<Node*> tree(size, nullptr);
    Node* root = nullptr;

    tree[6] = CreateNode(6, nullptr, nullptr);
    tree[5] = CreateNode(5, nullptr, nullptr);
    tree[4] = CreateNode(4, nullptr, nullptr);
    tree[3] = CreateNode(3, nullptr, nullptr);
    tree[2] = CreateNode(2, tree[5], tree[6]);
    tree[1] = CreateNode(1, tree[3], tree[4]);
    tree[0] = CreateNode(0, tree[1], tree[2]);

    root = tree[0]; // Root Node

    printf("[전위(Preorder) 순회] - Recursion\n-> ");
    PreorderTraversal_Recursion(root);
    printf("\n\n");

    printf("[중위(Inorder) 순회] - Recursion\n-> ");
    InorderTraversal_Recursion(root);
    printf("\n\n");

    printf("[후위(Postorder) 순회] - Recursion\n-> ");
    PostorderTraversal_Recursion(root);
    printf("\n\n");

    printf("[전위(Preorder) 순회] - Stack(DFS)\n-> ");
    PreorderTraversal_Stack(root);
    printf("\n\n");

    printf("[중위(Inorder) 순회] - Stack\n-> ");
    InorderTraversal_Stack(root);
    printf("\n\n");

    printf("[후위(Postorder) 순회] - Stack\n-> ");
    PostorderTraversal_Stack(root);
    printf("\n\n");

    printf("[레벨(Level Order) 순회] - Queue(BFS)\n-> ");
    LevelOrderTraversal_Queue(root);
    printf("\n\n");

    FreeNodes(tree);

    return 0;
}

Node* CreateNode(int data, Node* left, Node* right)
{
    auto node = reinterpret_cast<Node*>(malloc(sizeof(Node)));

    if (node != nullptr)
    {
        node->data = data;

        node->left = left;
        node->right = right;

        //node->isVisited = false;
    }

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

// Root-Left-Right
void PreorderTraversal_Recursion(Node* root)
{
    if (root != nullptr)
    {
        printf("%d ", root->data);
        PreorderTraversal_Recursion(root->left);
        PreorderTraversal_Recursion(root->right);
    }
}

// Left-Root-Right
void InorderTraversal_Recursion(Node* root)
{
    if (root != nullptr)
    {
        InorderTraversal_Recursion(root->left);
        printf("%d ", root->data);
        InorderTraversal_Recursion(root->right);
    }
}

// Left-Right-Root
void PostorderTraversal_Recursion(Node* root)
{
    if (root != nullptr)
    {
        PostorderTraversal_Recursion(root->left);
        PostorderTraversal_Recursion(root->right);
        printf("%d ", root->data);
    }
}

// Root-Left-Right
void PreorderTraversal_Stack(Node* root)
{
    stack<Node*> stack;

    stack.push(root);

    while (!stack.empty())
    {
        Node* node = stack.top();
        stack.pop();

        printf("%d ", node->data);

        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
    }
}

// Left-Root-Right
void InorderTraversal_Stack(Node* root)
{
    stack<Node*> stack;

    Node* node = root;

    while (!stack.empty() || node != nullptr)
    {
        if (node != nullptr)
        {
            stack.push(node);

            node = node->left;
        }
        else
        {
            node = stack.top();
            stack.pop();

            printf("%d ", node->data);

            node = node->right;
        }
    }
}

// Left-Right-Root
void PostorderTraversal_Stack(Node* root)
{
    stack<Node*> stack;

    Node* node = root;
    Node* lastNode = nullptr;

    while (!stack.empty() || node != nullptr)
    {
        if (node != nullptr)
        {
            stack.push(node);

            node = node->left;
        }
        else
        {
            Node* top = stack.top();

            if (top->right != nullptr && top->right != lastNode)
            {
                node = top->right;
            }
            else
            {
                printf("%d ", top->data);

                lastNode = top;
                stack.pop();
            }
        }
    }
}

// isVisited Flag를 이용한 방법 (가능)
//void PostorderTraversal_Stack(Node* root)
//{
//    stack<Node*> stack;
//
//    stack.push(root);
//
//    while (!stack.empty())
//    {
//        Node* node = stack.top();
//
//        if (node->isVisited)
//        {
//            stack.pop();
//
//            printf("%d ", node->data);
//        }
//        else
//        {
//            node->isVisited = true;
//
//            if (node->right != nullptr)
//            {
//                stack.push(node->right);
//            }
//            if (node->left != nullptr)
//            {
//                stack.push(node->left);
//            }
//        }
//    }
//}

void LevelOrderTraversal_Queue(Node* root)
{
    queue<Node*> queue;

    queue.push(root);

    // [Level Order Traversal]
    while (!queue.empty())
    {
        Node* node = queue.front();
        queue.pop();

        printf("%d ", node->data);

        if (node->left != nullptr)
        {
            queue.push(node->left);
        }

        if (node->right != nullptr)
        {
            queue.push(node->right);
        }
    }
}

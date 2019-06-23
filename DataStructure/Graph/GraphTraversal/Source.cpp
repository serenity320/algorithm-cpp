#include <cstdio>
#include <stack>
#include <vector>
#include <queue>

#define VERTEX_MAX 10

using namespace std;

struct Node
{
    int vertex;
    Node* link;
};

struct Graph
{
    Node* adjList[VERTEX_MAX];
    bool isVisited[VERTEX_MAX];

    int size; // Vertex의 개수
};

Graph* CreateGraph();
void FreeGraph(Graph* graph);

void InsertVertex(Graph* graph, int v);
void InsertEdge(Graph* graph, int u, int v); // G(u, v)
void ResetVisitedNode(Graph* graph);

void DFS_Recursion(Graph* graph, int vertex); // Recursion
void DFS_Stack(Graph* graph, int vertex); // Stack
void BFS_Queue(Graph* graph, int vertex); // Queue

int main()
{
    Graph* graph = CreateGraph();
    int vertex = 8;

    for (int i = 0; i < vertex; i++)
    {
        InsertVertex(graph, i);
    }

    InsertEdge(graph, 0, 2);
    InsertEdge(graph, 0, 1);
    InsertEdge(graph, 1, 4);
    InsertEdge(graph, 1, 3);
    InsertEdge(graph, 1, 0);
    InsertEdge(graph, 2, 6);
    InsertEdge(graph, 2, 5);
    InsertEdge(graph, 2, 0);
    InsertEdge(graph, 3, 7);
    InsertEdge(graph, 3, 1);
    InsertEdge(graph, 4, 7);
    InsertEdge(graph, 4, 1);
    InsertEdge(graph, 5, 7);
    InsertEdge(graph, 5, 2);
    InsertEdge(graph, 6, 7);
    InsertEdge(graph, 6, 2);
    InsertEdge(graph, 7, 6);
    InsertEdge(graph, 7, 5);
    InsertEdge(graph, 7, 4);
    InsertEdge(graph, 7, 3);

    printf("[깊이 우선 탐색(DFS)] - Recursion\n");
    {
        ResetVisitedNode(graph);
        DFS_Recursion(graph, 0);
    }

    printf("\n");

    printf("[깊이 우선 탐색(DFS)] - Stack\n");
    {
        ResetVisitedNode(graph);
        DFS_Stack(graph, 0);
    }

    printf("\n");

    printf("[너비 우선 탐색(BFS)] - Queue\n");
    {
        ResetVisitedNode(graph);
        BFS_Queue(graph, 0);
    }

    printf("\n");

    FreeGraph(graph);

    return 0;
}

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->size = 0;

    for (int v = 0; v < VERTEX_MAX; v++)
    {
        graph->adjList[v] = nullptr;
        graph->isVisited[v] = false;
    }

    return graph;
}

void FreeGraph(Graph* graph)
{
    for (int v = 0; v <  graph->size; v++)
    {
        free(graph->adjList[v]);
    }

    free(graph);

    graph = nullptr;
}

void InsertVertex(Graph* graph, int v)
{
    if (graph->size + 1 < VERTEX_MAX)
    {
        graph->size++;
    }
    else
    {
        printf("그래프 점정의 개수 초과\n");
    }
}

void InsertEdge(Graph* graph, int u, int v)
{
    Node* node = nullptr;

    if (u < graph->size && v < graph->size)
    {
        node = (Node*)malloc(sizeof(Node));

        node->vertex = v;
        node->link = graph->adjList[u];
        graph->adjList[u] = node;
    }
}

void ResetVisitedNode(Graph* graph)
{
    for (int v = 0; v < graph->size; v++)
    {
        graph->isVisited[v] = false;
    }
}

void DFS_Recursion(Graph* graph, int vertex)
{
    graph->isVisited[vertex] = true;
    printf("%d ", vertex);

    for (Node* w = graph->adjList[vertex]; w != nullptr; w = w->link)
    {
        if (!graph->isVisited[w->vertex])
        {
            DFS_Recursion(graph, w->vertex);
        }
    }
}

void DFS_Stack(Graph* graph, int vertex)
{
    stack<int> stack;
    int v = vertex;

    stack.push(v);
    graph->isVisited[v] = true;

    printf("%d ", v);

    while (!stack.empty())
    {
        Node* w = graph->adjList[v];

        while (w != nullptr)
        {
            if (!graph->isVisited[w->vertex])
            {
                stack.push(w->vertex);
                graph->isVisited[w->vertex] = true;

                printf("%d ", w->vertex);

                v = w->vertex;
                w = graph->adjList[v];
            }
            else
            {
                w = w->link;
            }
        }

        v = stack.top();
        stack.pop();
    }
}

void BFS_Queue(Graph* graph, int vertex)
{
    queue<int> queue;
    int v = vertex;

    queue.push(v);
    graph->isVisited[v] = true;

    printf("%d ", v);

    while (!queue.empty())
    {
        v = queue.front();
        queue.pop();

        for (Node* w = graph->adjList[v]; w != nullptr; w = w->link)
        {
            if (!graph->isVisited[w->vertex])
            {
                queue.push(w->vertex);
                graph->isVisited[w->vertex] = true;

                printf("%d ", w->vertex);
            }
        }
    }
}

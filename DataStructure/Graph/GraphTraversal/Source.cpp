#include <cstdio>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct Graph
{
    vector<vector<int>> AdjList;
    vector<bool> IsVisited;

    size_t Size;

    Graph(size_t size)
    {
        AdjList.assign(size, vector<int>());
        IsVisited.assign(size, false);

        Size = size;
    }

    void AddEdge(int u, int v)
    {
        // G(u, v)
        AdjList[u].push_back(v);
    }

    void VisitVertex(int v)
    {        
        IsVisited[v] = true;
        printf("%d ", v);
    }

    void ResetIsVisited()
    {
        std::fill(IsVisited.begin(), IsVisited.end(), false);
    }
};

void DFS_Recursion(Graph& graph, int source); // Recursion
void DFS_Stack(Graph& graph, int source); // Stack
void BFS_Queue(Graph& graph, int source); // Queue

int main()
{
    int vertex = 8;
    Graph graph(vertex);

    graph.AddEdge(0, 2);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 4);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 0);
    graph.AddEdge(2, 6);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 0);
    graph.AddEdge(3, 7);
    graph.AddEdge(3, 1);
    graph.AddEdge(4, 7);
    graph.AddEdge(4, 1);
    graph.AddEdge(5, 7);
    graph.AddEdge(5, 2);
    graph.AddEdge(6, 7);
    graph.AddEdge(6, 2);
    graph.AddEdge(7, 6);
    graph.AddEdge(7, 5);
    graph.AddEdge(7, 4);
    graph.AddEdge(7, 3);

    //for (int i = 0; i < graph.size; i++)
    //{
    //    std::reverse(graph.adjList[i].begin(), graph.adjList[i].end());
    //}

    printf("[±íÀÌ ¿ì¼± Å½»ö(DFS)] - Recursion\n");
    {
        graph.ResetIsVisited();
        DFS_Recursion(graph, 0);
    }

    printf("\n");

    printf("[±íÀÌ ¿ì¼± Å½»ö(DFS)] - Stack\n");
    {
        graph.ResetIsVisited();
        DFS_Stack(graph, 0);
    }

    printf("\n");

    printf("[³Êºñ ¿ì¼± Å½»ö(BFS)] - Queue\n");
    {
        graph.ResetIsVisited();
        BFS_Queue(graph, 0);
    }

    printf("\n");

    return 0;
}

void DFS_Recursion(Graph& graph, int source)
{
    graph.VisitVertex(source);

    for (auto w : graph.AdjList[source])
    {
        if (!graph.IsVisited[w])
        {
            DFS_Recursion(graph, w);
        }
    }
}

void DFS_Stack(Graph& graph, int source)
{
    stack<int> stack;
    int v = source;

    stack.push(v);
    graph.VisitVertex(v);

    while (!stack.empty())
    {
        auto adjList = graph.AdjList[v].begin();

        while (adjList != graph.AdjList[v].end())
        {
            int w = *adjList;

            if (!graph.IsVisited[w])
            {
                stack.push(w);
                graph.VisitVertex(w);

                v = w;

                adjList = graph.AdjList[v].begin();
            }
            else
            {
                ++adjList; // next
            }
        }

        v = stack.top();
        stack.pop();
    }
}

void BFS_Queue(Graph& graph, int source)
{
    queue<int> queue;
    int v = source;

    queue.push(v);
    graph.VisitVertex(v);

    while (!queue.empty())
    {
        v = queue.front();
        queue.pop();

        for (auto w : graph.AdjList[v])
        {
            if (!graph.IsVisited[w])
            {
                queue.push(w);
                graph.VisitVertex(w);
            }
        }
    }
}

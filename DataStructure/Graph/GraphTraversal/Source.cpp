#include <cstdio>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct Graph
{
    vector<vector<int>> AdjList;
    vector<bool> IsVisited;

    size_t Size; // Vertex °³¼ö

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
    // [Source Vetex]
    {
        graph.IsVisited[source] = true;

        printf("%d ", source);
    }

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
    int u = source;

    // [Source Vetex]
    {
        graph.IsVisited[u] = true;
        stack.push(u);

        printf("%d ", u);
    }

    while (!stack.empty())
    {
        auto adjList = graph.AdjList[u].begin();

        while (adjList != graph.AdjList[u].end())
        {
            // <u, v>
            int v = *adjList;

            if (!graph.IsVisited[v])
            {
                graph.IsVisited[v] = true;
                stack.push(v);

                printf("%d ", v);

                u = v;
                adjList = graph.AdjList[u].begin();
            }
            else
            {
                ++adjList; // next
            }
        }

        u = stack.top();
        stack.pop();
    }
}

void BFS_Queue(Graph& graph, int source)
{
    queue<int> queue;
    int u = source;

    // [Source Vetex]
    {
        printf("%d ", u);

        graph.IsVisited[u] = true;
        queue.push(u);
    }

    while (!queue.empty())
    {
        u = queue.front();
        queue.pop();

        for (auto v : graph.AdjList[u])
        {
            // <u, v>
            if (!graph.IsVisited[v])
            {
                printf("%d ", v);

                graph.IsVisited[v] = true;
                queue.push(v);
            }
        }
    }
}

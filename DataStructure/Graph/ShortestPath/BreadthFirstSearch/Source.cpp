#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct AdjListGraph
{
    int Infinity = std::numeric_limits<int>::max();

    vector<vector<int>> AdjList; // <weight>
    vector<bool> IsVisited;

    size_t Size; // Vertex 개수
    bool IsDirected; // 방향 그래프 여부

    AdjListGraph(size_t size, bool isDirected)
    {
        AdjList.assign(size, vector<int>());
        IsVisited.assign(size, false);

        Size = size;
        IsDirected = isDirected;
    }

    void AddEdge(int u, int v)
    {
        if (IsDirected)
        {
            // 방향 그래프
            // (u, v) w
            AdjList[u].push_back(v);
        }
        else
        {
            // 무방향 그래프
            // <u, v>, <v, u> w
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
    }
};

// [BFS : Breadth-First Search]
// 음수 가중치가 없다고 가정
vector<int64_t> BFS_Queue(AdjListGraph& graph, int source); // O(N)

int main()
{
    int V = 0; // Vertex 개수
    int E = 0; // Edge 개수
    int source = 0; // 시작 Vertex 번호

    // [input.txt]
    scanf("%d %d", &V, &E);
    scanf("%d", &source);

    vector<vector<int>> input(E, vector<int>(2, 0));

    for (int i = 0; i < E; i++)
    {
        // u, v
        scanf("%d %d", &input[i][0], &input[i][1]);
    }

    printf("\n");

    printf("[BFS : Breadth-First Search]\n");
    {
        AdjListGraph graph(V, false);

        // Graph 정점 연결
        for (int i = 0; i < E; i++)
        {
            int u = input[i][0];
            int v = input[i][1];

            graph.AddEdge(u, v);
        }

        // Dijkstra Algorithm
        auto distance = BFS_Queue(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            int destination = i; // 0이 아닌 1번 정점부터 시작할 경우 1을 더함

            printf("%d -> %d : ", source, destination);

            if (distance[i] != graph.Infinity)
            {
                printf("%lld\n", distance[i]);
            }
            else
            {
                printf("INFINITY\n");
            }
        }
    }

    return 0;
}

vector<int64_t> BFS_Queue(AdjListGraph& graph, int source)
{
    vector<int64_t> distance(graph.Size, graph.Infinity);

    queue<int> queue;
    int u = source;

    // [Source Vetex]
    {
        distance[u] = 0;

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
                distance[v] = distance[u] + 1;

                graph.IsVisited[v] = true;
                queue.push(v);
            }
        }
    }

    return distance;
}

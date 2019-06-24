#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct AdjMaxtrixGraph
{
    int Infinity = std::numeric_limits<int>::max();

    vector<vector<int>> AdjMaxtrix;
    vector<bool> IsVisited;

    size_t Size;
    bool IsDirected; // 방향 그래프 여부

    AdjMaxtrixGraph(size_t size, bool isDirected)
    {
        AdjMaxtrix.assign(size, vector<int>(size, Infinity));
        IsVisited.assign(size, false);

        Size = size;
        IsDirected = isDirected;

        // Graph 초기화
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    // 같은 정점은 Weight가 0
                    AdjMaxtrix[i][j] = 0;
                }
            }
        }
    }

    void AddEdge(int u, int v, int w)
    {
        if (IsDirected)
        {
            // 방향 그래프
            // (u, v) = w
            AdjMaxtrix[u][v] = w;
        }
        else
        {
            // 무방향 그래프
            // <u, v>, <v, u> = w
            AdjMaxtrix[u][v] = w;
            AdjMaxtrix[v][u] = w;
        }
    }
};

struct AdjListGraph
{
    int Infinity = std::numeric_limits<int>::max();

    vector<vector<pair<int, int>>> AdjList;
    vector<bool> IsVisited;

    size_t Size;
    bool IsDirected; // 방향 그래프 여부

    AdjListGraph(size_t size, bool isDirected)
    {
        AdjList.assign(size, vector<pair<int, int>>());
        IsVisited.assign(size, false);

        Size = size;
        IsDirected = isDirected;
    }

    void AddEdge(int u, int v, int w)
    {
        if (IsDirected)
        {
            // 방향 그래프
            // (u, v) = w
            AdjList[u].push_back(make_pair(v, w));
        }
        else
        {
            // 무방향 그래프
            // <u, v>, <v, u> = w
            AdjList[u].push_back(make_pair(v, w));
            AdjList[v].push_back(make_pair(u, w));
        }
    }
};

// [Dijkstra 알고리즘]
// - 음수 가중치가 없다고 가정
vector<int64_t> Dijkstra_GreedyAlgorithm(AdjMaxtrixGraph& graph, int source); // O(N^2)
vector<int64_t> Dijkstra_PriorityQueue(AdjListGraph& graph, int source); // O(M + NlogN)

int main()
{
    int V = 0; // Vertex 개수
    int E = 0; // Edge 개수
    int S = 0; // 시작 Vertex 번호

    // [input.txt]
    scanf("%d %d", &V, &E);
    scanf("%d", &S);

    vector<vector<int>> input(E, vector<int>(3, 0));

    for (int i = 0; i < E; i++)
    {
        // u, v, w
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }

    printf("[Dijkstra] - Greedy Algorithm\n");
    {
        AdjMaxtrixGraph graph(V, true);

        // Graph 정점 연결
        for (int i = 0; i < E; i++)
        {
            int u = input[i][0] - 1;
            int v = input[i][1] - 1;
            int w = input[i][2];

            graph.AddEdge(u, v, w);
        }

        // 0이 아닌 1번 정점부터 시작할 경우 -1을 더함
        int source = S - 1;

        // Dijkstra Algorithm
        auto distance = Dijkstra_GreedyAlgorithm(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            // 0이 아닌 1번 정점부터 시작할 경우 1을 더함
            int destination = i + 1;

            printf("%d -> %d : ", S, destination);

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

    printf("\n");

    printf("[Dijkstra] - Priority Queue\n");
    {
        AdjListGraph graph(V, true);

        // Graph 정점 연결
        for (int i = 0; i < E; i++)
        {
            int u = input[i][0] - 1;
            int v = input[i][1] - 1;
            int w = input[i][2];

            graph.AddEdge(u, v, w);
        }

        // 0이 아닌 1번 정점부터 시작할 경우 -1을 더함
        int source = S - 1;

        // Dijkstra Algorithm
        auto distance = Dijkstra_PriorityQueue(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            int destination = i + 1; // 0이 아닌 1번 정점부터 시작할 경우 1을 더함

            printf("%d -> %d : ", S, destination);

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

vector<int64_t> Dijkstra_GreedyAlgorithm(AdjMaxtrixGraph& graph, int source)
{
    vector<int64_t> distance(graph.Size, graph.Infinity);
    //vector<int> parentVertex(graph.Size, -1);

    distance[source] = 0;

    for (int i = 0; i < graph.Size; i++)
    {
        int u = -1;
        int64_t minDistance = graph.Infinity;

        for (int v = 0; v < graph.Size; v++)
        {
            // 방문하지 않은 정점 중에 최단 거리(다음에 방문할 정점)
            if (!graph.IsVisited[v] && minDistance >= distance[v])
            {
                minDistance = distance[v];
                u = v;
            }
        }

        if (u >= 0)
        {
            // 다음에 방문할 정점(Vertex)
            graph.IsVisited[u] = true;

            // 방문할 정점과 연결된 정점들의 가중치를 바탕으로 거리 갱신
            for (int v = 0; v < graph.Size; v++)
            {
                int64_t sumDistance = distance[u] + graph.AdjMaxtrix[u][v];

                // Minumum Distance
                if (!graph.IsVisited[v] && distance[v] > sumDistance)
                {
                    distance[v] = sumDistance;
                    //parentVertex[vertex] = u;
                }
            }
        }
    }

    return distance;
}

vector<int64_t> Dijkstra_PriorityQueue(AdjListGraph& graph, int source)
{
    vector<int64_t> distance(graph.Size, graph.Infinity);
    //vector<int> parentVertex(graph.Size, -1);

    // 오름차순으로 거리를 정렬하여 최단 거리의 정점부터 찾음 (greater<Dijkstra>)
    typedef pair<int64_t, int> Dijkstra; // <distance, vertex>
    priority_queue<Dijkstra, vector<Dijkstra>, greater<Dijkstra>> queue;

    distance[source] = 0;

    queue.push(make_pair(0, source));

    while (!queue.empty())
    {
        auto top = queue.top();
        queue.pop();

        int64_t w = top.first;
        int u = top.second;

        graph.IsVisited[u] = true;

        // 현재 점정(vertex)보다 짧은 경로가 없을 때만 확인
        if (distance[u] >= w)
        {
            for (auto v : graph.AdjList[u])
            {
                int vertex = v.first;
                int64_t weight = w + v.second;

                // 최단 경로가 있으면, 정점들의 가중치를 바탕으로 거리 갱신(우선순위 큐에 Push)
                if (!graph.IsVisited[vertex] && distance[vertex] > weight)
                {
                    distance[vertex] = weight;
                    //parentVertex[vertex] = u;

                    queue.push(make_pair(weight, vertex));
                }
            }
        }
    }

    return distance;
}

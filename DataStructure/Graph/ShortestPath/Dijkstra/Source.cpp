#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct AdjMatrixGraph
{
    int Infinity = std::numeric_limits<int>::max();

    vector<vector<int>> AdjMatrix;
    vector<bool> IsVisited;

    size_t Size; // Vertex 개수
    bool IsDirected; // 방향 그래프 여부

    AdjMatrixGraph(size_t size, bool isDirected)
    {
        AdjMatrix.assign(size, vector<int>(size, Infinity));
        IsVisited.assign(size, false);

        Size = size;
        IsDirected = isDirected;

        // Graph 초기화
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (i == j)
                {
                    // 같은 정점은 Weight가 0
                    AdjMatrix[i][j] = 0;
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
            AdjMatrix[u][v] = w;
        }
        else
        {
            // 무방향 그래프
            // <u, v>, <v, u> = w
            AdjMatrix[u][v] = w;
            AdjMatrix[v][u] = w;
        }
    }
};

struct AdjListGraph
{
    int Infinity = std::numeric_limits<int>::max();

    vector<vector<pair<int, int64_t>>> AdjList; // <vertex, weight>
    vector<bool> IsVisited;

    size_t Size; // Vertex 개수
    bool IsDirected; // 방향 그래프 여부

    AdjListGraph(size_t size, bool isDirected)
    {
        AdjList.assign(size, vector<pair<int, int64_t>>());
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
// 음수 가중치가 없다고 가정
// https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
vector<int64_t> Dijkstra_GreedyAlgorithm(AdjMatrixGraph& graph, int source); // O(N^2)
vector<int64_t> Dijkstra_PriorityQueue(AdjListGraph& graph, int source); // O(M + NlogN)

int main()
{
    int V = 0; // Vertex 개수
    int E = 0; // Edge 개수
    int source = 0; // 시작 Vertex 번호

    // [input.txt]
    scanf("%d %d", &V, &E);
    scanf("%d", &source);

    vector<vector<int>> input(E, vector<int>(3, 0));

    for (int i = 0; i < E; i++)
    {
        // u, v, w
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }

    printf("[Dijkstra] - Greedy Algorithm\n");
    {
        AdjMatrixGraph graph(V, true); // 방향 그래프

        // Graph 정점 연결
        for (int i = 0; i < E; i++)
        {
            int u = input[i][0];
            int v = input[i][1];
            int w = input[i][2];

            graph.AddEdge(u, v, w);
        }

        // Dijkstra Algorithm
        auto distance = Dijkstra_GreedyAlgorithm(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            int destination = i;

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

    printf("\n");

    printf("[Dijkstra] - Priority Queue\n");
    {
        AdjListGraph graph(V, true); // 방향 그래프

        // Graph 정점 연결
        for (int i = 0; i < E; i++)
        {
            int u = input[i][0];
            int v = input[i][1];
            int w = input[i][2];

            graph.AddEdge(u, v, w);
        }

        // Dijkstra Algorithm
        auto distance = Dijkstra_PriorityQueue(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            int destination = i;

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

vector<int64_t> Dijkstra_GreedyAlgorithm(AdjMatrixGraph& graph, int source)
{
    vector<int64_t> distance(graph.Size, graph.Infinity);
    //vector<int> parentVertex(graph.Size, -1);

    // [Source Vetex]
    {
        distance[source] = 0;
        //parentVertex[source] -1;
    }

    for (size_t i = 0; i < graph.Size - 1; i++)
    {
        int u = -1;
        int64_t minDistance = graph.Infinity;

        // 방문하지 않은 정점 중에 최단 거리
        //for (size_t v = 0; v < graph.Size; v++)
        for (int v = graph.Size - 1; v >= 0; v--)
        {
            if (!graph.IsVisited[v] && minDistance >= distance[v])
            {
                minDistance = distance[v];
                u = v; // 다음에 방문할 정점
            }
        }

        if (u >= 0)
        {
            graph.IsVisited[u] = true;

            // <u, v>
            for (size_t v = 0; v < graph.Size; v++)
            {
                // graph.AdjMatrix[u][v] > 0 : 같은 정점(Weight가 0)이 아닌 경우
                if (graph.AdjMatrix[u][v] > 0 && distance[u] < graph.Infinity)
                {
                    int64_t sumDistance = distance[u] + graph.AdjMatrix[u][v];

                    // 방문할 정점과 연결된 정점들의 가중치를 바탕으로 거리 갱신
                    if (!graph.IsVisited[v] && distance[v] > sumDistance)
                    {
                        distance[v] = sumDistance;
                        //parentVertex[v] u;
                    }
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

    // 오름차순(greater<Dijkstra>)으로 거리를 정렬하여 최단 거리의 정점부터 찾음
    typedef pair<int64_t, int> Dijkstra; // <distance, vertex>
    priority_queue<Dijkstra, vector<Dijkstra>, greater<Dijkstra>> queue;

    // [Source Vetex]
    {
        distance[source] = 0;
        //parentVertex[source] -1;

        queue.push(make_pair(0, source));
    }

    while (!queue.empty())
    {
        auto top = queue.top();
        queue.pop();

        int u = top.second;
        int64_t w = top.first; // distance[u]

        // 최단 경로를 구하는 것이므로 방문 확인을 안함
        //graph.IsVisited[u] = true;

        // <u, v>
        for (auto vertex : graph.AdjList[u])
        {
            int v = vertex.first;
            int64_t weight = w + vertex.second;

            // 최단 경로가 있으면 정점들의 가중치를 바탕으로 거리 갱신
            if (distance[v] > weight)
            {
                distance[v] = weight;
                //parentVertex[v] u;

                queue.push(make_pair(distance[v], v));
            }
        }
    }

    return distance;
}

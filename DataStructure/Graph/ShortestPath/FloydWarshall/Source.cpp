#include <cstdio>
#include <vector>
#include <algorithm>

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
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
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
            // (u, v) w
            AdjMatrix[u][v] = w;
        }
        else
        {
            // 무방향 그래프
            // <u, v>, <v, u> w
            AdjMatrix[u][v] = w;
            AdjMatrix[v][u] = w;
        }
    }
};

// [Floyd-Warshall 알고리즘]
// 음수 사이클 없다고 가정
vector<vector<int64_t>> FloydWarshall_GreedyAlgorithm(AdjMatrixGraph& graph, int source); // O(N^3)

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
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }

    printf("[Floyd-Warshall] - Greedy Algorithm\n");
    {
        AdjMatrixGraph graph(V, true);

        // Graph 정점 연결
        for (int i = 0; i < E; i++)
        {
            int u = input[i][0];
            int v = input[i][1];
            int w = input[i][2];

            graph.AddEdge(u, v, w);
        }

        // Floyd-Warshall Algorithm
        auto distance = FloydWarshall_GreedyAlgorithm(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            int destination = i;

            printf("%d -> %d : ", source, destination);

            if (distance[source][i] < graph.Infinity)
            {
                printf("%lld\n", distance[source][i]);
            }
            else
            {
                printf("INFINITY\n");
            }
        }

        printf("\n");

        // 최단 거리 출력(인접 행렬)
        printf("▶ 전체 최단 거리 (인접 행렬)\n");

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (distance[i][j] == graph.Infinity)
                {
                    printf("%3s", "∞");
                }
                else
                {
                    printf("%3lld", distance[i][j]);
                }
            }

            printf("\n");
        }
    }

    return 0;
}

vector<vector<int64_t>> FloydWarshall_GreedyAlgorithm(AdjMatrixGraph& graph, int source)
{
    vector<vector<int64_t>> distance(graph.Size, vector<int64_t>(graph.Size, graph.Infinity));

    // Distance 초기화
    for (int i = 0; i < graph.Size; i++)
    {
        for (int j = 0; j < graph.Size; j++)
        {
            distance[i][j] = graph.AdjMatrix[i][j];
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < graph.Size; k++)
    {
        for (int i = 0; i < graph.Size; i++)
        {
            for (int j = 0; j < graph.Size; j++)
            {
                int64_t sum = distance[i][k] + distance[k][j];

                distance[i][j] = std::min(distance[i][j], sum);
            }
        }
    }

    return distance;
}

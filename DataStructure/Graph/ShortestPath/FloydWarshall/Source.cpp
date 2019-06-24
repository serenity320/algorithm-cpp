#include <cstdio>
#include <vector>

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

// [Floyd-Warshall 알고리즘]
// - 음수 사이클 없다고 가정
vector<vector<int64_t>> FloydWarshall_GreedyAlgorithm(AdjMaxtrixGraph& graph, int source); // O(N^3)

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
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }

    printf("[Floyd-Warshall] - Greedy Algorithm\n");
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
        auto distance = FloydWarshall_GreedyAlgorithm(graph, source);

        // Shortest Path 출력
        for (int i = 0; i < V; i++)
        {
            // 0이 아닌 1번 정점부터 시작할 경우 1을 더함
            int destination = i + 1;

            printf("%d -> %d : ", S, destination);

            if (distance[source][i] != graph.Infinity)
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
                    printf("%3s\n", "∞");
                }
                else
                {
                    printf("%3lld\n", distance[i][j]);
                }
            }
        }
    }

    return 0;
}

vector<vector<int64_t>> FloydWarshall_GreedyAlgorithm(AdjMaxtrixGraph& graph, int source)
{
    vector<vector<int64_t>> distance(graph.Size, vector<int64_t>(graph.Size, graph.Infinity));

    // Distance 초기화
    for (int i = 0; i < graph.Size; i++)
    {
        for (int j = 0; j < graph.Size; j++)
        {
            distance[i][j] = graph.AdjMaxtrix[i][j];
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

                // Minumum Distance
                if (distance[i][j] > sum)
                {
                    distance[i][j] = sum;
                }
            }
        }
    }

    return distance;
}

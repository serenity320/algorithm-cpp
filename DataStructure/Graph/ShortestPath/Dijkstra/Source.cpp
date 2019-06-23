#include <cstdio>
#include <vector>
#include <queue>

#define INFINITY 0x7FFFFFFF

using namespace std;

// [Dijkstra 알고리즘]
// - 음수 가중치가 없다고 가정
void Dijkstra_GreedyAlgorithm(int V, int E, int source, vector<vector<int>>& input); // O(N^2)
void Dijkstra_PriorityQueue(int V, int E, int source, vector<vector<int>>& input); // O(M + NlogN)

int main()
{
    int countV = 0;
    int countE = 0;
    int source = 0;
    vector<vector<int>> input;

    // [input.txt]
    scanf("%d %d", &countV, &countE);
    scanf("%d", &source);

    input.resize(countE, vector<int>(3, 0));

    for (int i = 0; i < countE; i++)
    {
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }

    printf("[Dijkstra] - Greedy Algorithm\n");
    {
        Dijkstra_GreedyAlgorithm(countV, countE, source, input); 
    }

    printf("\n");

    printf("[Dijkstra] - Priority Queue\n");
    {
        Dijkstra_PriorityQueue(countV, countE, source, input);
    }

    return 0;
}

void Dijkstra_GreedyAlgorithm(int V, int E, int source, vector<vector<int>>& input)
{
    vector<vector<int>> adjMaxtrix;
    vector<int64_t> distance;
    vector<bool> isVisited;

    int sourceIdx = source - 1; // 0이 아닌 1번 정점부터 시작할 경우 -1을 더함

    adjMaxtrix.resize(V, vector<int>(V, INFINITY));
    distance.resize(V, INFINITY);
    isVisited.resize(V, false);

    // Graph 초기화
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
            {
                // 같은 정점은 Weight가 0
                adjMaxtrix[i][j] = 0;
            }
        }
    }

    // Graph 정점 연결
    for (int i = 0; i < E; i++)
    {
        int u = input[i][0] - 1;
        int v = input[i][1] - 1;
        int w = input[i][2];

        // 방향 그래프 (u, v) = w
        adjMaxtrix[u][v] = w;

        // 무방향 그래프 <u, v>, <v, u> = w
        //adjMaxtrix[u][v] = w;
        //adjMaxtrix[v][u] = w;
    }

    // Dijkstra
    distance[sourceIdx] = 0;

    for (int i = 0; i < V; i++)
    {
        int u = -1;
        int64_t minDist = INFINITY;

        for (int v = 0; v < V; v++)
        {
            // 방문하지 않은 정점 중에 최단 거리(다음에 방문할 정점)
            if (!isVisited[v] && minDist >= distance[v])
            {
                minDist = distance[v];
                u = v;
            }
        }

        if (u >= 0)
        {
            // 다음에 방문할 정점(Vertex)
            isVisited[u] = true;

            // 방문할 정점과 연결된 정점들의 가중치를 바탕으로 거리 갱신
            for (int v = 0; v < V; v++)
            {
                int64_t sumDist = distance[u] + adjMaxtrix[u][v];

                // Minumum
                if (!isVisited[v] && distance[v] > sumDist)
                {
                    distance[v] = sumDist;
                }
            }
        }
    }

    // Shortest Path 출력
    for (int i = 0; i < V; i++)
    {
        // 0이 아닌 1번 정점부터 시작할 경우 1을 더함
        int destination = i + 1;

        printf("%d -> %d : ", source, destination);

        if (distance[i] != INFINITY)
        {
            printf("%lld\n", distance[i]);
        }
        else
        {
            printf("INFINITY\n");
        }
    }
}

void Dijkstra_PriorityQueue(int V, int E, int source, vector<vector<int>>& input)
{
    typedef pair<int64_t, int> Dijkstra;

    // 오름차순으로 거리를 정렬하여 최단 거리의 정점부터 찾음 (greater<Dijkstra>)
    priority_queue<Dijkstra, vector<Dijkstra>, greater<Dijkstra>> queue;

    vector<vector<pair<int, int>>> adjList(V);
    vector<int64_t> distance(V, INFINITY);

    int sourceIdx = source - 1; // 0이 아닌 1번 정점부터 시작할 경우 -1을 더함

    // 그래프 연결
    for (int i = 0; i < E; i++)
    {
        int u = input[i][0] - 1;
        int v = input[i][1] - 1;
        int w = input[i][2];

        // 방향 그래프 (u, v) = w
        adjList[u].push_back(make_pair(v, w));

        // 무방향 그래프 <u, v>, <v, u> = w
        //adjList[u].push_back(make_pair(v, w));
        //adjList[v].push_back(make_pair(u, w));
    }

    // Dijkstra
    distance[sourceIdx] = 0;

    queue.push(make_pair(0, sourceIdx));

    while (!queue.empty())
    {
        int64_t w = queue.top().first;
        int u = queue.top().second;

        queue.pop();

        // 현재 점정(vertex)보다 짧은 경로가 없을 때만 확인
        if (distance[u] >= w)
        {
            for (int v = 0; v < adjList[u].size(); v++)
            {
                int vertex = adjList[u][v].first;
                int64_t weight = w + adjList[u][v].second;

                // 최단 경로가 있으면, 정점들의 가중치를 바탕으로 거리 갱신(우선순위 큐에 Push)
                if (distance[vertex] > weight)
                {
                    distance[vertex] = weight;

                    queue.push(make_pair(weight, vertex));
                }
            }
        }
    }

    // Shortest Path 출력
    for (int i = 0; i < V; i++)
    {
        int destination = i + 1; // 0이 아닌 1번 정점부터 시작할 경우 1을 더함

        printf("%d -> %d : ", source, destination);

        if (distance[i] != INFINITY)
        {
            printf("%lld\n", distance[i]);
        }
        else
        {
            printf("INFINITY\n");
        }
    }
}

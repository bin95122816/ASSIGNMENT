#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int rear;
} Node;

Node graph[MAX];
int visited[MAX];
int parent[MAX];

void add(int n, int m)
{
    graph[n].data[graph[n].rear++] = m;
    graph[m].data[graph[m].rear++] = n;
}

void dfs(int current)
{
    visited[current] = 1; //방문 처리

    for (int i = 0; i < graph[current].rear; i++) //현재 접근한 노드의 연결된 노드들에 차례로 접근
    {
        int next = graph[current].data[i]; //연결된 노드들 중 차례로 저장 (if 1번 노드와 연결된 6, 4 중에 연결

        if (!visited[next]) //만약 해당 노드를 아직 방문하지 않은 상태이면
        {
            parent[next] = current; //parent[6] = 1 -> parent[3] = 6 -> parent[5] = 3 ->  parent[4]=1 -> parent[2]=4 -> parent[7]=4 ->
            dfs(next); //6번 노드와 연결된 노드을에 접근 ( 1, 3인데 1은 방문 상태이므로 3만 접근 )
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        graph[i].rear = 0;
        visited[i] = 0;
        parent[i] = 0;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        add(n, m);
    }

    dfs(1);

    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", parent[i]);
    }

    return 0;
}
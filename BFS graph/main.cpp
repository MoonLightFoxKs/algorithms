#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> Queue;
    const int N = 7;
    int visited[N];
    int A[N][N]= { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
        { 1, 0, 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0 } };
    int pr[N];
    int start;
    for (int i = 0; i < 7; i++)
        visited[i] = 0;
    cout<<"введите начальную вершину ";
    cin>>start;
    Queue.push(start);
    visited[start] = 1;
    pr[start] = -1;
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && A[node][i])
            {
                Queue.push(i);
                visited[i] = 1;
                pr[i] = node;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout<<pr[i]<<" ";
    }
    
    cout<<endl<<"введите конечную вершину ";
    int konch;
    cin>>konch;
    cout<<"путь: "<<endl;
    for (int i=konch;pr[i]!=-1;)
    {
        cout<<pr[i]<<endl;
        i = pr[i];
    }
    return 0;
}

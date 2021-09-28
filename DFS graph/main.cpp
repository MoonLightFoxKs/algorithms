#include <iostream>
using namespace std;

const int N = 7;
int visited[N]={0,0,0,0,0,0,0};
int A[N][N]= { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
    { 1, 0, 1, 1, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0 } };
int pr[N];
int start;


void go(int a){
    visited[a] = 1; // ставим метку, что посетили данную вершину
    for (int i = 0; i<N; i++){ // проходим по всем вершинам
        if (!visited[i] && A[a][i] ){ // если вершине не пройдена и инцидентна данной
            pr[i]=a; // записываем предшествующую 
            go(i); // запускаемся из нее
        }
    }
}



int main()
{
    cout<<"введите начальную вершину ";
    cin>>start;
    pr[start] = -1;
    go(start);
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

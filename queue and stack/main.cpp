#include <iostream>
using namespace std;

class stek{
private:
    int var;
    int K;
    int S;
    int *mas;

public:
    stek() {
     S = 5;
     var = -1;
     mas = new int[S];
    }
    
    stek(int n) {
     S = n;
     var = -1;
     mas = new int[S];
    }
    
    ~stek() {
     delete[] mas;
    }
    
    void input() {
     if (var >= S-1) cout << "!Full!"<<endl;
     else {
        var++;
        cout << "Enter element ";
        cin >> K;
        mas[var] = K;
     }
    }
    
    void output() {
        if (var < 0) cout << "Empty("<<endl;
     else {
        K = mas[var];
        cout <<K<<endl;
        var--;
     }
    }
};


class queue{
private:
    int N;
    int K;
    int v;
    int t;
    int *mas;

public:
    queue(int n1){
        t = n1;
        N = 0;
        K = 0;
        mas = new int[t];
    }
    
    ~queue(){
        delete[] mas;
    }
    
    void input(){
        if (((K+1) % t)!= N){
            cout << "Enter element ";
            cin >> v;
            mas[K] = v;
            K = (K + 1) % t;
        }
        else cout << "!Full queue!"<<endl;
    }
    
    void output(){
        if (K!=N) {
            cout << mas[N] << endl;
            N = (N + 1) % t;
        }
        else {
            cout << "Empty queue(" << endl;
        }
    }
};


int main() {
    stek s(4);
    for(int i=0;i<4;i++)
     s.input();
    for(int i=0;i<5;i++)
     s.output();
    
    queue q(3);
    q.input();
    q.input();
    q.output();
    q.input();
    q.output();
}

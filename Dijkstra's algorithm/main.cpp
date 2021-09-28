#include <cstdlib>
#include <iostream>
#include <iomanip>
#define SIZE 6
using namespace std;

int main()
{
    int DUG[SIZE][SIZE]; // матрица связей
    int MIN_WEG[SIZE]; // минимальное расстояние
    int FIKS[SIZE]; // посещенные вершины
    int temp;
    int minindex, min;
    // Инициализация матрицы связей
    for (int i = 0; i < SIZE; i++)
    {
        DUG[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            cout<<"Введите расстояние "<<i + 1 <<" - "<<j + 1<<": ";
            cin>>temp;
            DUG[i][j] = temp;
            DUG[j][i] = temp;
        }
    }
    cout << endl;
    // Вывод матрицы связей
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout<<setw(7)<<DUG[i][j];
        cout<<endl;
    }
    //Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++)
    {
        MIN_WEG[i] = 10000;
        FIKS[i] = 1;
    }
    MIN_WEG[0] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((FIKS[i] == 1) && (MIN_WEG[i] < min))
            { // Переприсваиваем значения
                min = MIN_WEG[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (DUG[minindex][i] > 0)
                {
                    temp = min + DUG[minindex][i];
                    if (temp < MIN_WEG[i])
                    {
                        MIN_WEG[i] = temp;
                    }
                }
            }
            FIKS[minindex] = 0;
        }
    } while (minindex < 10000);
    // Вывод кратчайших расстояний до вершин
    cout<<"\nКратчайшие расстояния до вершин:"<<endl;
    for (int i = 0; i < SIZE; i++)
        cout<<setw(4)<<MIN_WEG[i];
    cout<<endl;
    // Восстановление пути
    int ver[SIZE]; // массив посещенных вершин
    int end = 4; // индекс конечной вершины = 5 - 1
    ver[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = MIN_WEG[end]; // вес конечной вершины
    
    while (end > 0) // пока не дошли до начальной вершины
    {
        for (int i = 0; i < SIZE; i++) // просматриваем все вершины
            if (DUG[end][i] != 0) // если связь есть
            {
                int temp = weight - DUG[end][i]; // определяем вес пути из предыдущей вершины
                if (temp == MIN_WEG[i]) // если вес совпал с рассчитанным
                { // значит из этой вершины и был переход
                    weight = temp; // сохраняем новый вес
                    end = i; // сохраняем предыдущую вершину
                    ver[k] = i + 1; // и записываем ее в массив
                    k++;
                }
            }
    }
    // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    cout<<"\nВывод кратчайшего пути:"<<endl;
    for (int i = k - 1; i >= 0; i--)
        cout<<setw(4)<<ver[i];
    cout<<endl<<endl;
}

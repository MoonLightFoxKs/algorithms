#include <iostream>
using namespace std;

class element {  //класс элемент
public:
    int v;       //значение
    element *a_s; //адрес следующего
    element *a_p; //адрес предыдущего
    int k;        //кол-во элементов в списке
};

class list{    //класс список
private:
    element *a_n; //начало списка
    element *a_k; //конец списка
public:
    list() {
        a_n = a_k = 0; //создание пустого списка
    }
   
    void addFirst(int v1) { //добавление элемента
        element *buf1 = new element;
        buf1->v = v1;
        if (a_n==0) {
            buf1->a_s = a_k;
            a_k = buf1;
        }
        else {
            buf1->a_s = a_n;
            a_k->a_p = buf1;
        }
        a_n = buf1;
        a_n->a_p = 0;
    }
    
    void showList() const { //вывод списка
        if (a_n!=0) {
            element *buf2 = a_n;
            while (buf2) {
                cout << buf2->v << " ";
                buf2 = buf2->a_s;
            }
            cout << endl;
        }
        else cout << "Лист пуст " << endl;
    }
    
    element* poisk(int v2){ //поиск элемента по заданному значению
        element *buf3 = a_n;
        if (a_n == 0){
            cout << "пусто";
            return 0;
        }
        else while (buf3){
            if (buf3->v == v2) {
                return buf3;
                break;
            }
            else buf3 = buf3->a_s;
         }
        return 0;
    }
    
    void addBefore(int v3, element *where1) { //добавление элемента перед заданным элементом
        if (where1 != 0) {
            element *buf4 = new element;
            buf4->v = v3;
            if (where1 == a_n){
                buf4->a_p = 0;
                buf4->a_s = where1;
                where1->a_p = buf4;
                a_n = buf4;
            }
            else{
                buf4->a_p = where1->a_p;
                buf4->a_s = where1;
                where1->a_p->a_s = buf4;
                where1->a_p = buf4;
            }
        }
        else cout << "Лист пуст";
    }
    
    void addAfter(int v4, element *where2){ //добавление элемента после заданного элемента
        if (where2 != 0) {
            element *buf5 = new element;
            buf5->v = v4;
            if (where2 == a_k){
                buf5->a_s = 0;
                buf5->a_p = where2;
                where2->a_s = buf5;
                a_k = buf5;
            }
            else{
                buf5->a_s = where2->a_s;
                buf5->a_p = where2;
                where2->a_s->a_p = buf5;
                where2->a_s = buf5;
            }
        }
        else cout << "Лист пуст";
    }
};

int main(){
    list l;
    l.addFirst(5);
    l.addFirst(4);
    l.addFirst(1);
    l.addAfter(3,l.poisk(1)); //добавляем 3 после 1
    l.addBefore(2, l.poisk(3)); //добавляем 2 перед 3
    l.showList(); //выводим список
    return 0;
} 

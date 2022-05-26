#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

struct List {
    int data;
    List* next;
};

void create_list(List*& L, int size) {
    List* t;
    cout << "Input element of first list: ";

    for (int i = 0; i < size; i++) {
        t = new List;
        cin >> t->data;
        t->next = L;
        L = t;
    }
}
void print(List* L, int num) {
    List* p = L;
    cout << "List L" << num << ":" << endl;

    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}
int GetSize(List* L) {
    int size = 0;
    for (; L != NULL; L = L->next)
    {
        ++size;
    }
    return size;
}
void delete_num(List* L) {
    List* p = L;

    for (int i = 1; i < GetSize(L); i++)
    {
        if (i % 2 == 0) {

        }
    }
}
int main()
{
    setlocale(LC_ALL, "RU");
    List* L1 = NULL, * L2 = NULL;
    int size;

    cout << "Input size of first list: ";
    cin >> size;
    create_list(L1, size);
    print(L1, 1);
    return 0;
}
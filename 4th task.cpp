#include <iostream>
using namespace std;

void fill(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

int main()
{
    int A[100];
    fill(A, 100);

    int key = 0;
    cout << "Input key: " << endl;
    cin >> key;

    bool apperance = false;

    for (int i = 0; i < 100; i++) {
        if (A[i] == key) {
            cout << "key = " << key << " " << "index = " << i << endl;
            apperance = true;
            break;
        }
    }
    if (!apperance) {
        cout << "key not found\n";
    }

    int B[10000];
    fill(B, 10000);

    key = 0;
    apperance = false;
    cout << "Input key: " << endl;
    cin >> key;

    for (int i = 0; i < 10000; i++) {
        if (B[i] == key) {
            cout << "key = " << key << " " << "index = " << i << endl;
            apperance = true;
            break;
        }
    }
    if (!apperance) {
        cout << "key not found\n";
    }

    int C[100000];
    fill(C, 100000);

    key = 0;
    apperance = false;
    cout << "Input key: " << endl;
    cin >> key;

    for (int i = 0; i < 100000; i++) {
        if (C[i] == key) {
            cout << "key = " << key << " " << "index = " << i << endl;
            apperance = true;
            break;
        }
    }
    if (!apperance) {
        cout << "key not found\n";
    }
}
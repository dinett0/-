#include<iostream>
#include<fstream>
#include<locale.h>
#include<iomanip>
#include <cstdlib>
using namespace std;

struct champ
{
    char naz[20];
    int vyi, por, nich, zab, pro;
};

int main()
{
    int i, j, n;
    ifstream file_in("D:\\in.txt");
    if (!file_in)
    {
        cout << "Error!" << endl;
        system("pause");
        return 0;
    }

    (file_in >> n).get();
    cout << n << endl;
    champ* p = new champ[n];
    for (i = 0; i < n; i++)
    {
        file_in.getline(p[i].naz, 20);
        cout << p[i].naz << endl;
        file_in >> p[i].vyi >> p[i].por >> p[i].nich >> p[i].zab >> p[i].pro;
        file_in.get();
        cout << p[i].vyi << ' ' << p[i].por << ' ' << p[i].nich << ' '
            << p[i].zab << ' ' << p[i].pro << endl;
    }
    file_in.close();

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].pro > p[j].pro)
            {
                swap(p[i], p[j]);
            }
        }
    }

    ofstream file_out("D:\\out.txt");
    if (!file_out)
    {
        cout << "Error! Failed to create a file for writing!" << endl;
        return 0;
    }

    file_out << n << endl;

    for (i = 0; i < n; i++)
    {
        file_out << p[i].naz << endl;
        file_out << p[i].vyi << ' ' << p[i].por << ' '
            << p[i].nich << ' ' << p[i].zab << ' ' << p[i].pro << endl;
    }

    cout << "Result in file out.txt" << endl << endl;
    file_out.close();

    file_out.open("D:\\file.bin", ios::binary);
    if (!file_out)
    {
        cout << "Error! Failed to create a file for writing!" << endl;
        return 0;
    }

    file_out.write((const char*)&n, sizeof(n));
    file_out.write((const char*)p, sizeof(champ) * n);
    file_out.close();

    delete[] p;

    file_in.open("D:\\file.bin", ios::binary);
    if (!file_in)
    {
        cout << "Error!" << endl;
        return 0;
    }

    n = 0;
    file_in.read((char*)&n, sizeof(n));
    cout << n << endl;

    p = new champ[n];

    file_in.read((char*)p, sizeof(champ) * n);
    file_in.close();

    for (int i = 0; i < n; ++i)
    {
        cout << p[i].naz << endl;
        cout << p[i].vyi << ' ' << p[i].por << ' ' << p[i].nich << ' '
            << p[i].zab << ' ' << p[i].pro << endl;
    }

    delete[] p;
    return 0;
}
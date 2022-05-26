#include <iostream>
using namespace std;
const int n = 10, col_razr = 3;
int length_number(int dat, int number)
{
    while (number > 1)
    {
        dat /= 10;
        number--;
    }
    return dat % 10;
}

void sort_number(int dop_mas[n][n], int mas[n], int number)
{
    int mas_col[n], i, j, temp = 0;
    for (i = 0; i < n; i++)
        mas_col[i] = 0;
    for (i = 0; i < n; i++)
    {
        int a = length_number(mas[i], number);
        dop_mas[mas_col[a]][a] = mas[i];
        mas_col[a]++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mas_col[i]; j++)
        {
            mas[temp] = dop_mas[j][i];
            temp++;
        }
    }
}

int main()
{

    int number, i;
    int mas[n] = { 403, 533, 550, 715, 698, 612, 502, 306, 704, 248 };
    int dop_mas[n][n];
    for (number = 1; number < 4; number++)
        sort_number(dop_mas, mas, number);
    for (i = 0; i < n; i++)
        cout << mas[i] << endl;
    return 0;
}
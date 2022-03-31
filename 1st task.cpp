#include <iostream>
#include <ctime>

int const SIZE = 10;

using namespace std;

bool prostate(int a);
void fill(int arr[], int size);
void show(int arr[], int size);

int main()
{
	srand(time(NULL));

	int arr[SIZE];
	fill(arr, SIZE);
	show(arr, SIZE);

	cout << "Prime number's indexes are: ";

	int first_prime = -1;
	bool swich = true;

	for (int i = 0; i < 10; i++)
	{
		if (prostate(arr[i]) == true) {
			if (swich) {
				cout << i << " ";
				first_prime = i;
				swich = false;
			}
			else {
				cout << i << " ";
			}
		}
	}

	cout << endl;

	int arr1[SIZE + 1]{};

	if (first_prime != -1) {
		swich = true;;

		for (int i = 0; i < SIZE + 1; i++)
		{
			if (i == first_prime) {
				swich = false;
				arr1[i] = arr[i];
				continue;
			}
			(swich) ? (arr1[i] = arr[i]) : (arr1[i] = arr[i - 1]);
		}
		show(arr1, SIZE + 1);

		cout << "Here you can put any integer number: ";
		cin >> arr1[first_prime + 1];

		show(arr1, SIZE + 1);
	}
	else {
		cout << "no prime numbers around..." << endl;
	}

	int arr2[SIZE + 1];

	for (int i = 0; i < SIZE + 1; i++)
	{
		if ((arr1[i] % 7) == 0) {
			continue;
		}
		arr2[i] = arr1[i];
	}
	cout << "Here's an array with cut out 7s: " << endl;
	show(arr2, SIZE + 1);
}

void fill(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool prostate(int a)
{
	int count = 0;

	for (int i = 1; i <= a; i++) {

		if ((a % i) == 0)
			count++;
	}

	return (count == 2) ? (true) : (false);
}
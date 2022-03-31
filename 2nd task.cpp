#include <iostream>
#include <ctime>

using namespace std;

bool prostate(int a);
void fill(int arr[], int size);
void show(int arr[], int size);
void kill7(int arr[], int size);


int main()
{
	srand(time(NULL));

	int size;
	cout << "Enter SIZE value" << endl;
	cin >> size;

	int* arr = new int[size];

	fill(arr, size);
	show(arr, size);

	cout << "Prime number's indexes are: ";

	int first_prime = -1;
	bool swich = true;

	for (int i = 0; i < size; i++) {
		if (prostate(arr[i])) {
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

	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (first_prime != -1) {
		size++;

		int* arrr = new int[size];


		swich = true;;

		for (int i = 0; i < size; i++){
			if (i == first_prime) {
				swich = false;
				arrr[i] = arr[i];
				continue;
			}
			(swich) ? (arrr[i] = arr[i]) : (arrr[i] = arr[i - 1]);
		}
		delete[] arr;

		cout << "Here you can put any integer number: ";
		cin >> arrr[first_prime + 1];

		show(arrr, size);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

		kill7(arrr, size);

		delete[] arrr;
	}
	else {
		cout << "no prime numbers around..." << endl;

		kill7(arr, size);

		delete[] arr;
	}
}

void fill(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
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
		{
			count++;
		}
	}

	return (count == 2) ? (true) : (false);
}

void kill7(int arr[], int size) {

	int amoun7 = 0;
	for (int i = 0; i < size; i++) {
		if ((arr[i] % 7 == 0) && (arr[i] != 0)) {
			amoun7++;
		}
	}

	int* arrrr = new int[size - amoun7];

	int j = 0;
	for (int i = 0; i < size - amoun7; i++) {
		int place;
		for (; j < size; j++)
		{
			int count = 1;
			if ((arr[j] % 7 == 0) && (arr[j] != 0)) {
				count++;
				continue;
			}
			place = arr[j];
			j += count;
			break;
		}
		arrrr[i] = place;
	}

	cout << "Array without sevens: " << endl;
	show(arrrr, size - amoun7);

	delete[] arrrr;
}



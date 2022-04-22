#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

	string test = "In computer programming, a null-terminated string is a character string stored as an array containing the characters and terminated with a null character. Alternative names are C string, which refers to the C programming language and ASCIIZ. ", exp = "string";
	int i = 0, eh;
	bool checker = true;

	while (test[i]!='\0')
	{
		checker = true;
		if (test[i] == exp[0]) {
			eh = i;
			for (int j = 0; j < exp.length(); j++)
			{
				if (exp[j] != test[eh]) {
					checker = false;
					break;
				}
				eh++;
			}
			if (checker) {
				cout << "Index " << i;
			}
		}
		i++;
	}

}
#include <iostream>
using namespace std;

const int SIZE = 100;

void Search(int A[], int SIZE, int search_value) {
	int begin, end, mid;
	begin = 0;
	end = SIZE;
	int i = 0;

	while (true)
	{
		mid = (end + begin) / 2;
		if (A[mid] > search_value) {
			end = mid;
			cout << "Iteration " << i++ << ", not found\n";
		}
		else if (A[mid] < search_value) {
			begin = mid;
			cout << "Iteration " << i++ << ", not found\n";
		}
		else {
			cout << "Iteration " << i << ". Found on the position " << mid;
			break;
		}
		if (i > 10) {
			break;
		}
	}

	cout << endl;
}

void show(int arr[], int size) {
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {

	int A[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		A[i] = i + 1;
	}

	show(A, SIZE);

	int search_value;
	cout << "Enter value: ";
	cin >> search_value;
	Search(A, SIZE, search_value);

	/// ///////////////////////////////////////////////////////////////////////////////////////////////////////

	int C[1000];
	for (size_t i = 0; i < 1000; i++)
	{
		C[i] = i + 1;
	}

	cout << "Enter value: ";
	cin >> search_value;

	Search(A, 1000, search_value);
}

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void fill(vector<int> &a) {
	cout << "fill func:";

	for (int i = 0; i <	10; i++)
	{
		a.push_back(rand());
	}
}

void show(vector<int> &a) {
	cout << "show func:\n|";

	for (int shower:a)
	{
		cout << shower << "|";
	}
	cout << endl;
}

bool prostate(int a)
{
	int count = 0;

	for (int i = 1; i <= a; i++) {
		if ((a % i) == 0){
			count++;
		}
	}
	return (count == 2) ? (true) : (false);
}

int main(int argc, char*argv[]) {
	srand(time(NULL));

	vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(rand()%100);
	}

	cout << endl;
	show(vec);

	cout << "Prime number's indexes are: \n";
	int first_prime = -1;

	for (size_t i = vec.size()-1; i > 0; i--)
	{
		if (prostate(vec[i])) {
			cout << i << " ";
			first_prime = i;
		}
	}
	cout << endl;

	 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (first_prime != -1) {
		int number;
		cout << "Enter some number here: ";
		cin >> number;

		vec.insert(vec.begin() + first_prime + 1 , number);
		show(vec);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ) {
		if (*it % 7 == 0 && *it != 0) {
			it = vec.erase(it);
		}
		else {
			++it;
		}
	}

	show(vec);
}
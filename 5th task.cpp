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

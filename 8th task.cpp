#include <iostream> // ??????? 2
#include <stack>

using namespace std;

int main() {
    int n, x;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            s.push(x);
        }
        if (i > 0) {
            if (x > s.top()) {
                s.push(x);
            }
        }
    }
    cout << "Output of the program: " << s.size() << "\n";
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int op1 = A * N;
    (op1 < B)? cout << op1 << endl: cout << B << endl;
}
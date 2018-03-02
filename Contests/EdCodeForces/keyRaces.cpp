#include <iostream>

using namespace std;

int main(void) {
    long long s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    long long first = (v1 * s) + (2 * t1), second = (v2 * s) + (2 * t2);

    if(first < second) cout << "First\n";
    else if (second < first) cout << "Second\n";
    else cout << "Friendship\n";

    return 0;
}
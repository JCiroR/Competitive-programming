#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <climits>

using namespace std;

typedef long long ll;

const int MAXN = 110;

map<ll, int> indices;
int fib_to_index[MAXN];

void load() {
    indices[1] = 0;
    indices[2] = 1;
    ll prev_2 = 1, prev = 2;
    long long limit = INT_MAX;
    for(int i = 2; i < 100; i++) {
        ll curr = prev + prev_2;
        indices[curr] = i;
        prev_2 = prev;
        prev = curr;
        if(curr > limit) break;
    }
}

int main(void) {
    load();
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int max_index = -1;
        ll curr;
        for(int i = 0; i < N; i++) {
            cin >> curr;
            fib_to_index[i] = indices[curr];
            max_index = max(max_index, fib_to_index[i]);
        }
        string cipher;
        getline(cin, cipher);
        getline(cin, cipher);
        string text(max_index + 1, ' ');
        int j = 0;
        for(int i = 0; i < cipher.size() && j < N; i++) {
            if(isupper(cipher[i])) {
                text[fib_to_index[j]] = cipher[i];
                j++;
            }
        }
        cout << text << endl;;
    }

}
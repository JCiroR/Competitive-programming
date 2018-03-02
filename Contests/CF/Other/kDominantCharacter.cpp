#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int last_ocurrence[256];
int max_distance[256];

int curr_distance(char curr, int i) {
    if(last_ocurrence[curr] == -1) return i;
    else return i - last_ocurrence[curr] - 1;
}

int main(void) {
    string s;
    cin >> s; int s_size = s.size();
    memset(last_ocurrence, -1, sizeof(last_ocurrence));
    memset(max_distance, -1, sizeof(max_distance));

    for(int i = 0; i < s.size(); i++) {
        char curr = s[i];
        max_distance[curr] = max(max_distance[curr], curr_distance(curr, i));
        last_ocurrence[curr] = i;
    }

    int answ = s.size();
    for(int i = 0; i < 256; i++)
        if(max_distance[i] != -1) answ = min(answ, max(max_distance[i], s_size-1-last_ocurrence[i]));

    cout << answ + 1 << endl;
    return 0;
}
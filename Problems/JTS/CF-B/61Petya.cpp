#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    int n, temp;
    cin >> n;
    vector<int> vi;
    vi.reserve(n);
    while(n--) {
        cin >> temp;
        vi.push_back(temp);
    }
    int max = -1;
    for(int i = 0; i < vi.size(); i++) {
        int curr = 1, last = vi[i];
        for(int j = i-1; j >= 0; j--) {
            if(vi[j] <= last) curr++;
            else break;
            last = vi[j];
        }
        last = vi[i];
        for(int j = i+1; j < vi.size(); j++) {
            if(vi[j] <= last) curr++;
            else break;
            last = vi[j];
        }
        if(max < curr) max = curr;
    }
    cout << max << endl;
}
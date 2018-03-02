#include <iostream>
#include <cstring>

using namespace std;

int a[20];
int freq[20];

int main() {
    memset(a, 0, sizeof(a));
    memset(freq, 0, sizeof(freq));
    int lim, sum, count = 0;
    cin >> sum >> lim;
    for(int i = 1; i <= lim; i++) {
        int t = (i &(-i));
        for(int j = 0; j < 20; j++)
            if(t & (1 << j)) a[j]++;                
    }
    for(int i = 20; i >= 0; i--) {
        if((1 << i) & sum)
            freq[i]++, count++;
        if((1 << i) > lim) {
            count += freq[i];            
            freq[i - 1] += 2 * freq[i];
            freq[i] = 0;
        } else if(a[i] < freq[i] && i > 0) {
            int def = freq[i] - a[i];
            freq[i] -= def;
            freq[i - 1] += def * 2;
            count += def;
        }        
    }
    for(int i = 0; i < 20; i++)
        if(a[i] < freq[i]) { 
            cout << -1 << endl;
            return 0;
        }
    cout << count << endl; bool space = false;
    for(int i = 1; i <= lim && count; i++) {
        int t = (i & (-i)), index;
        for(int j = 0; j < 20; j++)
            if(t & (1<<j)) index = j;
        if(freq[index] > 0) {
            freq[index]--;
            count--;
            if(space) cout << " ";
            cout << i;
            space = true;
        }
    }
    cout << endl;
}
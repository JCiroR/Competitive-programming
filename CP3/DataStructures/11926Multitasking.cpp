#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <bitset>

#define MAXN 1000001

using namespace std;

int main(void) {
    int n, m, start, end, repetition;
    bitset<MAXN> tasks;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        bool conflict = false;
        tasks.reset();    
        while(n--) {
            cin >> start >> end;
            for(int i = start; i < end && !conflict; i++) {
                if(tasks[i] == 0) tasks[i] = 1;
                else conflict = true;
            }
        }

        while(m--) {
            cin >> start >> end >> repetition;
            while(start < tasks.size() && !conflict) {
                for(int i = start; i < end && i < tasks.size(); i++) {
                    if(tasks[i] == 0) tasks[i] = 1;
                    else {
                        conflict = true;
                        break;
                    }
                }
                start += repetition;
                end += repetition;
            }
        }
        if (conflict) cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";
    }
    return 0;
}
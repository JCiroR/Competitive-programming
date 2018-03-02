#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 13;
int l[MAXN];

bool greaterThan(int i, int j) { return i > j;}

int main(void) {
    int t, n, temp;
    while(cin >> t >> n) {
        if(n == 0) break;
        fill(&l[0], &l[MAXN-1], 0);
        printf("Sums of %i:\n", t);
        for(int i = 0; i < n; i++) scanf("%i", &l[i]);
        sort(&l[0], &l[MAXN], greaterThan);

        int guide = 0;
        for(int i = 0; i < n; i++)
            guide = guide | 1 << i;
        bool answFound = false;

        set<string> mem;
        while(guide != 0) {
            int sum = 0;
            for(int i = 0; i < n && sum <= t; i++)
                if(1<<i & guide) sum += l[(n-1) - i];
            if(sum == t) {
                string answ = "";
                for(int i = n - 1; i >= 0; i--) {
                    if(1<<i & guide) { 
                       if(!(answ.size() == 0)) answ += "+";
                         answ += to_string(l[(n-1)-i]);
                    }
                }
                if(mem.count(answ) == 0) {
                    cout << answ << "\n";
                    mem.insert(answ);
                }
                answFound = true;
            }
            guide--;
        }
        if(!answFound) printf("NONE\n");
    }
    return 0;
}
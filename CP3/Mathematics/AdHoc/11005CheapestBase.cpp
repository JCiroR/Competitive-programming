#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int costs[256];

long long getCost(string number) {
    long long cost = 0;
    for(int i = 0; i < number.size(); i++) {
        cost += costs[number[i]];
    }
    return cost;
}

string toRadix(int query, int b) {
    if(query == 0) return "0";
    string rep = "";
    while(query) {
        rep += digits[query % b];
        query /= b;
    }
    reverse(rep.begin(), rep.end());
    return rep;
}

int main(void) {
    int cT = 0, T;
    cin >> T;
    while(T--) {
        cT++;
        if(cT > 1) printf("\n");
        printf("Case %d:\n",cT);
        int cost;
        for(int i = 0; i < 36; i++) {
            cin >> cost;
            char digit  = digits[i];
            costs[digit] = cost;
        }
        int Q, query; cin >> Q;
        while(Q--) {
            cin >> query;
            long long cheapest = 2000*36;
            vector<int> bases;
            for(int i = 2; i <= 36; i++) {
                int bRadixCost = getCost(toRadix(query, i));
                if(bRadixCost == cheapest) bases.push_back(i);
                else if(bRadixCost < cheapest) {
                    cheapest = bRadixCost;
                    bases.clear();
                    bases.push_back(i);
                }
            }
            /**/
            printf("Cheapest base(s) for number %d:", query);
            for(int i = 0; i < bases.size(); i++)
                printf(" %d", bases[i]);
            printf("\n");/**/
        }
    }
    return 0;
}
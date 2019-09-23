#include <string>
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

string getC(long long curr) {    
    string aux = to_string(curr), s = "";
    for(int i = 0; i < aux.size(); i++) {
        if((aux[i] - '0') % 2 == 0) s.push_back('0');
        else s.push_back('1');
    }
    s.insert(0, 18 - s.size(), '0');
    return s;
}

int main() {
    int t;
    scanf("%d\n", &t);
    unordered_map<string, int> mp(100010);
    while(t--) {
        long long curr;
        char op;
        scanf("%c %I64d\n", &op, &curr);
        string code = getC(curr);
        if(op == '+') mp[code]++;                    
        else if(op == '-') mp[code]--;
        else if(op == '?') printf("%d\n", mp[code]);
    }
}
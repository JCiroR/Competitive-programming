#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

#define MAXN 10005

int intervals[MAXN][2];
string names [MAXN];


int main(void) {
    int T,D, L, H, Q, P,records;
    string name;

    scanf("%i", &T);
    while(T--) {
        records = 0;
        scanf("%i", &D);
        while(D--) {
            cin >> name >> L >> H;
            names[records] = name;
            intervals[records][0] = L;
            intervals[records][1]  = H;
            records++;
        }
        scanf("%i", &Q);
        while(Q--) {
            scanf("%i", &P);
            int nameIndex = -1;
    
            for(int i = 0; i < records; i++) {
                if(intervals[i][0] <= P && intervals[i][1] >= P) {
                    if(nameIndex == -1) nameIndex = i;
                    else {
                        nameIndex = -1;
                        break;
                    }
                }
            }
            if(nameIndex != -1) cout << names[nameIndex] << "\n";
            else cout << "UNDETERMINED\n";
        }
        if(T != 0) cout << "\n"; 
    }
    return 0;
}
#include <cstdio>

using namespace std;

const int MAXN = 105;
char field[MAXN];

int main(void) {
    int T, testC = 1;
    scanf("%i", &T);
    while(T--) {
        int N;
        scanf("%i %s",&N, field);
        int answ = 0;
        for(int i = 0; i < N;) {
            if(field[i] == '.') {
                answ++;
                i += 3;
            } else ++i;
        }
        printf("Case %i: %i\n", testC++, answ);
    } 
    
    return 0;
}
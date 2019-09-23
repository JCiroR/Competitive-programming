#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 3005;
bool arcs[MAXN][MAXN];

int main(void) {
    int T, n, m, from, to;
    scanf("%i", &T);
    while(T--) {
        fill(&arcs[0][0], &arcs[0][0] + sizeof(arcs), false);
        scanf("%i %i", &n, &m);
        while(m--) {
            scanf("%i %i",&from, &to);
            if(from == to) continue;
            from--; to--;
            arcs[from][to] = arcs[to][from] = true;
        }
        int answ = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)
            {
                if(!arcs[i][j]) continue;
                for(int k = j + 1; k < n; k++) {
                    if(arcs[k][i] && arcs[j][k]) answ++;
                }
            }
        }
    printf("%i\n", answ);
    }
    return 0;
}
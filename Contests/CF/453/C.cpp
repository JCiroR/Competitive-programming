#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100003 * 2;
int g1[MAXN], g2[MAXN], seq[MAXN], indice, n;

bool build(int lev) {
    bool perfect = true;
    for(int i = 0; i < seq[0]; i++) {
        g1[indice] = -1;
        g2[indice] = -1;
        indice++;
    }
    
    for(int i = 1; i < lev; i++) {
        int parent = indice - 1, parent2 = indice -2;

        if(seq[i] > 1 && seq[i - 1] > 1) {
            perfect = false;
            for(int j = 0; j < seq[i]; j++) {
                g1[indice] = parent;
                if(j % 2 == 0) g2[indice] = parent;
                else g2[indice] = parent2;
                indice++;
            }
        } else {
            for(int j = 0; j < seq[i]; j++) {
                g1[indice] = g2[indice] = parent;
                indice++;
            }
        }
    }
    return perfect;
}

int main(void) {
    memset(g1, 0, sizeof(g1));
    memset(g2, 0, sizeof(g2));
    indice = n = 0;

    int h; cin >> h;
    for(int i = 0; i <= h; i++) {
        cin >> seq[i];
        n += seq[i];
    }
    if(build(h + 1)) cout << "perfect\n";
    else {
        cout << "ambiguous\n";
        cout << g1[0] + 1;
        for(int i = 1; i < n; i++) {
            cout << " " << g1[i] + 1;
        }
        cout << "\n" << g2[0] + 1;
        for(int i = 1; i < n; i++) {
            cout << " " << g2[i] + 1;
        }
        cout << endl;
    }
    return 0;
}
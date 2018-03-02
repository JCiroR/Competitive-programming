#include <iostream>

using namespace std;

int main(void) {
    int tNecesitado = 0, n, temp, m, j, r;
    int minTime = -1;
    cin >> n;
    while(n--) {
        cin >> temp;
        tNecesitado += temp;
    }

    cin >> m;
    while(m--) {
        cin >> j >> r;
        if(j <= tNecesitado && tNecesitado <= r) {
            minTime = tNecesitado;
            break;
        } else if (tNecesitado <= j) {
            minTime = j;
            break;
        }
    }

    cout << minTime;
    return 0;
}
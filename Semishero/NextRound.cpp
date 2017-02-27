#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, temp, counter = 0;
    cin >> n >> k;

    //if(n == 1 && k > 1) cout << 1;

    vector<int> arreglo;
    while(n--) {
        cin >> temp;
        arreglo.push_back(temp);
    }
    int kth = arreglo[k - 1];


    for(int i = 0; i < arreglo.size(); i++) {
        if(arreglo[i] > 0 &&  arreglo[i] >= kth) counter++;
    }
    cout << counter;
}
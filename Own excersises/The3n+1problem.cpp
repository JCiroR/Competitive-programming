#include <iostream>

using namespace std;

int main() {
    int i, j, counter, maxVal, temp;

    while(cin >> i >> j) {
        maxVal = 1;
        int min = i;            //Desperate solution
        int max = j;            // I won't do it again :'v
        if(i > j) {
            min = j;
            max = i;
        }
        for(int t = min; t <= max; t++) {
            counter = 1;
            temp = t;
            while(temp != 1) {
                if (temp % 2 == 0) temp /= 2;
                else temp = temp * 3 + 1;
                counter ++;
            }
            if (counter > maxVal) maxVal = counter;
        }
        cout << i << " " << j << " " << maxVal << endl;
    }
    return 0;
}
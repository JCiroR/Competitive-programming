#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, m, c, currentUsage, maxUsage, request;
    bool blown;
    vector<int> devices;
    devices.reserve(21);

    int counter = 1;
    while(cin >> n >> m >> c) {
        if(n == 0 && m == 0 && c == 0) break;
        cout << "Sequence " << counter << endl;
        counter ++;

        for(int i = 0; i < n; i++) {
            cin >> devices[i];      
        }  
        currentUsage = 0;
        maxUsage = 0;   
        blown = false;     
        
        for(int i = 0; i < m; i++) {
            cin >> request;
            currentUsage += devices[request - 1];
            devices[request - 1] *= -1;
            maxUsage = max(maxUsage, currentUsage);
            if(currentUsage > c) blown = true;
        }
        
        if(blown) cout << "Fuse was blown." << endl << endl;
        else cout << "Fuse was not blown." << endl << "Maximal power consumption was " 
                  << maxUsage << " amperes." << endl << endl;
    }

    return 0;
}
    #include <iostream>

    using namespace std;

    int main(void) {
        int cases, currx, curry, x, y;
        while(cin >> cases >> x >> y) {
            if(cases == 0) break;
            while(cases--) {
                cin >> currx >> curry;
                if(currx == x || curry == y) cout << "divisa\n";
                else if(currx > x && curry > y) cout << "NE\n";
                else if(currx > x && curry < y) cout << "SE\n";
                else if(currx < x && curry > y) cout << "NO\n";
                else cout << "SO\n";  
            }
        }
        return 0;
    }
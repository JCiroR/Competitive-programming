#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream ifs("input.txt", ifstream::in);
    int n, temp; ifs >> n;
    vector<int> vi;
    vi.reserve(n);    
    for(int i = 0; i < n; i++) {
        ifs >> temp;
        vi.push_back(temp);
    }
    ifs.close();
    sort(vi.begin(), vi.end());
    int max_r = 1;
    for(int i = 0; i < n; i++) {
        int as_min = 2 * vi[i];
        int as_max = (vi[i] % 2 == 0)? vi[i]/2 : (vi[i] + 1)/2;
        max_r = max(max_r,int (1 + i - (lower_bound(vi.begin(), vi.end(), as_max) - vi.begin())));
        max_r = max(max_r, int((upper_bound(vi.begin(), vi.end(), as_min) - vi.begin()) - i));
    }
    ofstream ofs ("output.txt", ofstream::out);
    ofs << n - max_r << endl;
    ofs.close();
}
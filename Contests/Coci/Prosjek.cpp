#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<double> nums;
    int n; cin >> n;
    while(n--) {
        double temp; cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    while(nums.size() > 1) {
        double a = nums[0];
        double b = nums[1];
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        nums.insert(nums.begin(), ((a+b)/2.0));
    }
    printf("%.7lf\n", nums[0]);    
}

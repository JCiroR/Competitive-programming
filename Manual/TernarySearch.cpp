int main() {
    int r = n-1, l = 0;
    while (r - l > 2) { // greater than precision
        int l2 = l + (r-l)/3;
        int r2 = r - (r-l)/3;
        // left pointer to maximum
        if (arr[l2] < arr[r2]) l = l2;  // change to <= to find right pointer
                                        // change to > to find minimum
        else r = r2;
    }
    // maximum is either l, l+1 or r
    printf("%d - %d: %d %d %d\n", l, r, arr[l], arr[l+1], arr[r]);
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}
double winnerOfTheGameOfMarbles(int a, int b)
{
    if (a == 0) return 1.000000;
    double ans = 0.000000;
    double res ;
    if (b > 0) {
        res = double(b) / double(b + a);
        b--;
        double k = res * double(a) / double(b + a);
        ans += k;
    }
    while(b > 0) {
        if (b > 0) {
            res *= double(b) / double(b + a);
            b--;
        }
        if (b > 0) {
            res *= double(b) / double(b + a);
            b--;
        }
        double k = res * double(a) / double(b + a);
        ans += k;

    }
    double p = 1.000000 - ans;
    return p;
}
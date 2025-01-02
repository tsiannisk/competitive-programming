const int N = 2020;
	 
int z[N][N][2];

int solve(string s) {
    int n = sz(s);
    forn(i, n + 1) forn(j, m) forn(k, 2) z[i][j][k] = 0;
    z[0][0][1] = 1;
    forn(i, n)
    forn(j, m)
    forn(k, 2)
    for (int p = 0; p <= (k ? int(s[i] - '0') : 9); p++) {
        if ((i & 1) && p != d) continue;
        if (!(i & 1) && p == d) continue;
        if (!i && !p) continue;
        int ni = i + 1;
        int nj = (j * 10 + p) % m;
        int nk = k && (p == int(s[i] - '0'));
        inc(z[ni][nj][nk], z[i][j][k]);
    }
    int ans = 0;
    forn(k, 2) inc(ans, z[n][0][k]);
    return ans;
}
	 
bool good(string s) {
int rm = 0;
forn(i, sz(s)) {
    int p = int(s[i] - '0');
    if ((i & 1) && p != d) return false;
    if (!(i & 1) && p == d) return false;
    rm = (rm * 10 + p) % m;
}
return !rm;
}
	 
inline void solve() {
    int ans = 0;
    inc(ans, solve(b));
    dec(ans, solve(a));
    inc(ans, good(a));
    cout << ans << endl;
}
	 
inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }
	 
int main() {
    #ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
    #endif
	    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
	 
    while (read()) {
        ld stime = gett();
        solve();
        cerr << gett() - stime << endl;
    }
	    
    return 0;
}
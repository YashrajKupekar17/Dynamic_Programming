#include<bits/stdc++.h>
using namespace std;
 
 
template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }
 
#define int     long long
#define all(x)  x.begin(), x.end()
#define double  long double
#define endl    '\n'
#define ff      first
#define ss      second
#define v       vector
const bool MULTIPLE_TESTCASES = 0; 
// int gways(int n) {
//     if (n == 1) return 1;
//     if (n == 2) return 2;
//     return ways(n - 1) + gways(n - 1);  // Now ways is recognized in scope
// }

// int ways(int n) {
//     if (n == 1) return 1;
//     if (n == 2) return 2;
//     return ways(n - 1) + ways(n - 2) + 2 * gways(n - 2);  // Use gways correctly
// }

//the question is
// Function to calculate the number of ways to tile a 2xN grid
int ways(int n){
    int w[n+10],g[n+10];
    w[0]=g[0]=0;
    w[1]=g[1]=1;
    w[2]=g[2]=2;
    for(int i=3;i<=n;i++){
        w[i]=w[i-1]+w[i-2]+ 2*g[i-2]; // Calculate the number of ways to tile a 2xN grid using the recurrence relation
        g[i]=w[i-1]+g[i-1]; // Calculate the number of ways to tile a 2xN grid with a gap at the end
    }
    return w[n]; // Return the number of ways to tile a 2xN grid
}

// Function to solve the problem
void solve() {
    int n;
    cin>>n; // Input the value of N
    int ans = ways(n); // Calculate the number of ways to tile a 2xN grid
    cout<<ans<<endl; // Output the result
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    MULTIPLE_TESTCASES and cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve();
    }
}

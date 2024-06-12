//sol
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include<array> 
#include<cstdlib> 
#include <stack>
#include <queue>
#include <set>
#include <map>
#include<iomanip>
#include <fstream>
#include <string>
#include<bitset>

#include<bits/stdc++.h>

#define beginn v.begin();
#define endd  v.end();
#define vectorr  vector<int> v(n);
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(nullptr);
typedef const int dd;
typedef long long ll;

using namespace std;


template<class x>
ostream& operator ==(ostream& out, x y) {
    out << y;
    return out;
}

template<class x>
istream& operator / (istream& in, x& y) {
    in >> y;
    return in;
}

template<class x>
void print(x y) {
    cout << y;
    cout << "\n";

    return;
}

template <class t>
void get(t& x) {

    cin >> x;
    return;
}


bool isbrime(long long val) {
    for (long long c = 2; c <= (val / 2); c++) {
        if (val % c == 0)
            return false;
    }
    return true;
}


void prefix(vector<long long>& pre, vector<long long>v) {
    pre[0] = v[0];
    for (long long c = 1; c < v.size(); c++) {
        pre[c] = pre[c - 1] + v[c];
    }
    return;
}


int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int nPr(int n, int r)
{
    return fact(n) / fact(n - r);
}

void primefact(ll x, vector<ll>& v) {

    for (ll d = 2; d * d <= x; d++) {
        while (x % d == 0) {
            v.push_back(d);
            x /= d;
        }
    }
    if (x > 1)
        v.push_back(x);// like 7
    return;
}


void read(vector<int>& arr, ll m) {

    for (ll c = 0; c < m; c++) {
        get(arr[c]);

    }

    return;
}

bool check(string j) {
    for (int c = 0; c < (j.size() - 1); c++) {
        if (j[c] == j[c + 1]) {
            if ((j[c] != '*') && (j[c] != '?'))
                return false;
        }
    }

    return true;
};


int gcd(int x, int y) {

    vector <int>vx;
    for (int i = 1; i <= x; ++i) {
        if (x % i == 0)
            vx.push_back(i);
    }

    vector <int>vy;
    for (int i = 1; i <= y; ++i) {
        if (y % i == 0)
            vy.push_back(i);
    }

    sort(vx.begin(), vx.end());
    //the max. elements are in the end 
    for (int c = vx.size() - 1; c >= 0; c--) {
        int n = count(vy.begin(), vy.end(), vx[c]);
        if (n != 0) {
            return vx[c];
        }
    }


}

void solve() {
 
    int r, co;
    get(r);
    get(co);
   
    int rmax = -1;
    int cmax = -1;
    
    int nr,zc;
    vector<string>arr(r);
    for (int c = 0; c < r; c++) {
        get(arr[c]);
        int row = count(arr[c].begin(), arr[c].end(), '#');
        if (row >= rmax) {
            
            rmax = row;//the index of this row
            nr = c;
        }
    }

    

    for (int j = 0; j < co; j++) {
        int sum = 0;
        for (int k = 0; k < r; k++) {
            if (arr[k][j] == '#')
                sum++;
        }
        if (sum > cmax) {
            cmax = sum;
            zc = j;
        }
    }

    

    cout<<++nr<<" "<<++zc<<std::endl;
     
    return;
}



int main() {

    fast;
    int t;
    get(t);
    while(t--)
    solve();

    return 0;
}



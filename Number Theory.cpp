//
// Created by Ismail Mohamed on 7/9/2024.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

// Fixed Mod.

ll fixMod(ll a, ll b) {
    return (a % b + b) % b;
}


// Get Divisors.

vector<int> getDivisors(int n) {    // O(sqrt(n))
    vector<int> ret;
    int i = 1;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }

    if (i * i == n) {
        ret.push_back(i);
    }
    return ret;
}

// Get Multiples.

vector<int> getMultiples(int x, int n) {    // O(n/x)
    vector<int> ret;
    for (int m = x; m <= n; m += x) {
        ret.push_back(m);
    }
    return ret;
}


// Get Prime.

bool isPrime(int n) {   // O(sqrt(n))
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}



// Is Prime from 1 to n.

const int N = 1e6 + 6;

bool Prime[N];

void sieve() {
    fill(Prime, Prime + N, true);
    Prime[0] = Prime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (Prime[i]) {
            for (int m = i * i; m < N; m += i) {
                Prime[m] = false;
            }
        }
    }
}


// Get Power LL.

ll fPower(ll a, ll b) {  // O(log(b))
    if (b == 0) return 1;
    ll p = fPower(a, b >> 1);
    return (b & 1) ? p * p * a : p * p;
}


// GCD.

ll GCD(ll a, ll b) {  // O(log(n))
    if (b == 0) return a;
    return GCD(b, a % b);
}


// LCM.


// GCD * LCM = a * b
ll LCM(ll a, ll b) {
    return a * (b / GCD(a, b));
}



int main(){

    return 0;
}


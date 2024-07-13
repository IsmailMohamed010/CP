//
// Created by Ismail Mohamed on 7/9/2024.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long


#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)

/* Mod Equations (use it to avoid overflow).
 * (a + b) % x = (a % x + b % x) % x
 * (a - b) % x = (a % x - b % x) % x
 * (a * b) % x = (a % x * b % x) % x
 */


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

// Function to get Divisors for all number form 1 to n
vector<ll>res(1e6+5,1);
ll getDivisors_form_1_to_n(ll n) {  // o(n*log(n))
    for(ll i = 2;i<=n;i++) {
        ll z= i;
        while(z<=n) {
            res[z]++;
            z+=i;
        }
    }
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



// Is Prime.

const int N = 1e6 + 6;

bool Prime[N];

void sieve() {      // o(n) ==> o(n*log(log(n+1))).
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

/*
Be worried that if you check about one prime number only you find isprime() is better than sieve()
as the time complexity for isprime() is less than sieve()  (o(sqrt(n) < o(n)),
but if you check about more than one use sieve() better than isprime() (o(n) < o(n*sqrt(n))).
*/


// Get Prime Factors like this formula ==> N (N>1) = P1^e1 * P2^e2 * P3^e3 ......
vector<pair<int, int> > getPrimeFactors(ll n) { // O(sqrt(n))
    vector<pair<int, int> > ret;
    for (int p = 2; p * p <= n; p++) {
        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        if (e > 0) {
            ret.push_back({ p, e });
        }
    }
    if (n > 1) {
        ret.push_back({ n, 1 });
    }
    return ret;
}


// Get Power LL.

ll fPower(ll a, ll b) {  // O(log(b))
    if (b == 0) return 1;
    ll p = fPower(a, b >> 1);
    return (b & 1) ? p * p * a : p * p;
}

/*
 * Basic ideas for GCD  gcd(a,b) = 1 mean that a & b is a co-prime numbers.
 */
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

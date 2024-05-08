#include <bits/stdc++.h> 
using namespace std; 
// to find gcd 
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long modpow(int base ,int exp ,int mod){
     int result = 1;
     base = base % mod;
     while(exp >0){
          if(exp%2!=0){
               result = (base * result)%mod;
          }
          exp = exp>>1;
          base = (base * base) % mod;
     }
     return result;
}

int main() 
{ 
    // 2 random prime numbers 
    int p = 11; 
    int q = 13; 
    int n = p * q; 
    int count; 
    int totient = (p - 1) * (q - 1); 
    // public key 
    // e stands for encrypt 
    int e = 7; 
    // for checking co-prime which satisfies e>1 
    while (e < totient) 
    { 
        count = gcd(e, totient); 
        if (count == 1) 
            break; 
        else 
            e++; 
    } 

//     double k = 2; 
    // choosing d such that it satisfies d*e = 1 + k * totient 
    // Find d such that d*e % totient = 1, here using a simple method for demonstration:
    int d = 1;
    while ((d * e) % totient != 1) {
        d++;
    }

    
    int msg = 13; 
    int c = modpow(msg, e , n); 
    int m = modpow(c, d,n); 
    
    cout << "Message data = " << msg; 
    cout << "\n" 
         << "p = " << p; 
    cout << "\n" 
         << "q = " << q; 
    cout << "\n" 
         << "n = pq = " << n; 
    cout << "\n" 
         << "totient = " << totient; 
    cout << "\n" 
         << "e = " << e; 
    cout << "\n" 
         << "d = " << d; 
    cout << "\n" 
         << "Encrypted data = " << c; 
    cout << "\n" 
         << "Original Message sent = " << m; 
    return 0; 
} 
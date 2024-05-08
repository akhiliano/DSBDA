#include <iostream>
#include <cmath>

using namespace std;

// Function to find gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function for modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd, multiply the base with result
            result = (result * base) % mod;
        exp = exp >> 1;  // exp = exp / 2
        base = (base * base) % mod;  // base = base * base
    }
    return result;
}

int main() {
    int p = 11;
    int q = 13;
    int n = p * q;
    int totient = (p - 1) * (q - 1);

    int e = 7;
    while (e < totient) {
        if (gcd(e, totient) == 1)
            break;
        else
            e++;
    }

    // Find d such that d*e % totient = 1, here using a simple method for demonstration:
    int d = 1;
    while ((d * e) % totient != 1) {
        d++;
    }

    int msg = 13; // Original message must be less than n
    long long c = modPow(msg, e, n); // Encrypt
    long long m = modPow(c, d, n); // Decrypt

    cout << "Message data = " << msg << "\n";
    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";
    cout << "n = pq = " << n << "\n";
    cout << "totient = " << totient << "\n";
    cout << "e = " << e << "\n";
    cout << "d = " << d << "\n";
    cout << "Encrypted data = " << c << "\n";
    cout << "Decrypted Message = " << m << "\n";

    return 0;
}

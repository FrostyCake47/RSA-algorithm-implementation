#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED

#define ull unsigned long long

ull int gcd(int a, int b);

ull int lcm(int a, int b);

ull int encrypt(int m, int e, int n);

ull int decrypt(int c, int d, int n);

ull int mod_mult_inv(int n, int a, int t1, int t2);

bool isPrime(int n);

int generate_prime(int MIN, int MAX);

#endif // RSA_H_INCLUDED

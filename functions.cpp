#include <cmath>
#include <ctime>
#include <cstdlib>
#define ull unsigned long long

ull int gcd(int a, int b){ //Euclidean Algorithm

    if(b == 0) return a;

    return gcd(b, a%b);

}

ull int lcm(int a, int b){

    return (a*b)/gcd(a,b);

}

ull int encrypt(int m, int e, int n){

    return ((ull)pow(m,e))%n;

}

ull int decrypt(int c, int d, int n){

    return ((ull)pow(c,d))%n;

}

ull int mod_mult_inv(int n, int a, int t1, int t2){ //Extended euclidean algorithm is used

    static int mod = n;

    //base case
    if(a == 0){

        if(t1%mod >= 0) return t1%mod;

        else return t1%mod + mod;
    }

    //recursive case

    return mod_mult_inv(a, n%a, t2, t1 - (t2*(n/a)));

}

bool isPrime(int n) //Function may not be used due to the size limitation of int
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int generate_prime(int MIN, int MAX){ //Function may not be used due to the size limitation of int

    srand(time(0));

    int num;

    num = rand()%(MAX - MIN + 1) + MIN;

    if(isPrime(num)) return num;
    else return generate_prime(MIN, MAX);

}

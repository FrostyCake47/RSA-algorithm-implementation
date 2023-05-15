#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include "rsa.h" //"rsa.h" instead of <rsa.h> tells the compiler to look in to the current or custom folders first rather than the system folder

#define ull unsigned long long

using namespace std;

int main(){

    srand(time(0));

    //Key generation

    int p, q;

    do{

        p = 7; //generate_prime(1, 20); //Generates primes p and q until they are unequal
        q = 13; //generate_prime(1, 20);

    }while(p == q);

    // p and q are given explicit values here. Please check readme.cpp for clarification

    cout<<"p = "<<p<<" q = "<<q<<endl;

    int n = p*q, lambda_n=lcm(p-1,q-1); //Carmichael's function

    cout<<"n = "<<n<<" \nlambda_n = "<<lambda_n<<endl;

    //choosing e

    int e;

    do{

        e = 5; //rand()%(18) + 3; //Generates a number in (2, 20]

    }while(gcd(e, lambda_n) != 1); //gcd(e,lambda_n) = 1;

    cout<<"e = "<<e<<endl;

    //Public key is (n, e)

    int d = mod_mult_inv(lambda_n , e, 0, 1); //Initial values of t1 and t2 are 0 and 1 respectively for calculating the modular multiplicative ??inverse

    //Kindly check readme_theory for more information

    cout<<"d = "<<d<<endl;

    //Private key is (d)

    int m;

    do{
        cout<<"Enter a number between 0 and 10: ";
        cin>>m;
        cout<<"\n";

    }while(m<1 || m>9); // m belongs to (0,10) This constraint is also to help the size limitation of int

    //Encryption
    //Solving c congruent to m raised to e (mod n) simplest way

    int c = encrypt(m, e, n);

    //c is the encrypted block

    cout<<"Encrypted block: "<<c<<"\n"<<endl;;

    //Decryption
    //Solving m congruent to c raised to d (mod n) simplest way

    int decrypted_message = decrypt(c, d, n);

    cout<<"Decrypted message: "<<decrypted_message<<endl;

    return 0;

}

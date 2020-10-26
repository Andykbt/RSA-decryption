//
//  RSA.h
//  Assignment 1 RSA
//
//  Created by Andy Truong on 28/9/20.
//  Copyright © 2020 Andy Truong. All rights reserved.
//

#ifndef RSA_h
#define RSA_h
class RSA {
private:
    int p, q, m, n, phi;
    double c, d, e, decryptedText;
public:
    RSA(int p, int q, int e, int m) {
        this->p = p;
        this->q = q;
        this->e = e;
        this->m = m;
        
        n = p*q;    //calculate n
        phi = (p-1)*(q-1);  //calculate phi
        
        if (isValidInputs()) {
            encrypt();
            printResults();
        } else
            cout << "##### Inputs are invalid #####" << endl;
    }
    
    bool isPrime(int n) {
        if (n <= 1)
              return false;
        
          // Check from 2 to n-1
          for (int i = 2; i < n; i++)
              if (n % i == 0)
                  return false;
        
          return true;
    }
    
    int modInverse(int a, int m){
        a = a % m;
        for (int x = 1; x < m; x++)
           if ((a * x) % m == 1)
              return x;
        return 0;
    }
    
    /*int gcd(int a, int b) {
        int t;
        while (1) {
            t = a % b;
            if (t == 0)
                return b;
            a = b;
            b = t;
        }
    }*/
    
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    
    double squareMultiply(int base, int exponent, int n) {
        int binary[32]; //hold exponent converted to bits
        int k = 0; //number of bits
        
        //convert exponent to binary
        while (exponent > 0) {
            binary[k] = exponent % 2;
            exponent = exponent / 2;
            k++;
        }
        
        k--;
        int c = 0, d = 1;
        for (int i = k; i >= 0; i--) {
            c = 2 * c;
            d = (d * d) % n;
            
            if (binary[i] == 1) {
                c = c + 1;
                d = (d * base) % n;
            }
            //cout << "i: " << i << " bi: " << binary[i] << " c: " << c << " d: " << d << endl;
        }
        
        return d;
    }
    
    bool isValidInputs() {
        if (isPrime(p) && isPrime(q) && p != q && gcd(e, phi) == 1)
            return true;
        else
            return false;
    }
    
    void printResults() {
        cout << "#### RESULTS #####" << endl;
        cout << "----- INPUTS ----- " << endl;
        cout << "p: " << p << ", q: " << q << ", e: " << e << ", m: " << m << endl;
        cout << "----- DERIVED VALUES -----" << endl;
        cout << "n: " << n << endl;
        cout << "phi: " << phi << endl;
        cout << "d: " << d << endl;
        cout << "cipherText: " << c << endl;
        cout << "decrypted plaintext: " << decryptedText << endl;
        cout << "#################" << endl;
    }
    
    void encrypt() {
        int tmp;
        //check 1 < e < phi(n) and gcd(e, phi(n))
        while (e < phi) {
            tmp = gcd(e, phi);
            if (tmp == 1)
                break;
            else;
                e++;
        }
        
        c = squareMultiply(m, e, n);
        d = modInverse(e, phi);
        
        decryptedText = squareMultiply(c, d, n);
    }
};

#endif /* RSA_h */

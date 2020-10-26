//
//  main.cpp
//  Assignment 1 RSA
//
//  Created by Andy Truong on 28/9/20.
//  Copyright © 2020 Andy Truong. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

#include "RSA.h"

int main(int argc, const char * argv[]) {
    int p, q, e, m;
    cout << "*** RSA Encryption ***" << endl;
    cout << "Enter p: ";
    cin >> p;
    cout << "Enter q: ";
    cin >> q;
    cout << "Enter e: ";
    cin >> e;
    cout << "Enter m: ";
    cin >> m;
    
    
    RSA r(p, q, e, m);
    return 0;
}

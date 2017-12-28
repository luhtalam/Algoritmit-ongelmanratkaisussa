/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luhtalam
 *
 * Created on 10. tammikuuta 2017, 19:31
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    long long n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n++;
        }
    }
    cout << n;
}


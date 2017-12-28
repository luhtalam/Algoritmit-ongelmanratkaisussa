/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luhtalam
 *
 * Created on 10. tammikuuta 2017, 19:49
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    long double pi = 3.14159265358979323846264338327950288 ;
    long double V = 4;
    long double r;
    cout << setprecision(6)  << fixed;
    cin >> r;
    V = V*pi*r*r*r/3;
    cout << V;
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luhtalam
 *
 * Created on 10. tammikuuta 2017, 19:37
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cin.sync_with_stdio(false);
    int n, a;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        cout << sum << " ";
    }
}


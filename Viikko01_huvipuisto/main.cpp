/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luhtalam
 *
 * Created on 10. tammikuuta 2017, 21:54
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n, max;
    cin >> n >> max;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i]; 
    }
    sort(c.begin(), c.end());
    int numb = 0;
    int b, a = 0;
    b = n-1;
    while(a <= b) {
        numb++;
        if(c[a]+c[b] <= max) {
            a++;
            b--;
        } else {
            b--;
        }
    }
    cout << numb;
}


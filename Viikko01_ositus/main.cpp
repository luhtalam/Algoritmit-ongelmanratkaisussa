/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luhtalam
 *
 * Created on 10. tammikuuta 2017, 22:08
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> numbers;

bool ok(long long sum) {
    int c = 1;
    long long counter = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] > sum) return false;
        counter += numbers[i];
        if (counter > sum) {
            c++;
            counter = numbers[i];
        }
    }
    return c <= k;
}

int main(int argc, char** argv) {
    cin.sync_with_stdio(0);
    cin >> n >> k;
    int max = 0;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        numbers.push_back(a);
    }
    long long sum = 0;
    for (long long i = 1e12; i >= 1; i /= 2) {
        while (!ok(sum + i)) sum += i;
    }
    cout << sum + 1;
    return 0;
}


#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include "utils.h"
#include "math.h"
#include <cctype>
using namespace std;

int closestPow2(int n) {
    int res = 1;
    while (res <= n) {
        res = res * 2;
    }
    return res/2;
}

int intlog(int base, int x) {
    return (int)(log(x) / log(base));
}

int caseInsensitive(const string str1, const string str2) {
    for ( int i = 0; i < str1.length(); i++ ) {
        toupper(str1[i]);
    } 
    for ( int i = 0; i < str2.length(); i++ ) {
        toupper(str2[i]);
    }

    if ( str1 > str2 ) {
        return 1;
    } else {
        return -1;
    }
}
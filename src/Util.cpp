#include "Util.hpp"
#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <gmp.h>
using namespace std;

bool Util::isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;

    int range = sqrt(x);
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int i = 5; i <= range; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

bool Util::isRelativelyPrime(int x, int y) {
    return gcd(x,y) == 1;
}

int Util::getDecryptionKey(int toitentN, int e) {
    int k = 0;
    while (true) {
        if ((1+toitentN*k) % e == 0) {
            break;
        }
        k++;
    }
    return (1+toitentN*k)/e;
}

vector<string> Util::turingify(string text) {
    vector<string> turing;
    turing.push_back("B");
    for (int i = 0; i < text.length(); i++) {
        turing.push_back(text.substr(i,1));
    }
    turing.push_back("B");
    return turing;
}

string Util::crypt(string text, int key, int n) {
    int notText = stoi(text);
    mpz_t base, exponent, mod, result;
    mpz_init(base);
    mpz_init(exponent);
    mpz_init(mod);
    mpz_init(result);
    mpz_set_ui(base, notText);
    mpz_set_ui(exponent, key);
    mpz_set_ui(mod, n);
    mpz_powm(result,base,exponent,mod);
    char *str = mpz_get_str(nullptr, 10, result);
    string res(str);
    free(str);
    return res;
}

string Util::forceDigit(string value, int digits) {
    try {
        ostringstream oss;
        oss << setw(digits) << setfill('0') << stoi(value);
        return oss.str();
    } catch (exception e) {
        return value;
    }
}
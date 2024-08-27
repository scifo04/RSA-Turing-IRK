#include "Util.hpp"
#include "Serialize.hpp"
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

vector<int> Util::getDecryptionKey(int toitentN, int e) {
    vector<int> recList;
    int k = 0;
    while (recList.size() <= 5) {
        if ((1+toitentN*k) % e == 0) {
            recList.push_back((1+toitentN*k)/e);
        }
        k++;
    }
    return recList;
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

vector<string> Util::stringEncryption(vector<string> list, int enKey, int n) {
    vector<string> newList(list);
    for (int i = 1; i < newList.size()-1; i++) {
        newList[i] = Util::forceDigit(Util::crypt(Serialize::createSerial(list[i]),enKey,n),to_string(n).length());
    }
    return newList;
}

vector<string> Util::stringDecryption(vector<string> list, int deKey, int n) {
    vector<string> newList(list);
    for (int i = 1; i < newList.size()-1; i++) {
        newList[i] = Serialize::numericEq.at(Util::forceDigit(Util::crypt(newList[i],deKey,n),2));
    }
    return newList;
}

void Util::printEncryptDecryptList(vector<string> enc, vector<string> dec) {
    cout << "Regular Method: " << "\n";
    cout << "Encryption Result: ";
    for (int i = 1; i < enc.size()-1; i++) {
        cout << enc[i] << " ";
    }
    cout << "\n" << "Decryption Result: ";
    for (int i = 1; i < dec.size()-1; i++) {
        cout << dec[i];
    }
    cout << "\n";
}
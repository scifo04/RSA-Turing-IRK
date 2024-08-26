#include <iostream>
#include "Engine.hpp"
#include "Serialize.hpp"
#include "Util.hpp"
#include "Turing.hpp"
#include <string>
#include <vector>
using namespace std;

Engine::Engine() {
    cout << "Please insert the regular text: ";
    getline(cin, text);
    plainChar = Util::turingify(text);
    p = 1; q = 1;
    while (!Util::isPrime(p)) {
        cout << "Insert the p-value: ";
        cin >> p;
        if (!Util::isPrime(p)) {
            cout << "The number inserted is not prime" << "\n";
        }
    }
    while (!Util::isPrime(q)) {
        cout << "Insert the q-value: ";
        cin >> q;
        if (!Util::isPrime(q)) {
            cout << "The number inserted is not prime" << "\n";
        }
    }
    n = p*q;
    toitentN = (p-1)*(q-1);
    e = 2;
    cout << "The toitent N value is " << toitentN << "!\n";
    while (!Util::isRelativelyPrime(toitentN, e)) {
        cout << "Insert the encryption key: ";
        cin >> e;
        if (!Util::isRelativelyPrime(toitentN, e)) {
            cout << "The number inserted is not relatively prime to toitent N" << "\n";
        }
    }
    vector<int> recs = Util::getDecryptionKey(toitentN, e);
    cout << "The decryption keys (First five are " << recs[0] << ", " << recs[1] << ", " << recs[2] << ", " << recs[3] << ", " << recs[4] << "): " << "\n";
    cout << "Choose your decryption key: ";
    while (true) {
        cin >> d;
        if (e*d % toitentN == 1) {
            break;
        } else {
            cout << "This number's modulus to toitent N is not 1" << "\n";
            cout << "Choose your decryption key: ";
        }
    }
    Turing t(plainChar, e, d, n);
    t.encrypt();
    t.decrypt();
    cout << "\n";
    t.printEncryptAndDecrypt();
}
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Turing.hpp"
#include "Util.hpp"
#include "Serialize.hpp"
#include <map>
#include <tuple>
using namespace std;

const map<pair<string,string>,tuple<string,string,string>> Turing::turingDictEncrypt = {
    {make_pair("q0","PlainText"),make_tuple("q0","Serialize","R")},
    {make_pair("q0","B"),make_tuple("q1","B","L")},
    {make_pair("q1","Serialize"),make_tuple("q1","Encrypt","L")},
    {make_pair("q1","B"),make_tuple("q2","B","R")}
};

const map<pair<string,string>,tuple<string,string,string>> Turing::turingDictDecrypt = {
    {make_pair("q0","Encrypt"),make_tuple("q0","Decrypt","R")},
    {make_pair("q0","B"),make_tuple("q1","B","L")},
    {make_pair("q1","Decrypt"),make_tuple("q1","PlainText","L")},
    {make_pair("q1","B"),make_tuple("q2","B","R")}
};

Turing::Turing(vector<string> tape, int encryptionKey, int decryptionKey, int n) {
    this->tape = tape;
    this->encryptionKey = encryptionKey;
    this->decryptionKey = decryptionKey;
    this->n = n;
    this->currIndex = 1;
}

void Turing::encrypt() {
    this->states.clear();
    bool isSimulated = false;
    vector<string> statusMap(tape);
    for (int i = 1; i < statusMap.size()-1; i++) {
        statusMap[i] = "PlainText";
    }
    this->initialState = "q0";
    this->states.push_back("q0");
    this->states.push_back("q1");
    this->states.push_back("q2");
    this->finalState = "q2";
    string showings;
    cout << "Choose Printing Methods (Simulate/Skip): ";
    cin >> showings;
    if (showings == "Simulate") {
        isSimulated = true;
    }
    if (isSimulated) {
        printTuring();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    while (initialState != finalState) {
        tuple<string,string,string> resStatus = turingDictEncrypt.at(make_pair(initialState,statusMap[currIndex]));
        initialState = get<0>(resStatus);
        statusMap[currIndex] = get<1>(resStatus);
        if (statusMap[currIndex] == "Serialize") {
            tape[currIndex] = Serialize::createSerial(tape[currIndex]);
        } else if (statusMap[currIndex] == "Encrypt") {
            tape[currIndex] = Util::crypt(tape[currIndex],encryptionKey,n);
        }
        if (isSimulated) {
            printTuring();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        if (get<2>(resStatus) == "R") {
            currIndex++;
        } else {
            currIndex--;
        }
    }
    cout << "Encryption Result: ";
    for (string s: tape) {
        if (s != "B") {
            cout << Util::forceDigit(s,to_string(n).length());
        }
    }
    this->encrypted = tape;
    cout << "\n";
}

void Turing::decrypt() {
    this->states.clear();
    bool isSimulated = false;
    vector<string> statusMap(tape);
    for (int i = 1; i < statusMap.size()-1; i++) {
        statusMap[i] = "Encrypt";
    }
    this->initialState = "q0";
    this->states.push_back("q0");
    this->states.push_back("q1");
    this->states.push_back("q2");
    this->finalState = "q2";
    string showings;
    cout << "Choose Printing Methods (Simulate/Skip): ";
    cin >> showings;
    if (showings == "Simulate") {
        isSimulated = true;
    }
    if (isSimulated) {
        printTuring();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    while (initialState != finalState) {
        tuple<string,string,string> resStatus = turingDictDecrypt.at(make_pair(initialState,statusMap[currIndex]));
        initialState = get<0>(resStatus);
        statusMap[currIndex] = get<1>(resStatus);
        if (statusMap[currIndex] == "Decrypt") {
            tape[currIndex] = Util::crypt(tape[currIndex],decryptionKey,n);
        } else if (statusMap[currIndex] == "PlainText") {
            tape[currIndex] = Serialize::numericEq.at(Util::forceDigit(tape[currIndex],2));
        }
        if (isSimulated) {
            printTuring();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        if (get<2>(resStatus) == "R") {
            currIndex++;
        } else {
            currIndex--;
        }
    }
    cout << "Decryption Result: ";
    for (int i = 1; i < tape.size()-1; i++) {
        cout << tape[i];
    }
    this->decrypted = tape;
    cout << "\n";
}

void Turing::printTuring() {
    const string red = "\033[31m";
    const string reset = "\033[0m";
    for (int i = 0; i < tape.size(); i++) {
        if (i == currIndex) {
            if (tape[i] != " ") {
                cout << red << Util::forceDigit(tape[i],to_string(n).length()) << reset << " ";
            } else {
                cout << red << "[Space]" << reset << " ";
            }
        } else {
            if (tape[i] != " ") {
                cout << Util::forceDigit(tape[i],to_string(n).length()) << " ";
            } else {
                cout << "[Space]" << " ";
            }
        }
    }
    cout << "\n" << "\n";
}
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

class Turing {
    private:
        static const map<pair<string,string>,tuple<string,string,string>> turingDictEncrypt;
        static const map<pair<string,string>,tuple<string,string,string>> turingDictDecrypt;
        vector<string> tape;
        int encryptionKey;
        int decryptionKey;
        int n;
        int currIndex;
        string initialState;
        vector<string> states;
        string finalState;
        vector<string> encrypted;
        vector<string> decrypted;
    public:
        Turing(vector<string>,int,int,int);
        void encrypt();
        void decrypt();
        void printTuring();
        void printEncryptAndDecrypt();
};
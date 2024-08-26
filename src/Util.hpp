#include <iostream>
#include <vector>
using namespace std;

class Util {
    public:
        static bool isPrime(int);
        static bool isRelativelyPrime(int,int);
        static vector<int> getDecryptionKey(int,int);
        static vector<string> turingify(string);
        static string crypt(string,int,int);
        static string forceDigit(string,int);
};
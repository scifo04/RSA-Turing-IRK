#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Serialize {
    private:
        static const map<char, string> serialEq;
    public:
        static string createSerial(string);
        static const map<string, string> numericEq;
};
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void decimalToHex (int hash) {
    std::stringstream ss;
    ss << std::hex << hash;
    string res = (ss.str());
    cout << "Generated hash: "<<res;
}

void hashFunction (string input, int sqrtNumArray[], int &hash) {
    int specialNum = 4154234;
    for (int i = 0; i < input.length(); i++) {
        hash = hash ^ (input[i]);
        hash = hash * specialNum;
        for(int ii = 0; ii < 4; ii++) {
            hash = hash ^ sqrtNumArray[ii];
        }
    }
}

int main(int argc, char* argv[])
{
    //Press 1 to the command line and enter data on your own or enter file name to read input from it
    int hash = 1;
    string textFile, input;
    ifstream inFile;
    std::stringstream buffer;
    // prime numbers below 100
    int primeNumbers[4] = {2, 17, 41, 59};
    // creating some numbers by sqrt prime numbers
    float sqrtNum;
    int sqrtNumArray[4];
    for (int i=0; i<4; i++) {
        sqrtNum = sqrt(primeNumbers[i])*100000000;
        sqrtNumArray[i] = sqrtNum;
    }
    if (argv[1][0] == '1' && argc >= 3) {
        for(int j=2; j<argc; j++) {
            hashFunction(argv[j], sqrtNumArray, hash);
        }
    }
    else if (argv[1][0] != '1' && argc == 2) {
        //reading from file but file name has to be existing
        textFile = argv[1];
        inFile.open(textFile.c_str());
        buffer << inFile.rdbuf();
        while(!buffer.eof()) {
            buffer >> input;
            hashFunction(input, sqrtNumArray, hash);
        }
    }
    else {
        cout << "this is executed\n";
        // if file or input is empty
    }

    decimalToHex(hash);
}

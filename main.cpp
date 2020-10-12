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
    cout << res;
    if ( res.length() < 8)
      cout << res[0];
    cout << " ";
}
// hash function which creates 4 different 8hex hashes
void hashFunction (string input, int sqrtNumArray[], int hash[], bool ifNull) {
    int sum = 0, multiplySum=1, sumOfBoth=0;
    if(ifNull) {
        sum += 128;
        multiplySum *= 128;
        sumOfBoth = sumOfBoth + sum + multiplySum;

        hash[0] = hash[0] ^ 128;
        hash[1] = hash[1] ^ sum;
        hash[2] = hash[2] ^ multiplySum;
        hash[3] = hash[3] ^ sumOfBoth;

        hash[0] = hash[0] * sqrtNumArray[0];
        hash[1] = hash[1] * sqrtNumArray[sum%4+4];
        hash[2] = hash[2] * sqrtNumArray[multiplySum%4+8];
        hash[3] = hash[3] * sqrtNumArray[sumOfBoth%4+12];

        for(int ii = 0; ii < 4; ii++) {
            hash[0] = hash[0] ^ sqrtNumArray[ii];
            hash[1] = hash[1] ^ sqrtNumArray[ii+4];
            hash[2] = hash[2] ^ sqrtNumArray[ii+8];
            hash[3] = hash[3] ^ sqrtNumArray[ii+12];
        }
    }
    else {
         for (int i = 0; i < input.length(); i++) {
            sum += (int)input[i];
            multiplySum *= ((int)input[i]);
            sumOfBoth = sumOfBoth + sum + multiplySum;

            hash[0] = hash[0] ^ (input[i]);
            hash[1] = hash[1] ^ sum;
            hash[2] = hash[2] ^ multiplySum;
            hash[3] = hash[3] ^ sumOfBoth;

            hash[0] = hash[0] * sqrtNumArray[((int)input[i])%4];
            hash[1] = hash[1] * sqrtNumArray[sum%4+4];
            hash[2] = hash[2] * sqrtNumArray[multiplySum%4+8];
            hash[3] = hash[3] * sqrtNumArray[sumOfBoth%4+12];

            for(int ii = 0; ii < 4; ii++) {
                hash[0] = hash[0] ^ sqrtNumArray[ii];
                hash[1] = hash[1] ^ sqrtNumArray[ii+4];
                hash[2] = hash[2] ^ sqrtNumArray[ii+8];
                hash[3] = hash[3] ^ sqrtNumArray[ii+12];
            }
        }
    }
}

int main(int argc, char* argv[])
{
    //Enter 1 to the command line and enter data on your own or enter file name only to read input from it
    int hash[4] ={1, 2, 3, 4};
    bool ifNull = false;
    string textFile, input;
    ifstream inFile;
    std::stringstream buffer;
    // prime numbers below 100
    int primeNumbers[16] = {2, 17, 41, 59, 7, 31, 67, 19, 83, 11, 47, 71, 5, 23, 53, 41};
    // creating some numbers by sqrt prime numbers
    double sqrtNum;
    int sqrtNumArray[16];
    for (int i=0; i<16; i++) {
        sqrtNum = sqrt(primeNumbers[i])*1000000;
        sqrtNumArray[i] = sqrtNum;
    }
    if (argv[1][0] == '1' && argc >= 3) {
        for(int j=2; j<argc; j++) {
            hashFunction(argv[j], sqrtNumArray, hash, ifNull);
        }
    }
    else if (argv[1][0] != '1' && argc == 2) {
        //reading from file but file name has to be existing
        textFile = argv[1];
        inFile.open(textFile.c_str());
        if (!inFile) {
            std::cerr << textFile << "failed to open";
        }
        else {
                // checking if file is empty
            if (inFile.peek() == std::ifstream::traits_type::eof()) {
                ifNull = true;
                hashFunction(input, sqrtNumArray, hash, ifNull);
            }
            else {
                buffer << inFile.rdbuf();
                while(!buffer.eof()) {
                    buffer >> input;
                    hashFunction(input, sqrtNumArray, hash, ifNull);
                }
            }
        }
    }
    else {
        // if input is empty
        ifNull = true;
        hashFunction(input, sqrtNumArray, hash, ifNull);
    }

    cout << "Generated hash: ";
    decimalToHex(hash[0]);
    decimalToHex(hash[1]);
    decimalToHex(hash[2]);
    decimalToHex(hash[3]);
    return 0;
}

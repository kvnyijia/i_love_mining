#include <iostream>
#include <iomanip>
#include "keccak.h"
#include <ctime>
#include <boost/multiprecision/cpp_int.hpp>
// #include <omp.h>
#include <thread>

using namespace std;
using namespace boost::multiprecision;

string dec2hex(uint256_t i, int width) {
    stringstream ioss;     
    string s_temp;         
    ioss << std::hex << i;      // Make ioss string as hex form
    ioss >> s_temp;

    if (width > s_temp.size()) {
        string s_0(width - s_temp.size(), '0');           // Padding zeros
        s_temp = s_0 + s_temp;                            // Combine
    }

    string s = s_temp.substr(s_temp.length() - width, s_temp.length());    // Pick right width
    return s;
}

string hex2ascii(string in) {
    int len = in.length();
    string newString;

    for (int i = 0; i < len; i += 2) {
        string byte = in.substr(i, 2);
        char chr = (char) (int) strtol(byte.c_str(), NULL, 16);
        newString.push_back(chr);
    }
    return newString;
}

void f(string ss, string ee) {
    string address = "f32fa30e2bfC68D83633388Bf4b2550250376Df9";
    string hex_i;
    address = string(64 - address.length(),'0') + address;
    Keccak keccak;
    uint256_t mask { "17179869184" };
    uint256_t max { "115792089237316195423570985008687907853269984665640564039457584007913129639935" };
    uint256_t zero { "0" };
    uint256_t begin { ss };
    uint256_t end { ee };
    // uint256_t base { "1300000000" };
    uint256_t base { "2400000000" };


    int cnt = 0;
    for (uint256_t i = begin + base; i < end; ++i) {
        hex_i = dec2hex(i, 64);
        string abi_encoded = hex_i + address;    // now it is a string
        string out = hex2ascii(abi_encoded);
        string hash = keccak(out);
        hash = "0x" + hash;
        uint256_t hashVal { hash };
        if (hashVal % mask == zero) {
            cout << "You find the answer " << i << " Here is the answer!" << endl;
        }
        
        ++cnt;
        if (cnt >= 100000000) {
            cnt = 0;
            cout << i << endl;
        }
    } // End for
}

int main() {
    clock_t start = clock();

    thread th1(f, "0", "14474011154664524427946373126085988481658748083205070504932198000989141204992");
    thread th2(f, "14474011154664524427946373126085988481658748083205070504932198000989141204992", "28948022309329048855892746252171976963317496166410141009864396001978282409984");
    thread th3(f, "28948022309329048855892746252171976963317496166410141009864396001978282409984", "43422033463993573283839119378257965444976244249615211514796594002967423614976");
    thread th4(f, "43422033463993573283839119378257965444976244249615211514796594002967423614976", "57896044618658097711785492504343953926634992332820282019728792003956564819968");
    thread th5(f, "57896044618658097711785492504343953926634992332820282019728792003956564819968", "72370055773322622139731865630429942408293740416025352524660990004945706024960");
    thread th6(f, "72370055773322622139731865630429942408293740416025352524660990004945706024960", "86844066927987146567678238756515930889952488499230423029593188005934847229952");
    thread th7(f, "86844066927987146567678238756515930889952488499230423029593188005934847229952", "101318078082651670995624611882601919371611236582435493534525386006923988434944");
    thread th8(f, "101318078082651670995624611882601919371611236582435493534525386006923988434944", "115792089237316195423570985008687907853269984665640564039457584007913129639935");

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();

    clock_t end = clock();

    cout<< (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}

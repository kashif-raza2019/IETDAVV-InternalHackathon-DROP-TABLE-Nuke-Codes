#include <cstdint>
#include <iostream>
#include <string>
using namespace std;
class Block {
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, const string& sDataIn);

    string GetHash();

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;
};

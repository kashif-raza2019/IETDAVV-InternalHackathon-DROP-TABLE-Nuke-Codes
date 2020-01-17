#include "SIHBlock.h"
#include "hash1.h"
#include <time.h>

Block::Block(uint32_t nIndexIn, const string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}
string Block::GetHash() {
    return _sHash; 
}
void Block::MineBlock (uint32_t nDifficulty) {
    char  cstr[nDifficulty +1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}
inline string Block::_CalculateHash() const {
    stringstream s;
   s << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(s.str());
}
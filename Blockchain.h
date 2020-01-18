
#include <cstdint>
#include <vector>
#include "SIHBlock.h"

using namespace std;
class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    uint32_t key;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

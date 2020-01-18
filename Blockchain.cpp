#include "Blockchain.h"
Blockchain::Blockchain() {
    key = 6;
}
void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.Block(_key);
}
Block Blockchain::_GetLastBlock() const {
    return Block.back();
}

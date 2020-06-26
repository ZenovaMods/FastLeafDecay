#pragma once

class BlockSource;
class BlockPos;

class LeafBlock {
public:
    static void runDecay(BlockSource&, const BlockPos&, int);
};
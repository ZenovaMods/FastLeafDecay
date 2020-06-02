#pragma once

#include <thread>
#include <memory>

class Block;
class BlockPos;
class Level;
struct ActorBlockSyncMessage;

class BlockActor {
private:
    char filler[0xD0];

public:
    virtual ~BlockActor();
};

class BlockSource {
private:
    const std::thread::id mOwnerThreadID;
    const bool mAllowUnpopulatedChunks;
    const bool mPublicSource;
    Level& mLevel;

public:
    virtual ~BlockSource();
    Level& getLevel() const {
        return mLevel;
    }
    Level& getLevel() {
        return mLevel;
    }
    const Level& getLevelConst() const {
        return mLevel;
    }
    void addToTickingQueue(const BlockPos&, const Block&, int, int);
    bool setBlock(const BlockPos&, const Block&, int, std::shared_ptr<BlockActor>, const ActorBlockSyncMessage*);
};
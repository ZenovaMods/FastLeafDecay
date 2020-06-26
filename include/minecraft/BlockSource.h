#pragma once

#include <thread>
#include <memory>

class Block;
class BlockPos;
class Level;
class Level2;
struct ActorBlockSyncMessage;

enum class TickingQueueType : unsigned char {
    Internal,
    Random
};

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
    Level2& getLevel2() const {
        return reinterpret_cast<Level2&>(mLevel);
    }
    Level2& getLevel2() {
        return reinterpret_cast<Level2&>(mLevel);
    }
    const Level2& getLevelConst2() const {
        return reinterpret_cast<Level2&>(mLevel);
    }
    void addToTickingQueue(const BlockPos&, const Block&, int, int);
    void _addToTickingQueue(const BlockPos&, const Block&, int, int, TickingQueueType);
    bool setBlock(const BlockPos&, const Block&, int, std::shared_ptr<BlockActor>, const ActorBlockSyncMessage*);
};
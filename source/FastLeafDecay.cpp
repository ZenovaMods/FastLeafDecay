#include "FastLeafDecay.h"
#include "main.h"

#include "minecraft/BlockSource.h"
#include "minecraft/Level.h"
#include "minecraft/LeafBlock.h"

#include <vector>
#include <tuple>
#include <iostream>
#include <memory>
#include <sstream>
#include <iomanip>

class CompoundTag;

static bool decay = false;
static int baseDecayTime = 12;
static int maxDecayTime = 24;
static int randomizationTime = maxDecayTime - baseDecayTime;

bool (*_setBlock)(BlockSource*, const BlockPos&, const Block&, int, void*, const ActorBlockSyncMessage*);
bool setBlock(BlockSource* self, const BlockPos& pos, const Block& block, int updateFlags, void* blockEntity, const ActorBlockSyncMessage* syncMsg) {
	bool ret = _setBlock(self, pos, block, updateFlags, blockEntity, syncMsg);
	if (decay) {
		if (FastLeafDecay::versionId == "1.14.60.5")
			self->addToTickingQueue(pos, block, baseDecayTime + self->getLevel().getRandom().nextInt(randomizationTime), 0);
		else
			self->_addToTickingQueue(pos, block, baseDecayTime + self->getLevel2().getRandom().nextInt(randomizationTime), 0, TickingQueueType::Internal);
	}
	return ret;
}

void (*_LeafBlock_runDecay)(BlockSource&, const BlockPos&, int);
void LeafBlock_runDecay(BlockSource& region, const BlockPos& pos, int range) {
	decay = true;
	_LeafBlock_runDecay(region, pos, range);
	decay = false;
}

std::string FastLeafDecay::versionId;

void FastLeafDecay::Start() {
	//Zenova::Platform::DebugPause();
	Zenova_Info("FastLeafDecay start");
	versionId = GetManager().GetLaunchedVersion();
	InitVersionPointers(versionId);

	Zenova::Hook::Create(&LeafBlock::runDecay, &LeafBlock_runDecay, &_LeafBlock_runDecay);
	Zenova::Hook::Create(&BlockSource::setBlock, &setBlock, &_setBlock);
}

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new FastLeafDecay;
}

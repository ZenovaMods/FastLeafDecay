#include "Zenova.h"

#include "minecraft/BlockSource.h"
#include "minecraft/Level.h"

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
	if (decay)
		self->addToTickingQueue(pos, block, baseDecayTime + self->getLevel().getRandom().nextInt(randomizationTime), 0);
	return ret;
}

void (*_leafDecay)(BlockSource&, const BlockPos&, int);
void leafDecay(BlockSource& region, const BlockPos& pos, int range) {
	decay = true;
	_leafDecay(region, pos, range);
	decay = false;
}

void (*_beginCreativeGroup)(const std::string&, short, short, const CompoundTag*);
void beginCreativeGroup(const std::string& groupName, short id, short auxValue, const CompoundTag* userData) {
	return;
}


class FastLeafDecay : public Zenova::Mod {
	virtual void Start() {
		Zenova::Platform::DebugPause();
		std::cout << "FastLeafDecay start" << std::endl;

		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x16C4E10)), leafDecay, (void**)&_leafDecay);
		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1779860)), setBlock, (void**)&_setBlock);
		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1560AC0)), beginCreativeGroup, (void**)&_beginCreativeGroup);
	}

	virtual ~FastLeafDecay() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {}
};

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new FastLeafDecay;
}

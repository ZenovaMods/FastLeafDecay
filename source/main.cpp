// This file was automatically generated using tools/process_csv.py
// Generated on Thu Jun 25 2020 22:13:54 UTC

#include "main.h"


extern "C" {
	void* __genRandInt32_Random_Core__AEAAIXZ_ptr;
	void* _addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr;
	void* __addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HHW4TickingQueueType___Z_ptr;
	void* _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr;
	void* _runDecay_LeafBlock__SAXAEAVBlockSource__AEBVBlockPos__H_Z_ptr;
}

static std::unordered_map<std::string, size_t> pointerList[3];

void InitBedrockPointers() {
	pointerList[0]["1.14.60.5"] = 0x01AC370;
	pointerList[0]["1.16.0.2"] = 0x01D2B70;
	_addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1778AB0));
	__addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HHW4TickingQueueType___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x18C9E30));
	pointerList[1]["1.14.60.5"] = 0x1779860;
	pointerList[1]["1.16.0.2"] = 0x18CAA00;
	pointerList[2]["1.14.60.5"] = 0x16C4E10;
	pointerList[2]["1.16.0.2"] = 0x17DDA20;
}

void InitVersionPointers(std::string versionId) {
	__genRandInt32_Random_Core__AEAAIXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(pointerList[0][versionId]));
	_setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(pointerList[1][versionId]));
	_runDecay_LeafBlock__SAXAEAVBlockSource__AEBVBlockPos__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(pointerList[2][versionId]));
}

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) InitBedrockPointers();
	return TRUE;
}

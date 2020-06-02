// This file was automatically generated using tools/process_csv.py
// Generated on Tue Jun 02 2020 15:51:02 UTC

#include <Zenova/Hook.h>


extern "C" {
	void* __genRandInt32_Random_Core__AEAAIXZ_ptr;
	void* _addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr;
	void* _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr;
}

void InitBedrockPointers() {
	__genRandInt32_Random_Core__AEAAIXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x01AC370));
	_addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1778AB0));
	_setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1779860));
}

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) InitBedrockPointers();
	return TRUE;
}

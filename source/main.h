// This file was automatically generated using tools/process_csv.py
// Generated on Thu Jun 25 2020 22:13:54 UTC

#pragma once

#include <Zenova/Hook.h>

extern "C" {
	extern void* __genRandInt32_Random_Core__AEAAIXZ_ptr;
	extern void* _addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr;
	extern void* __addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HHW4TickingQueueType___Z_ptr;
	extern void* _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr;
	extern void* _runDecay_LeafBlock__SAXAEAVBlockSource__AEBVBlockPos__H_Z_ptr;
}

void InitBedrockPointers();
void InitVersionPointers(std::string);

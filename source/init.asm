; This file was automatically generated using tools/process_csv.py
; Generated on Thu Jun 25 2020 22:13:54 UTC
bits 64
SECTION .data
extern __genRandInt32_Random_Core__AEAAIXZ_ptr
extern _addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr
extern __addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HHW4TickingQueueType___Z_ptr
extern _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr
extern _runDecay_LeafBlock__SAXAEAVBlockSource__AEBVBlockPos__H_Z_ptr

SECTION .text
global ?_genRandInt32@Random@Core@@AEAAIXZ
?_genRandInt32@Random@Core@@AEAAIXZ:
	mov rax, [rel __genRandInt32_Random_Core__AEAAIXZ_ptr]
	jmp rax
global ?addToTickingQueue@BlockSource@@QEAAXAEBVBlockPos@@AEBVBlock@@HH@Z
?addToTickingQueue@BlockSource@@QEAAXAEBVBlockPos@@AEBVBlock@@HH@Z:
	mov rax, [rel _addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HH_Z_ptr]
	jmp rax
global ?_addToTickingQueue@BlockSource@@QEAAXAEBVBlockPos@@AEBVBlock@@HHW4TickingQueueType@@@Z
?_addToTickingQueue@BlockSource@@QEAAXAEBVBlockPos@@AEBVBlock@@HHW4TickingQueueType@@@Z:
	mov rax, [rel __addToTickingQueue_BlockSource__QEAAXAEBVBlockPos__AEBVBlock__HHW4TickingQueueType___Z_ptr]
	jmp rax
global ?setBlock@BlockSource@@QEAA_NAEBVBlockPos@@AEBVBlock@@HV?$shared_ptr@VBlockActor@@@std@@PEBUActorBlockSyncMessage@@@Z
?setBlock@BlockSource@@QEAA_NAEBVBlockPos@@AEBVBlock@@HV?$shared_ptr@VBlockActor@@@std@@PEBUActorBlockSyncMessage@@@Z:
	mov rax, [rel _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HV_$shared_ptr_VBlockActor___std__PEBUActorBlockSyncMessage___Z_ptr]
	jmp rax
global ?runDecay@LeafBlock@@SAXAEAVBlockSource@@AEBVBlockPos@@H@Z
?runDecay@LeafBlock@@SAXAEAVBlockSource@@AEBVBlockPos@@H@Z:
	mov rax, [rel _runDecay_LeafBlock__SAXAEAVBlockSource__AEBVBlockPos__H_Z_ptr]
	jmp rax

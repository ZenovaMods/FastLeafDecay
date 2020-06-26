#pragma once

#include "Zenova.h"

class FastLeafDecay : public Zenova::Mod {
public:
	static std::string versionId;

private:
	virtual void Start();
	virtual ~FastLeafDecay() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {
		Zenova_Info("FastLeafDecay Stop");
	}
};
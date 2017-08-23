#pragma once
#include "IBehaviour.h"

class DrunkenModifier : IBehaviour
{

public:
	DrunkenModifier();
	~DrunkenModifier();

	void Update(Player* The_Player) override;

private:

};
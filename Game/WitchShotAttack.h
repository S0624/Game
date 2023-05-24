#pragma once
#include "MoveTypeBase.h"
class WitchShotAttack : MoveTypeBase
{
public:
	WitchShotAttack();
	virtual ~WitchShotAttack(){}

	void Init();

	int IndexX() { return m_animeWidth; }
	int IndexY() { return m_animeHight; }
	int ShiftX() { return m_shiftX; }
	int AnimeMax() { return m_animeMax; }
private:
	int m_animeHight;
	int m_animeWidth;
	int m_shiftX;
	int m_animeMax;
};


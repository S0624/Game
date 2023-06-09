#pragma once
#include"PlayerBase.h"

// 必要なクラスの宣言
class WitchIdle;
class WitchShotAttack;
class WitchLongShotAttack;
class WitchCharge;
class Chicken;
class KnightCat;

class Witch : PlayerBase
{
public:
	Witch();
	virtual ~Witch();

	void Init();
	void Update();
	void Draw();

private:
	WitchIdle* m_pIdle;
	WitchShotAttack* m_pShot;
	WitchLongShotAttack* m_pLongShot;
	WitchCharge* m_pCharge;
	Chicken* m_pChicken;
	KnightCat* m_pKnightCat;

	int m_handle;
	int m_animeHight;
	int m_animeWidth;
	bool m_reversal;
	int m_imageX;
	int m_imageY;
	int m_animeLoopCount;
	int m_LoopCount;
	int m_animeFrame;
	int m_animeMax;
	int m_indexX;
	int m_shiftX;
	bool m_animeFlag;
};


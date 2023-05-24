#pragma once
#include "MoveTypeBase.h"
class Chicken : MoveTypeBase
{
public:
	Chicken();
	virtual ~Chicken();
	void Init();
	void Update();
	void Draw();

	void SetPos(Vec2 pos);
	void SetFlag(bool flag) { m_exist = flag; }
	bool IsExist() { return m_exist; }
private:
	int m_handle;
	Vec2 m_pos;
	int m_animeFrame;
	int m_animeMax;
	int m_animeWidth;
	int m_animeHight;
	bool m_exist;
};


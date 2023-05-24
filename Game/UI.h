#pragma once
#include"Vec2.h"
class UI
{
public:
	UI();
	~UI(){};

	void Init(){}
	void Update();
	void Draw();
private:
	Vec2 m_pos1;
	int m_life1;
	int m_damage1;
	int m_empty1;
	int m_countFrame1;

	Vec2 m_pos2;
	int m_life2;
	int m_damage2;
	int m_empty2;
	int m_countFrame2;
};
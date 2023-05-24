#include "UI.h"
#include "DxLib.h"
#include"game.h"
#include"Pad.h"

namespace
{
	const int kWidthGauge = 100;
	const int kHightGauge = 25;
}

UI::UI()
{
	m_pos1 = {680,50};
	m_life1 = 100;
	m_damage1 = 0;
	m_empty1 = 100;
	m_countFrame1 = 0;
	m_pos2 = {100,50};
}

void UI::Update()
{
	Pad::update();
	m_damage1 = 0;
	m_countFrame1++;
	if (m_countFrame1 >= 60)
	{
		m_empty1 = m_life1;
		m_countFrame1 = 0;
	}
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_damage1 -= 10;
		m_countFrame1 = 0;
	}
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		m_damage1 -= 20;
		m_countFrame1 = 0;
	}

	m_life1 += m_damage1;
	if (m_life1 <= 0)
	{
		m_empty1 = 0;
		m_life1 = 0;
	}
	printfDx("%d\n", m_life1);
}

void UI::Draw()
{
	DrawLine(Game::kScreenWindth  / 2, 0, Game::kScreenWindth / 2, 600, 0xffffff);
	DrawBox(m_pos1.x, m_pos1.y, m_pos1.x + (5 * m_empty1), m_pos1.y + kHightGauge,0xff0000,true);
	DrawBox(m_pos1.x, m_pos1.y, m_pos1.x + (5 * m_life1), m_pos1.y + kHightGauge,0x00ff00,true);
	//DrawBox(700 - m_pos2.x, m_pos2.y, 500 - (5 * m_empty1)+ kWidthGauge, m_pos2.y + kHightGauge,0xff0000,true);
	//DrawBox(700 - m_pos2.x, m_pos2.y, 500 - (5 * m_life1)+ kWidthGauge, m_pos2.y + kHightGauge,0x00ff00,true);

	DrawFormatString(100, 0, 0x00ff00, "%d", m_countFrame1);
	/*
	時間　99
	100　外
	色変え
	*/
}

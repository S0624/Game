#include "Chicken.h"
#include"condition.h"
#include"DrawFunctions.h"
#include"game.h"

namespace
{
	const char* const kFilmName = "../Data/Niwatori.png";
}
Chicken::Chicken() :
	m_handle(0),
	m_pos(),
	m_animeFrame(0),
	m_animeMax(0),
	m_animeWidth(0),
	m_animeHight(0),
	m_exist(false)
{

}

Chicken::~Chicken()
{
	my::MyDeleteGraph(m_handle);
}

void Chicken::Init()
{
	m_animeWidth = 1;
	m_animeHight = 0;
	m_animeMax = 10;
	m_handle = my::MyLoadGraph(kFilmName);
}

void Chicken::Update()
{
	if (m_exist)
	{
		m_animeFrame++;
		if (m_animeFrame > 7)
		{
			m_animeHight++;
			m_pos.x += 45;
			m_animeFrame = 0;
		}
		if (m_animeHight >= m_animeMax)
		{
			m_animeHight = 0;
		}
		if (m_pos.x >= Game::kScreenWindth)
		{
			m_exist = false;
		}
	}
}

void Chicken::Draw()
{
	if (m_exist)
	{
		my::MyDrawRectRotaGraph(static_cast<int>(m_pos.x) + 30,
			static_cast<int>(m_pos.y),			//�\�����W
			32 * m_animeWidth, 32 * m_animeHight,			//�؂��荶��
			32, 32,							//���A����
			3.0f, 0.0f,						//�g�嗦�A��]�p�x
			m_handle, true, false);
	}
}

void Chicken::SetPos(Vec2 pos)
{
	m_pos.x = pos.x;
	m_pos.y = pos.y;
}

#include "Witch.h"
#include "DxLib.h"
#include"Pad.h"
#include"game.h"
#include"DrawFunctions.h"
#include "condition.h"
#include"WitchIdle.h"
#include"WitchShotAttack.h"
#include"WitchLongShotAttack.h"
#include"WitchCharge.h"
#include"Chicken.h"
#include"KnightCat.h"

namespace
{
    const char* const kFilmName = "../Data/Witch.png";
}

Witch::Witch() :
    m_handle(0),
    m_animeHight(0),
    m_animeWidth(0),
    m_reversal(false),
    m_imageX(0),
    m_imageY(0),
    m_animeLoopCount(1),
    m_LoopCount(1),
    m_animeFrame(0),
    m_animeMax(0),
    m_indexX(0),
    m_shiftX(0),
    m_animeFlag(false)
{
    m_pIdle = new WitchIdle;
    m_pShot = new WitchShotAttack;
    m_pLongShot = new WitchLongShotAttack;
    m_pCharge = new WitchCharge;
    m_pChicken = new Chicken;
    m_pKnightCat = new KnightCat;
}

Witch::~Witch()
{
    delete m_pIdle;
    delete m_pShot;
    delete m_pLongShot;
    delete m_pCharge;
    delete m_pChicken;
    delete m_pKnightCat;

    my::MyDeleteGraph(m_handle);
}

void Witch::Init()
{
    m_handle = my::MyLoadGraph(kFilmName);

    m_pIdle->Init();
    m_pShot->Init();
    m_pLongShot->Init();
    m_pCharge->Init();
    m_pChicken->Init();
    m_pKnightCat->Init();
}

void Witch::Update()
{
    Pad::update();
    m_pChicken->Update();
    m_pKnightCat->Update();
    m_animeFrame++;
    if (m_animeFrame > 10)
    {
        m_animeHight++;
        m_animeFrame = 0;
    }
    if (m_animeHight >= m_animeMax)
    {
        m_LoopCount++;
        m_animeHight = 0;
        if (m_LoopCount >= m_animeLoopCount)
        {
            m_indexX = 1;
            m_animeFlag = false;
            m_pos.x += -m_shiftX;
            m_shiftX = 0;
            m_LoopCount = 0;
            m_animeLoopCount = 1;

            if (m_moveType == static_cast<int>(moveType::Attack3))
            {
                if (!m_pChicken->IsExist())
                {
                    m_pChicken->SetPos(m_pos);
                }
                m_pChicken->SetFlag(true);
            }
            if (m_moveType == static_cast<int>(moveType::Attack4))
            {
                if (!m_pKnightCat->IsExist())
                {
                    m_pKnightCat->SetPos(m_pos);
                }
                m_pKnightCat->SetFlag(true);
            }
        }
    }

    
    if (!m_animeFlag)
    {
        if (Pad::isPress(PAD_INPUT_RIGHT))
        {
            m_pos.x += 10;
            m_reversal = false;
        }
        if (Pad::isPress(PAD_INPUT_LEFT))
        {
            m_pos.x -= 10;
            m_reversal = true;
        }
        if (Pad::isPress(PAD_INPUT_UP))
        {
            m_pos.y -= 10;
        }
        if (Pad::isPress(PAD_INPUT_DOWN))
        {
            m_pos.y += 10;
        }
    
        //���U��
        if (Pad::isTrigger(PAD_INPUT_1))
        {
            m_moveType = static_cast<int>(moveType::Attack1);// �U��1���
            m_animeFlag = true;
        }
        //���U��
        else if (Pad::isTrigger(PAD_INPUT_2))
        {
            m_moveType = static_cast<int>(moveType::Attack2);// �U��2���
            m_animeFlag = true;
            m_pos.x += 100;
        }
        else if (Pad::isTrigger(PAD_INPUT_3))
        {
            m_moveType = static_cast<int>(moveType::Attack3);// �U��3���
            m_animeFlag = true;
            m_animeLoopCount = 2;
        }
        else if (Pad::isTrigger(PAD_INPUT_4))
        {
            m_moveType = static_cast<int>(moveType::Attack4);// �U��4���
            m_animeFlag = true;
            m_animeLoopCount = 3;
        }
        else
        {
            m_moveType = static_cast<int>(moveType::Idol);// �A�C�h�����
        }


        if (m_moveType == static_cast<int>(moveType::Idol))
        {
            m_animeWidth = m_pIdle->IndexX();
            m_animeMax = m_pIdle->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack1))
        {
            m_animeWidth = m_pShot->IndexX();
            m_animeHight = m_pShot->IndexY();
            m_animeMax = m_pShot->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack2))
        {
            m_animeWidth = m_pLongShot->IndexX();
            m_animeHight = m_pLongShot->IndexY();
            m_indexX = m_pLongShot->SizeX();
            m_shiftX = m_pLongShot->ShiftX();
            m_animeMax = m_pLongShot->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack3))
        {
            m_animeWidth = m_pCharge->IndexX();
            m_animeHight = m_pCharge->IndexY();
            m_animeMax = m_pCharge->AnimeMax();
        }
        if (m_moveType == static_cast<int>(moveType::Attack4))
        {
            m_animeWidth = m_pCharge->IndexX();
            m_animeHight = m_pCharge->IndexY();
            m_animeMax = m_pCharge->AnimeMax();
        }

    }

}

void Witch::Draw()
{
    my::MyDrawRectRotaGraph(static_cast<int>(m_pos.x),
        static_cast<int>(m_pos.y),			//�\�����W
        48 * m_animeWidth, 48 * m_animeHight,			//�؂��荶��
        48 * m_indexX, 48,							//���A����
        3.0f, 0.0f,						//�g�嗦�A��]�p�x
        m_handle, true, m_reversal);

    m_pChicken->Draw();
    m_pKnightCat->Draw();
}
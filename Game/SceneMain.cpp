#include "SceneMain.h"
#include"Witch.h"


SceneMain::SceneMain()
{
    m_pWitch = new Witch;
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
    m_pWitch->Init();
}

void SceneMain::Update()
{
    m_pWitch->Update();
}

void SceneMain::Draw()
{
    m_pWitch->Draw();
}

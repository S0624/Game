#pragma once
class Witch;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();
	void Init();
	void Update();
	void Draw();
private:
	Witch* m_pWitch;
};


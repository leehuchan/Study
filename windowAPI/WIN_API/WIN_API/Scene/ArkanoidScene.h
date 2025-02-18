#pragma once

class Bar;
class ArkMap;
class Brick;


class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;


private:
	shared_ptr<ArkMap> _map;
	shared_ptr<Bar> _bar;

	shared_ptr<class HpBar> _ui_hpBar;

};
/// <summary>
/// プレイヤークラス
/// </summary>

#pragma once

//インクルード
#include "../Object.h"

#include <Keyboard.h>
#include "../../Camera/TpsCamera.h"

class Player:public Object3D
{
public:
	Player();
	~Player();

	//更新
	void Update();

	void SetKey(DirectX::Keyboard* key);

private:

	DirectX::Keyboard* KeyBoard;
	DirectX::Keyboard::KeyboardStateTracker Tracker;

	//操作によるアクション
	void Up();
	void Down();
	void Right();
	void Left();
	void Jamp();

	float Angie;

};
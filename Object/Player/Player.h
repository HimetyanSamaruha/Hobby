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

	float Angie;

};
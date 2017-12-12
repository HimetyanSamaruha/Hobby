/// <summary>
/// �v���C���[�N���X
/// </summary>

#pragma once

//�C���N���[�h
#include "../Object.h"

#include <Keyboard.h>
#include "../../Camera/TpsCamera.h"

class Player:public Object3D
{
public:
	Player();
	~Player();

	//�X�V
	void Update();

	void SetKey(DirectX::Keyboard* key);

private:

	DirectX::Keyboard* KeyBoard;
	DirectX::Keyboard::KeyboardStateTracker Tracker;

	//����ɂ��A�N�V����
	void Up();
	void Down();
	void Right();
	void Left();
	void Jamp();

	float Angie;

};
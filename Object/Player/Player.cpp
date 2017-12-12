#include "Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player()
	:KeyBoard(nullptr)
	,Angie(0.0f)
{
	Load(L"Resources/box.cmo");
}

Player::~Player()
{
}

void Player::Update()
{
	if (KeyBoard)
	{
		//キーボードの情報を更新
		Keyboard::State keystate = KeyBoard->GetState();
		Tracker.Update(keystate);

		if (keystate.W)	Up();
		if (keystate.S)	Down();
		
	}
	

	Object3D::Update();
}

void Player::SetKey(DirectX::Keyboard * key)
{
	this->KeyBoard = key;
}

void Player::Up()
{
	Vector3 moveV(0, 0, -0.1f);

	Matrix rotmat = Matrix::CreateRotationY(0);
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

void Player::Down()
{
	Vector3 moveV(0, 0, 0.1f);

	Matrix rotmat = Matrix::CreateRotationY(0);
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

void Player::Right()
{
}

void Player::Left()
{
}

void Player::Jamp()
{
}

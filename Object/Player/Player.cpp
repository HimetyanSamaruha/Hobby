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
		if (keystate.A) Left();
		if (keystate.D) Right();
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

	Matrix rotmat = Matrix::CreateRotationY(Angie);
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

void Player::Down()
{
	Vector3 moveV(0, 0, 0.1f);

	Matrix rotmat = Matrix::CreateRotationY(Angie);
	//移動量ベクトルを自機の角度分回転させる
	moveV = Vector3::TransformNormal(moveV, rotmat);
	Vector3 pos = this->GetTranslation();
	this->SetTranslation(pos + moveV);
}

void Player::Right()
{
	Angie = this->GetRotation().y;
	this->SetRotation(Vector3(0, Angie - 0.03f, 0));
}

void Player::Left()
{
	Angie = this->GetRotation().y;
	this->SetRotation(Vector3(0, Angie + 0.03f, 0));
}

void Player::Jamp()
{
}

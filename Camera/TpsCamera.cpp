#include "TpsCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

TpsCamera::TpsCamera(int w, int h):
	Camera(w,h)
{
	TargetPos = Vector3::Zero;
	TargetRot = 0.0f;
	TargetRotX = 0.0f;
	TargetRotZ = 0.0f;

	Keyboard = nullptr;	
	Object = nullptr;
}

void TpsCamera::Update()
{
	if (Keyboard)
	{
		Keyboard::State keyboardstate = Keyboard->GetState();
		Tracker.Update(keyboardstate);

		if (keyboardstate.IsKeyDown(Keyboard::Keys::Right))
		{
			TargetRot = TargetRot + 0.02f;
		}

		if (keyboardstate.IsKeyDown(Keyboard::Keys::Left))
		{
			TargetRot = TargetRot - 0.02f;
		}
	}

	Vector3 refpos, eyepos;

	//�f�o�b�N�p
	if (Object)
	{
		SetTrans(Object->GetTranslation());
	}
	
	
	//TPS�J����
	refpos = TargetPos + Vector3(0, 2, 0);

	Vector3 cameraV(0.0f, 0.0f, 5.0f);

	Matrix rotY = Matrix::CreateRotationY(TargetRot);
	Matrix rotX = Matrix::CreateRotationX(TargetRotX);
	Matrix rotZ = Matrix::CreateRotationX(0);

	Matrix rot = rotZ * rotX*rotY;//Matrix::CreateRotationY(TargetRot);
	cameraV = Vector3::TransformNormal(cameraV, rot);

	eyepos = refpos + cameraV;

	//�S���R�J����
	eyepos = Eyepos + (eyepos - Eyepos)*0.03f;
	refpos = Refpos + (refpos - Refpos)*0.15f;

	Seteyepos(eyepos);
	Setrefpos(refpos);

	Camera::Update();
}

void TpsCamera::SetTrans(DirectX::SimpleMath::Vector3 trangetpos)
{
	TargetPos = trangetpos;
}

void TpsCamera::SetAngle(float tragetangle)
{
	TargetRot = tragetangle;
}

void TpsCamera::SetAngleX(float tragetangle)
{
	TargetRotX = tragetangle;
}

void TpsCamera::SetAngleZ(float tragetangle)
{
	TargetRotZ = tragetangle;
}

void TpsCamera::SetKeyboard(DirectX::Keyboard * key)
{
	Keyboard = key;
}

void TpsCamera::SetObject3D(Object3D * object3D)
{
	Object = object3D;
}

float TpsCamera::GetAngle()
{
	return TargetRot;
}

float TpsCamera::GetAngleX()
{
	return TargetRotX;
}

float TpsCamera::GetAngleZ()
{
	return TargetRotZ;
}

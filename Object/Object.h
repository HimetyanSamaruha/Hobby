#include <Windows.h>
#include <wrl\client.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>

//��
#include "../../Camera.h"

#pragma once

class Object3D
{
public:
	//
	static void InitielizeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> _device,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context,
		Camera* _camera
	);

protected:

	//���f��
	std::unique_ptr<DirectX::Model> ModelDate;

	//�f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device> Device;

	//�e�L�X�g
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> Context;

	//�ėp�X�e�[�g
	static std::unique_ptr<DirectX::CommonStates> States;
	static std::unique_ptr<DirectX::EffectFactory> Factory;

	//�J����
	static Camera* ccamera;

	//�X�P�[�����O
	DirectX::SimpleMath::Vector3 Scale;
	//��]�p
	DirectX::SimpleMath::Vector3 Rotation;
	//���s
	DirectX::SimpleMath::Vector3 Translation;

	//�s��
	DirectX::SimpleMath::Matrix World;
	DirectX::SimpleMath::Vector3 RotatrionV;

	Object3D* Parent;

public:

	//�R���X�g���N�^
	Object3D();

	//�f�[�^�����[�h
	void Load(const wchar_t* fileName);

	//�X�V
	void Update();

	//�`��
	virtual void Draw();

	//�Z�b�g
	void SetScale(DirectX::SimpleMath::Vector3& _scale)
	{
		Scale = _scale;
	}
	void SetRotation(DirectX::SimpleMath::Vector3& _rotation)
	{
		Rotation = _rotation;
	}
	void SetTranslation(DirectX::SimpleMath::Vector3& _translation)
	{
		Translation = _translation;
	}
	void SetParent(Object3D* _parent)
	{
		Parent = _parent;
	}
	void SetWorld(DirectX::SimpleMath::Matrix _worlad)
	{
		World = _worlad;
	}
	void ReUpdate();

	//�Q�b�g
	const DirectX::SimpleMath::Vector3& GetScale()
	{
		return Scale;
	}
	const DirectX::SimpleMath::Vector3& GetRotation()
	{
		return Rotation;
	}
	const DirectX::SimpleMath::Vector3& GetTranslation()
	{
		return Translation;
	}
	const DirectX::SimpleMath::Matrix& GetWorld()
	{
		return World;
	}

	Object3D* GetParent()
	{
		return Parent;
	}
};
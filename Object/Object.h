#include <Windows.h>
#include <wrl\client.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>

//仮
#include "../Camera/Camera.h"

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

	//モデル
	std::unique_ptr<DirectX::Model> ModelDate;

	//デバイス
	static Microsoft::WRL::ComPtr<ID3D11Device> Device;
	//テキスト
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> Context;
	//汎用ステート
	static std::unique_ptr<DirectX::CommonStates> States;
	static std::unique_ptr<DirectX::EffectFactory> Factory;

	//カメラ
	static Camera* ccamera;

	//スケーリング
	DirectX::SimpleMath::Vector3 Scale;
	//回転角
	DirectX::SimpleMath::Vector3 Rotation;
	//平行
	DirectX::SimpleMath::Vector3 Translation;

	//行列
	DirectX::SimpleMath::Matrix World;
	DirectX::SimpleMath::Vector3 RotatrionV;

	Object3D* Parent;

public:

	//コンストラクタ
	Object3D();

	//データをロード
	void Load(const wchar_t* fileName);

	//更新
	void Update();

	//描画
	virtual void Draw();

	//セット
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

	//ゲット
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
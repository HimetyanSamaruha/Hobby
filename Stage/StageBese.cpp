#include "StageBese.h"

StageBese::StageBese()
{
}

StageBese::~StageBese()
{
}

void StageBese::Initialize()
{
	//�傫�����ĕ`�悳��ĂȂ�����
	Stage.Load(L"Resources/Sora.cmo");
}

void StageBese::Draw()
{
	Stage.Draw();
}

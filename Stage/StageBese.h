#pragma once

#include "../Object/Object.h"

//�X�e�[�W�̍���
class StageBese:public Object3D
{
private:

	Object3D Stage;

public:

	StageBese();

	~StageBese();

	void Initialize();

	void Draw() override;

};
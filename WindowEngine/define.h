#pragma once


// Singleton ��ũ��
#define SINGLE(type) public:static type* GetInst() {static type mgr; return &mgr;} private:type(); ~type();

enum class OBJECT_TYPE
{
	DEFAULT,

	PLAYER,

	UI =31,
	END = 32,
};



enum class SCENE_TYPE
{
	MAIN,
	

	END,
};


enum class BRUSH_TYPE
{
	HOLLOW,
	BLACK,

	// ���� �����ؾ��ϴ� brush 2
	
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};
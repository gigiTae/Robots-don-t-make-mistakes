#pragma once


// Singleton ∏≈≈©∑Œ
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
#pragma once


// Singleton 매크로
#define SINGLE(type) public:static type* GetInst() {static type mgr; return &mgr;} private:type(); ~type();

#define KEY_CHECK(key,state) KeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define MOUSE_POS KeyMgr::GetInst()->GetMousePos()


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

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,
	
	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	BLACK,

	// 직접 해제해야하는 brush 2
	
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};
#pragma once



class Res;
class Texture;

class ResMgr
{
	SINGLE(ResMgr);


private:
	/// ¸â¹ö º¯¼ö

	map<wstring, Res*> m_mapTex;

public:
	Texture* LoadTexture(const wstring& _key, const wstring& _relativePath);
	Texture* CreateTexture(const wstring& _key, UINT _width, UINT _height);
	Texture* FindTexture(const wstring& _key);

};


#pragma once


// Singleton ��ũ��
#define SINGLE(type) public:static type* GetInst() {static type mgr; return &mgr;} private:type(); ~type();

#define PI 3.1415926535f


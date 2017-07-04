#ifndef _SIMPLEFACTORY_H_
#define _SIMPLEFACTROY_H_


#include "MyPlane.h"
#include "Enemy.h"
#include "Bomb.h"
#include "Ball.h"
#include "map.h"
#include "Boss.h"
#include "Gold.h"
#include "Progress.h"
#include "Explosion.h"
#include "GameObject.h"
#include "Strengthen.h"
#include "bomb2.h"
#include "Dazhao.h"


class AbstractFactory{

public:
    AbstractFactory();
    virtual ~AbstractFactory();


public:
    virtual CGameObject* createProduct(int type) = 0;    
};


class SimpleFactory:public AbstractFactory{

public:
    SimpleFactory();
    ~SimpleFactory();
    
public:
    CGameObject* createProduct(int type);
};
#endif
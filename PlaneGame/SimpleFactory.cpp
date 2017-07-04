#include "StdAfx.h"
#include "SimpleFactory.h"


AbstractFactory::AbstractFactory(){
}


AbstractFactory::~AbstractFactory(){
}


SimpleFactory::SimpleFactory(){
}


SimpleFactory::~SimpleFactory(){
}


CGameObject* SimpleFactory::createProduct(int type){
    CGameObject* temp = NULL;
    switch(type)
    {
    case 0:
  		temp = new CEnemy();
        break;
    case 1:
        temp = new CBomb();
        break;
	case 2:
        temp = new CBall();
        break;
	case 3:
		temp = new CStrengthen();
        break;
	case 4:
        temp = new CBoss();
		break;
	case 5:
		temp = new CGold();
		break;
	case 6:
		temp = new CBomb2();
		break;
	case 7:
        temp = new CDazhao();
        break;
	case 8:
        temp = new CExplosion();
		break;
	case 9:
        temp = new CMaps();
        break;
	case 10:
        temp = new CProgress();
        break;
	case 11:
        temp = new CMyPlane();
        break;
    default:
        break;
    }
    return temp;
}

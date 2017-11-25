#ifndef _cShip_HG_
#define _cShip_HG_

#include "iGameObject.h"
//#include "cLASERgun.h"

class cGameObject;	// forward declare

class cShip : public iGameObject
{
public:
	cShip();
	virtual ~cShip();		// Make this virtual, too
	int size;
	float topSpeed;
	float fuel;

	//virtual void FlyAround( void );
	//virtual void ShootWeapons( void );

	virtual void SetPosition( glm::vec3 newPos );
	virtual void SetVelocity( glm::vec3 newVel );

	virtual std::string getName( void );
	virtual void setName( std::string newName );

	// NOTE: I'm passing iMediator NOT the full factory
	virtual void SetMediator( iMediator* pMediator );

	//cLASERgun* pMyLASER;

	cGameObject* pMesh;

private:
	std::string name;

	iMediator* m_pTheMediator;
};

#endif 
#ifndef _cCell_HG_
#define _cShip_HG_

#include "iGameObject.h"

class cGameObject;	// forward declare

class cCell : public iGameObject
{
public:
	cCell();
	virtual ~cCell();		// Make this virtual, too
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

	cGameObject* pMesh;

private:
	std::string name;

	iMediator* m_pTheMediator;
};

#endif 

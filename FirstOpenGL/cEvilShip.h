#ifndef _cEvilShip_HG_
#define _cEvilShip_HG_

#include "iGameObject.h"
#include "cThruster.h"

class cGameObject;	// forward declare

class cEvilShip : public iGameObject
{
public:
	cEvilShip();
	virtual ~cEvilShip();		// Make this virtual, too
	int size;
	float topSpeed;
	float fuel;

	//virtual void FlyAround( void );
	virtual void ShootWeapons( void );

	virtual void SetPosition( glm::vec3 newPos );
	virtual void SetVelocity( glm::vec3 newVel );
	virtual void SetRotation( glm::vec3 newRot );
	virtual glm::vec3 GetPosition( void );

	virtual std::string getName( void );
	virtual void setName( std::string newName );

	// NOTE: I'm passing iMediator NOT the full factory
	virtual void SetMediator( iMediator* pMediator );

	virtual void moveTo( glm::vec3 targetPosition );
	virtual void update( void );

	cThruster* pMyThruster;

	cGameObject* pMesh;

private:
	std::string name;

	iMediator* m_pTheMediator;
};

#endif 

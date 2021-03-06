#ifndef _cBacteria_HG_
#define _cBacteria_HG_

#include "iGameObject.h"

#define _USE_MATH_DEFINES
#include <math.h>

class cGameObject;	// forward declare

class cBacteria : public iGameObject
{
public:
	cBacteria();
	virtual ~cBacteria();		// Make this virtual, too
	int size;
	float topSpeed;
	float fuel;

	//virtual void FlyAround( void );
	//virtual void ShootWeapons( void );

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

	void attackShip( std::string targetName, glm::vec3 targetPos );

	cGameObject* pMesh;

private:
	std::string name;
	std::string targetName;

	iMediator* m_pTheMediator;
};

#endif 
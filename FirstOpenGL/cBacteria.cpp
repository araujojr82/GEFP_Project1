#include "cBacteria.h"
#include <iostream>

extern float distanceSqEucl( float x1, float y1, float x2, float y2 );
extern float direction( float x1, float y1, float x2, float y2, float x3, float y3 );

cBacteria::cBacteria()
{
	this->size = 1;
	std::cout << "cBacteria::cBacteria() is called" << std::endl;
	return;
}

cBacteria::~cBacteria()
{
	std::cout << "cBacteria::~cBacteria() is called" << std::endl;
	return;
}

//void cShip::FlyAround( void )
//{
//	std::cout
//		<< "cShip::FlyAround() is called "
//		<< this->size
//		<< std::endl;
//	return;
//}
//
//void cShip::ShootWeapons( void )
//{
//	std::cout << "cShip shoots:";
//	this->pMyLASER->Shoot();
//	return;
//}
//
void cBacteria::SetPosition( glm::vec3 newPos )
{
	this->pMesh->position = newPos;
	//TODO: Set GO
	return;
}

void cBacteria::SetVelocity( glm::vec3 newVel )
{
	this->pMesh->vel = newVel;
	//TODO: Set GO
	return;
}

void cBacteria::SetRotation( glm::vec3 newRot )
{
	this->pMesh->rotation = newRot;
	return;
}

glm::vec3 cBacteria::GetPosition( void )
{
	return this->pMesh->position;
}

std::string cBacteria::getName( void )
{
	return this->name;
}

void cBacteria::setName( std::string newName )
{
	this->name = newName;
	return;
}

// NOTE: I'm passing iMediator NOT the full factory
void cBacteria::SetMediator( iMediator* pMediator )
{
	this->m_pTheMediator = pMediator;
	return;
}

void cBacteria::moveTo( glm::vec3 targetPosition )
{
	float startX, startY, endX, endY;

	startX = this->GetPosition().x;
	startY = this->GetPosition().y;
	endX = targetPosition.x;
	endY = targetPosition.y;

	float distance = sqrt( pow( endX - startX, 2 ) + pow( endY - startY, 2 ) );
	float directionX = ( endX - startX ) / distance;
	float directionY = ( endY - startY ) / distance;

	directionX *= 0.75f;
	directionY *= 0.75f;

	this->SetVelocity( glm::vec3( directionX, directionY, 0.0f ) );

	return;
}

void cBacteria::update( void )
{
	glm::vec3 thePosition = this->GetPosition();

	thePosition = this->GetPosition();

	if( thePosition.x > 11.0f ) thePosition.x = -11.0f;
	if( thePosition.x < -11.0f ) thePosition.x = 11.0f;
	this->SetPosition( thePosition );

	std::vector<std::string> vecParam;
	std::vector<std::string> vecResult;

	vecParam.push_back( "FindClosestObjByType" );
	vecParam.push_back( "Player" );

	vecParam.push_back( std::to_string( thePosition.x ) );
	vecParam.push_back( std::to_string( thePosition.y ) );
	vecParam.push_back( std::to_string( thePosition.z ) );


	vecResult = this->m_pTheMediator->Mediate( "bacteria", this->getName(), vecParam );

	return;
}

void cBacteria::attackShip( std::string theName, glm::vec3 targetPos )
{
	this->targetName = theName;
	this->moveTo( targetPos );

	return;
}
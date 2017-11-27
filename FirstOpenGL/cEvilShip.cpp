#include "cEvilShip.h"
#include <iostream>

cEvilShip::cEvilShip()
{
	this->size = 1;
	std::cout << "cShip::cShip() is called" << std::endl;
	return;
}

cEvilShip::~cEvilShip()
{
	std::cout << "cShip::~cShip() is called" << std::endl;
	return;
}

//void cEvilShip::FlyAround( void )
//{
//	std::cout
//		<< "cShip::FlyAround() is called "
//		<< this->size
//		<< std::endl;
//	return;
//}

void cEvilShip::ShootWeapons( void )
{
	std::cout << "cShip shoots:";
	//this->pMyLaser->Shoot();
	return;
}

void cEvilShip::SetPosition( glm::vec3 newPos )
{
	this->pMesh->position = newPos;

	//TODO: Set GO
	return;
}

void cEvilShip::SetVelocity( glm::vec3 newVel )
{
	//TODO: Set GO
	this->pMesh->vel = newVel;
	return;
}

void cEvilShip::SetRotation( glm::vec3 newRot )
{
	this->pMesh->rotation = newRot;
	return;
}

glm::vec3 cEvilShip::GetPosition( void )
{
	return this->pMesh->position;
}

std::string cEvilShip::getName( void )
{
	return this->name;
}

void cEvilShip::setName( std::string newName )
{
	this->name = newName;
	return;
}

// NOTE: I'm passing iMediator NOT the full factory
void cEvilShip::SetMediator( iMediator* pMediator )
{
	this->m_pTheMediator = pMediator;
	return;
}

void cEvilShip::moveTo( glm::vec3 targetPosition )
{
	float startX, startY, endX, endY;

	startX = this->GetPosition().x;
	startY = this->GetPosition().y;
	endX = targetPosition.x;
	endY = targetPosition.y;

	float distance = sqrt( pow( endX - startX, 2 ) + pow( endY - startY, 2 ) );
	float directionX = ( endX - startX ) / distance;
	float directionY = ( endY - startY ) / distance;


	this->SetVelocity( glm::vec3( directionX, directionY, 0.0f ) );

	return;
}

void cEvilShip::update( void )
{
	glm::vec3 newPosition, myPosition;

	myPosition = this->GetPosition();

	if( myPosition.y >= 8.0f )
	{
		myPosition.y = -8.0f;
		this->SetPosition( myPosition );
	}

	newPosition = this->pMyThruster->Start( myPosition );

	this->moveTo( newPosition );
	return;
}
#include "cCell.h"
#include <iostream>

cCell::cCell()
{
	this->size = 1;
	std::cout << "cCell::cCell() is called" << std::endl;
	return;
}

cCell::~cCell()
{
	std::cout << "cCell::~cCell() is called" << std::endl;
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
void cCell::SetPosition( glm::vec3 newPos )
{
	this->pMesh->position = newPos;
	//TODO: Set GO
	return;
}

void cCell::SetVelocity( glm::vec3 newVel )
{
	this->pMesh->vel = newVel;
	//TODO: Set GO
	return;
}

void cCell::SetRotation( glm::vec3 newRot )
{
	this->pMesh->rotation = newRot;
	return;
}

glm::vec3 cCell::GetPosition( void )
{
	return this->pMesh->position;
}

std::string cCell::getName( void )
{
	return this->name;
}

void cCell::setName( std::string newName )
{
	this->name = newName;
	return;
}

// NOTE: I'm passing iMediator NOT the full factory
void cCell::SetMediator( iMediator* pMediator )
{
	this->m_pTheMediator = pMediator;
	return;
}

void cCell::moveTo( glm::vec3 targetPosition )
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

void cCell::update( void )
{
	glm::vec3 newPosition, myPosition;

	myPosition = this->GetPosition();

	if( myPosition.x > 12.0f ) myPosition.x = -12.0f;
	if( myPosition.x < -12.0f ) myPosition.x = 12.0f;
	this->SetPosition( myPosition );

	newPosition = myPosition;
	newPosition += glm::vec3( generateRandomNumber( 0.0f, 12.0f ),
							  0.0f, //generateRandomNumber( -6.0f, 6.0f ),
							  0.0f );
	this->moveTo( newPosition );
	return;
}
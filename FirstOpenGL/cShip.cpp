#include "cShip.h"
#include <iostream>

cShip::cShip()
{
	this->size = 1;
	std::cout << "cShip::cShip() is called" << std::endl;
	return;
}

cShip::~cShip()
{
	std::cout << "cShip::~cShip() is called" << std::endl;
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

void cShip::ShootWeapons( void )
{
	std::cout << "cShip shoots:";
	this->pMyLaser->Shoot();
	return;
}

void cShip::SetPosition( glm::vec3 newPos )
{
	this->pMesh->position = newPos;
	
	//TODO: Set GO
	return;
}

void cShip::SetVelocity( glm::vec3 newVel )
{
	//TODO: Set GO
	this->pMesh->vel = newVel;
	return;
}

void cShip::SetRotation( glm::vec3 newRot )
{
	this->pMesh->rotation = newRot;
	return;
}

std::string cShip::getName( void )
{
	return this->name;
}

void cShip::setName( std::string newName )
{
	this->name = newName;
	return;
}

// NOTE: I'm passing iMediator NOT the full factory
void cShip::SetMediator( iMediator* pMediator )
{
	this->m_pTheMediator = pMediator;
	return;
}

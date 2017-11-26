#include "cVirus.h"
#include <iostream>

cVirus::cVirus()
{
	this->size = 1;
	std::cout << "cVirus::cVirus() is called" << std::endl;
	return;
}

cVirus::~cVirus()
{
	std::cout << "cVirus::~cVirus() is called" << std::endl;
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
void cVirus::SetPosition( glm::vec3 newPos )
{
	this->pMesh->position = newPos;
	//TODO: Set GO
	return;
}

void cVirus::SetVelocity( glm::vec3 newVel )
{
	this->pMesh->vel = newVel;
	//TODO: Set GO
	return;
}

void cVirus::SetRotation( glm::vec3 newRot )
{
	this->pMesh->rotation = newRot;
	return;
}

std::string cVirus::getName( void )
{
	return this->name;
}

void cVirus::setName( std::string newName )
{
	this->name = newName;
	return;
}

// NOTE: I'm passing iMediator NOT the full factory
void cVirus::SetMediator( iMediator* pMediator )
{
	this->m_pTheMediator = pMediator;
	return;
}

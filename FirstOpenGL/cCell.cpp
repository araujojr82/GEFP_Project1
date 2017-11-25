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
	//TODO: Set GO
	return;
}

void cCell::SetVelocity( glm::vec3 newPos )
{
	//TODO: Set GO
	return;
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
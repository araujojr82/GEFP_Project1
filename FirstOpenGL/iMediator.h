#pragma once
#ifndef _iMediator_HG_
#define _iMediator_HG_

class iGameObject;	// Forward declare
#include <string>

				// Interface class
class iMediator
{
public:
	// Memory leak if not virtual
	virtual ~iMediator() {};

	// These are "Mediator" sort of methods
	// Seen by the main, iShip, etc.
	virtual iGameObject* FindObjByID( unsigned int uniqueID ) = 0;
	virtual iGameObject* FindObjByName( std::string name ) = 0;

};

#endif
#include "cFactory.h"
// Include the SPECIFIC header here NEVER in the header of factory
#include "cShip.h"	
#include "cCell.h"


// Why here? Because this file is where "new" is being called
#include "cGameObject.h"
#include <vector>
#include <glm/glm.hpp>

// I'll need to get at g_vecGameObjects, 
//	but I can just extern it...
extern std::vector< cGameObject* >  g_vecGameObjects;

// A "factory" method
iGameObject* cFactory::CreateObject( std::string objType )
{
	iGameObject* pTheObject = NULL;	// or 0, or nullptr

	if( objType == "basic" )
	{
		pTheObject = new cShip();		// Abstract Factory
		this->AssembleObject( pTheObject, objType );
	}
	else if( objType == "fighter" )
	{
		pTheObject = new cShip();
		// ***********************************************
		// Here we add the game object association
		// (This would be a good case for making a G.O. Factory thing
		cGameObject* pTempGO = new cGameObject();
		pTempGO->scale = 2.0f;
		pTempGO->diffuseColour = glm::vec4( 0.5f, 0.5f, 0.5f, 1.0f );
		pTempGO->meshName = "fighter";
		pTempGO->typeOfObject = eTypeOfObject::UNKNOWN;
		pTempGO->bIsUpdatedInPhysics = true;
		//pTempGO->bIsWireFrame = true;
		::g_vecGameObjects.push_back( pTempGO );		// Fastest way to add
														// ***********************************************
		cShip* pS = ( cShip* )pTheObject;		//iShip* pTheShip
		pS->pMesh = pTempGO;
		this->AssembleObject( pTheObject, objType );
	}
	else if( objType == "cell" )
	{
		pTheObject = new cCell();
		// ***********************************************
		// Here we add the game object association
		// (This would be a good case for making a G.O. Factory thing
		cGameObject* pTempGO = new cGameObject();
		pTempGO->scale = 1.0f;
		pTempGO->diffuseColour = glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f );
		pTempGO->meshName = "bloodcell";
		pTempGO->typeOfObject = eTypeOfObject::UNKNOWN;
		pTempGO->bIsUpdatedInPhysics = true;
		//pTempGO->bIsWireFrame = true;

		::g_vecGameObjects.push_back( pTempGO );		// Fastest way to add
														// ***********************************************
		cCell* pS = ( cCell* )pTheObject;		//iShip* pTheShip
		pS->pMesh = pTempGO;
		//		((cShip*)(pTheShip))->pMesh = pTempGO;
		// ***********************************************
		this->AssembleObject( pTheObject, objType );
	}

	// Save the ship if it's valid
	if( pTheObject != NULL )
	{	// Then it's a valid ship, so save it
		pTheObject->SetMediator( this );
		this->vec_pObjects.push_back( pTheObject );
	}

	return pTheObject;
}


// "builder" design pattern
void cFactory::AssembleObject( iGameObject* pTheObject, std::string objType )
{
	if( objType == "fighter" )
	{	// Assemble or build the specifics of that object
		// It's got one Laser Gun
		// ( (cShip*)pTheShip )->pMyLASER...

		cShip* pShip = ( cShip* )pTheObject;	// not iShip
		pShip->pMyLaser = new cLaserGun();
	}
	return;
}


// Mediator things
//// These are "Mediator" sort of methods
//iShip* FindShipByID( unsigned int uniqueID );
//iShip* FindShipByName( std::string name );

void cFactory::UpdateAllObjects( double timestep )
{
	// **************************************************
	// Ship behaviour update step
	for( int index = 0; index != this->vec_pObjects.size(); index++ )
	{
		iGameObject* pCurObj = this->vec_pObjects[index];

		// For "fly around" (or anything tied with the physics),
		//	you might want to use the physics updater
		//pCurObj->FlyAround();
		// TODO: Any other behaviour we want 

	}//for ( int index = 0;

	return;
}


iGameObject* cFactory::FindObjByID( unsigned int uniqueID )
{
	// TODO: finish this
	return 0;
}

// Returns the ship or NULL(0) if didn't find it
iGameObject* cFactory::FindObjByName( std::string name )
{
	for( int index = 0; index != this->vec_pObjects.size(); index++ )
	{
		iGameObject* pCurrentObj = this->vec_pObjects[index];
		if( pCurrentObj->getName() == name )
		{
			return pCurrentObj;
		}
	}
	return NULL;
}
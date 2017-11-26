#include "cFactory.h"

extern float generateRandomNumber( float min, float max );

void loadObjectsUsingFactory(cFactory* pFactory, std::vector< iGameObject* > vecObjects)
{
    iGameObject* pSpaceShip = pFactory->CreateObject("fighter");    
    pSpaceShip->setName("PlayerShip");
	pSpaceShip->SetPosition( glm::vec3( 0.0f, 0.0f, 0.0f ) );
	pSpaceShip->SetVelocity( glm::vec3( 0.0f, 0.0f, 0.0f ) );
	pSpaceShip->SetRotation( glm::vec3( 0.0f, 0.0f, 0.0f ) );
    vecObjects.push_back(pSpaceShip);
    
    // These lines create a new object just by recompiling this object. Uncoment to test!
    //iGameObject* pSpaceShip2 = pFactory->CreateObject("fighter2");
    //pSpaceShip->setName("PlayerShip2");
    //pSpaceShip->SetVelocity(glm::vec3(0.0f, 0.0f, 0.1f));
    //vecObjects.push_back(pSpaceShip2);

	for( int index = 0; index != 10; index++ )
	{
        iGameObject* pCell = pFactory->CreateObject("cell");
		pCell->setName("cell" + std::to_string(index));
		pCell->SetPosition( glm::vec3( generateRandomNumber( -11.0f, 11.0f ), //x
									   generateRandomNumber( -6.0f, 6.0f ), //y
									   0.0f ) );				             //z

		//pCell->SetPosition( glm::vec3( 5.0f, 0.0f, 0.0f ) );

		pCell->SetRotation( glm::vec3( generateRandomNumber( -0.02f, 0.02f ),
									   generateRandomNumber( -0.02f, 0.02f ),
									   generateRandomNumber( -0.02f, 0.02f ) ) );
        vecObjects.push_back( pCell );
    }

	for( int index = 0; index != 5; index++ )
	{
		iGameObject* pVirus = pFactory->CreateObject( "virus" );
		pVirus->setName( "virus" + std::to_string( index ) );
		pVirus->SetPosition( glm::vec3( generateRandomNumber( -11.0f, 11.0f ), //x
										generateRandomNumber( -6.0f, 6.0f ), //y
										0.0f ) );				             //z
		
		//pVirus->SetPosition( glm::vec3( 0.0f, 5.0f, 0.0f ) );

		pVirus->SetRotation( glm::vec3( generateRandomNumber( -0.02f, 0.02f ),
			generateRandomNumber( -0.02f, 0.02f ),
			generateRandomNumber( -0.02f, 0.02f ) ) );
		vecObjects.push_back( pVirus );
	}
}
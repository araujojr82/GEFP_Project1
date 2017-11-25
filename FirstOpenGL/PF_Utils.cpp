#include "cFactory.h"

void loadObjectsUsingFactory(cFactory* pFactory, std::vector< iGameObject* > vecObjects)
{
    iGameObject* pSpaceShip = pFactory->CreateObject("fighter");    
    pSpaceShip->setName("PlayerShip");
    pSpaceShip->SetVelocity(glm::vec3(0.0f, 0.0f, 0.1f));
    vecObjects.push_back(pSpaceShip);
    iGameObject* pSpaceShip2 = pFactory->CreateObject("fighter2");
    pSpaceShip->setName("PlayerShip2");
    pSpaceShip->SetVelocity(glm::vec3(0.0f, 0.0f, 0.1f));
    vecObjects.push_back(pSpaceShip2);

    for (int index = 0; index != 1; index++)
    {
        iGameObject* pBS = pFactory->CreateObject("cell");
        // teapot
        pBS->setName("cell" + std::to_string(index));
        vecObjects.push_back(pBS);
    }
}
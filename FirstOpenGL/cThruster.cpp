#include "cThruster.h"
#include <iostream>

glm::vec3 cThruster::Start( glm::vec3 currentPosition )
{

	glm::vec3 moveToPosition;

	moveToPosition = currentPosition;
	moveToPosition += glm::vec3( 0.0f, 10.0f, 0.0f );

	return moveToPosition;
}

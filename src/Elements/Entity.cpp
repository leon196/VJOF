#include "Entity.h"

Entity::Entity()
{
	id = 0;
	name = "name";
	scale = ofVec3f(1,1,1);
}

Entity::~Entity()
{
}

void Entity::Draw()
{
}

void Entity::Translate(ofVec3f p)
{
	position = p;
}
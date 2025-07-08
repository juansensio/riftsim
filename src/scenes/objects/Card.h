#pragma once

#include "Object.h"

class Card : public Object {
	
public:
	Card(Entity* entity);
	~Card();

	void init();
};
#include "Object.h"

Object::Object(Entity* entity) : _entity(entity) {}

Object::~Object() {}

void Object::init() {}

void Object::update(const float& dt) {}

void Object::destroy() { _entity->destroy(); }
#include "Object.h"



void Object::setPosition(Vector2f pos) {
    this->pos = pos;
    sprite.setPosition(pos);
}

Vector2f Object::getPosition(void) {
    return sprite.getPosition();
}

void Object::draw(RenderWindow * window) {
    window->draw(sprite);
}

void Object::flip(float ang) {
    this->ang = ang;
    sprite.setRotation(0.0f);
    sprite.rotate(ang);
    sprite.getRotation();
    

}

FloatRect Object::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

bool Object::collidesWith(const Object& other) {
    return sprite.getGlobalBounds().intersects(other.getGlobalBounds());
}

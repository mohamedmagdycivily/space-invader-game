#include "Bullet.hpp"

void Bullet::initVar()
{
    movementSpeed = 5.f;
}

void Bullet::initSprite()
{
    if(!tex.loadFromFile("/home/mohamed/Desktop/MY_CODE/Game_Project/Files/SFML_C-_Simple_Games-master/SFML_C++_Simple_Games/SFML_C++_Simple_Games/Textures/bullet.png"))
        std::cout << "ERROR::Bullet.cpp::initTexture()::Can Not Load From File" << std::endl;
    
    sprite.setTexture(tex);
    sprite.scale(1, .5);
}

Bullet::Bullet()
{
    initVar();
    initSprite();
}

Bullet::Bullet(float x, float y)
{
    initVar();
    initSprite();
    
    direction.x = x;
    direction.y = y;
    
    sprite.setPosition(direction);
}

Bullet::~Bullet()
{
}

//public Functions
sf::FloatRect Bullet::getBounds()const
{
    return sprite.getGlobalBounds();
}

void Bullet::update()
{
//    sprite.move(direction.x * movementSpeed, direction.y * movementSpeed);
    sprite.move(0 ,-movementSpeed);
    
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(sprite);
}



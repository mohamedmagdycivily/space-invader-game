#include "Enemy.hpp"

//Private Functions
void Enemy::initVariables()
{
    pointCount    = rand() % 8 + 3; //max = 10, min = 3
    hpMax         = pointCount; //not used 
    hp            = hpMax;      //not used 
    damage        = pointCount;
    points        = pointCount;
    movementSpeed = pointCount  / 2.f; //[1->4]
}

void Enemy::initShape()
{
    shape.setRadius(pointCount * 5);
    shape.setPointCount(pointCount);
    shape.setFillColor(sf::Color(rand()%254 + 1, rand()%254 + 1, rand()%254 + 1));
}


Enemy::Enemy(float x, float y)
{
    initVariables();
    initShape();
    shape.setPosition(rand() % static_cast<int> (x - shape.getGlobalBounds().width), 
                      -shape.getRadius()*2 /*rand() % static_cast<int> (y - shape.getGlobalBounds().height)*/);
}

Enemy::~Enemy()
{
}

//Accessors
sf::FloatRect Enemy::getBounds()const
{
    return shape.getGlobalBounds();
}

int Enemy::getPoints()const
{
    return points;
}

int Enemy::getDamage()const
{
    return damage;
}

//public Functions
void Enemy::move()
{
    shape.move(0, movementSpeed);
}

void Enemy::update()
{
    move();
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(shape);
}

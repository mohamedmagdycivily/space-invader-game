#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
    sf::CircleShape shape;
    unsigned pointCount;
    int hpMax;
    int hp;
    int damage;
    int points;
    float movementSpeed;
    
    //Private Functions
    void initVariables();
    void initShape();
public:
    Enemy(float x, float y);
    ~Enemy();
    
    //Accessors
    sf::FloatRect getBounds()const;
    int getPoints()const;
    int getDamage()const;
    
    //public Functions
    void move();
    void update();
    void render(sf::RenderTarget *target);

};

#endif // ENEMY_HPP

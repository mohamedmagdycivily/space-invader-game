#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:
    sf::Texture tex;
    sf::Sprite sprite;
    
    sf::Vector2f direction;
    int movementSpeed;
    
    //private Functions
    void initVar();
    void initSprite();
    
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    
    //Accessors
    
    //public Functions
    sf::FloatRect getBounds()const;
    void update();
    void render(sf::RenderTarget *target);
};

#endif // BULLET_HPP

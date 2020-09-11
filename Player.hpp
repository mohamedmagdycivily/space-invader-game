#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include<iostream>

class Player
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    
    int movementSpeed;
    float attackCooldown;
    float attackCooldownMax;
    
    int hp;
    int hpMax;
    
    //private Functions
    void initVariables();
    void initSprite();
    
public:
    Player();
    ~Player();
    
    //Accessor
    sf::FloatRect getBounds()const;
    int getHpMax()const;
    int getHp()const;
    
    //public Functions
    void move(float x, float y);
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    bool canAttack();
    void updateAttack();
    void loseHp(int damage);
    
    void update();
    void render(sf::RenderTarget *target);
    
};

#endif // PLAYER_HPP

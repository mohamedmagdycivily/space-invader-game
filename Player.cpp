#include "Player.hpp"

//private Functions
void Player::initVariables()
{
    movementSpeed = 5;
    attackCooldownMax = 10;
    attackCooldown = attackCooldownMax;
    hpMax = 100;
    hp = hpMax;
}

void Player::initSprite()
{
    if(!texture.loadFromFile("/home/mohamed/Desktop/MY_CODE/Game_Project/Files/SFML_C-_Simple_Games-master/SFML_C++_Simple_Games/SFML_C++_Simple_Games/Textures/ship.png"))
        std::cout << "ERROR::Player.cpp::initSprite()::Can Not Load From File" << std::endl;
        
    sprite.setTexture(texture);
    sprite.setScale(0.1, .1);
}


Player::Player()
{
    initVariables();
    initSprite();
}

Player::~Player()
{
}

//Accessor
sf::FloatRect Player::getBounds()const
{
    return sprite.getGlobalBounds();
}

int Player::getHpMax()const
{
    return hpMax;
}

int Player::getHp()const
{
    return hp;
}

//public Functions
void Player::move(float x, float y)
{
    sprite.move(x * movementSpeed, y * movementSpeed);
}


void Player::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

sf::Vector2f Player::getPosition()
{
    return sprite.getPosition();
}

bool Player::canAttack()
{
    if(attackCooldown >= attackCooldownMax)
    {
        attackCooldown = 0;
        return true;
    }
    else
    {
//         attackCooldown += .5f;
         return false;
    }
}

void Player::updateAttack()
{
    if(this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 0.5f;
}

void Player::loseHp(int damage)
{
    hp -= damage;
    if(hp < 0)
        hp = 0;
}

void Player::update()
{
    updateAttack();
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(sprite);
}




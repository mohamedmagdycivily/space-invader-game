#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <sstream>

#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

class Game
{
private: 
    //window 
    sf::RenderWindow *window;
    sf::Event e;
    
    //player
    Player *player;
    
    //bullet
    std::vector<Bullet *> bullets;
    
    //Enemy
    std::vector<Enemy *> enemies;
    float spawnTimerMax;
    float spawnTimer;
    
    //world
    sf::Texture worldBackgroundTex;
    sf::Sprite worldBackground;
    
    //GUI
    sf::Font font;
    sf::Text text;
    sf::Text gameOverText;
    
    sf::RectangleShape hp;
    sf::RectangleShape hpReverse;
    sf::Vector2f hpSize;
    
//    int playerHp;
//    int playerHpMax;
    
    //system
    unsigned points;
    bool gameOver;
    
    //private Functions
    void initWindow();
    void initWorld();
    void initPlayer();
    void initBullet();
    void initEnemies();
    void initSystem();
    void initGui();
    
public:
    Game();
    ~Game();
    
    //Public  Functions
    void run();
    void pollEvents();
    
    void updateInput();
    void updateCollision();
    void updateBullets();
    void updateEnemies();
    void updateCompate();
    void updateGui();
    
    void update();
    void renderGui(sf::RenderTarget *target);
    void render();
};

#endif // GAME_HPP

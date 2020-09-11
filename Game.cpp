#include "Game.hpp"

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(5000, 5000), "Game3", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    window->setFramerateLimit(144);
}

void Game::initWorld()
{
   if(!worldBackgroundTex.loadFromFile("/home/mohamed/Desktop/MY_CODE/Game_Project/Files/SFML_C-_Simple_Games-master/SFML_C++_Simple_Games/SFML_C++_Simple_Games/Textures/background1.jpg"))
       std::cout << "ERROR::Game.cpp::initWorld()::Can Not Load from file" << std::endl;
       
    worldBackground.setTexture(worldBackgroundTex);
}

void Game::initPlayer()
{
    player = new Player;
}

void Game::initBullet()
{
    
}

void Game::initEnemies()
{
    spawnTimerMax = 25.f;
    spawnTimer = spawnTimerMax;
}

void Game::initSystem()
{
    points = 0;
    gameOver = false;
}

void Game::initGui()
{
    //font 
    if(!font.loadFromFile("/home/mohamed/Desktop/MY_CODE/Game_Project/Files/SFML_C-_Simple_Games-master/SFML_C++_Simple_Games/SFML_C++_Simple_Games/Fonts/Dosis-Light.ttf"))
        std::cout << "ERORR::Game.cpp::initGui()::Can Not Load From File " << std::endl; 
    
    //text
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setString("TEST");
    text.setPosition(window->getSize().x - 100, 5);
    
    //GameOverText
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(100);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("GAME OVER");
    gameOverText.setPosition(window->getSize().x / 2 - gameOverText.getGlobalBounds().width / 2, 
                             window->getSize().y / 2 - gameOverText.getGlobalBounds().height);
    
    //player HP
    hpSize = sf::Vector2f(window->getSize().x / 3, window->getSize().y /25);
    hp.setSize(hpSize);
    hp.setFillColor(sf::Color::Red);
    hp.setPosition(10, 5);
    
    hpReverse = hp;
    hpReverse.setFillColor(sf::Color(25, 25, 25, 200));
}

Game::Game()
{
    initWindow();
    initWorld();
    initPlayer();
    initBullet();
    initEnemies();
    initGui();
    initSystem();
}

Game::~Game()
{
    delete window;
    delete player;
    
    //delete bullets
    for(auto b : bullets)
    {
        delete b;
    }
    
    //delete enemies
    for(auto e : enemies)
    {
        e->render(window);
    }
}

//Private Functions
void Game::run()
{
    while(window->isOpen() )
    {
        pollEvents();
        
        if(!gameOver)
            update();
            
        render();
    }
}

void Game::pollEvents()
{
    while(window->pollEvent(e))
    {
     switch(e.type)
     {
         case sf::Event::KeyPressed:
         if(e.key.code == sf::Keyboard::Escape)
             window->close();
            break; // why if we delete break it closes if you click any button 
         case sf::Event::Closed:
            window->close();
            break;
         default:
            break;
     }
    }
}

void Game::updateInput()
{
    //update player Move
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player->move(0, -1.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->move(0, 1.f);
        
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move(1.f, 0);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->move(-1.f, 0);
        
    //Push a new bullet into bullets vector 
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->canAttack())
//    if(player->canAttack() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        bullets.push_back(new Bullet(player->getPosition().x + player->getBounds().width/2 - 5, player->getPosition().y));
        
}

void Game::updateCollision()
{
    //upadte collision with screen
    if(player->getBounds().top < 0)
        player->setPosition(player->getBounds().left, 0);
    else if(player->getBounds().top > window->getSize().y - player->getBounds().height)
        player->setPosition(player->getBounds().left, window->getSize().y - player->getBounds().height);

    if(player->getBounds().left < 0)
        player->setPosition(0, player->getBounds().top);
    else if(player->getBounds().left > window->getSize().x - player->getBounds().width)
        player->setPosition(window->getSize().x - player->getBounds().width, player->getBounds().top);

}

void Game::updateBullets()
{
    for(auto b : bullets)
    {
        b->update();
    }
}

void Game::updateEnemies()
{
    //create new enemy
    if(spawnTimer >= spawnTimerMax)
    {
        enemies.push_back(new Enemy(window->getSize().x , window->getSize().y));
        spawnTimer = 0;
    }
    else
        spawnTimer += .5;
    
    //move enemy and delete it at the end of the screen
    for(auto e : enemies)
    {
        e->update();
    }
}

void Game::updateCompate()
{
    // bullet collide with enemy
    for(size_t i{}; i < enemies.size(); i++)
    {
        for(size_t j{}; j < bullets.size(); j++)
        {
            if(enemies[i]->getBounds().intersects(bullets[j]->getBounds()))
            {
                //gain Points
                points += enemies.at(i)->getPoints();
                //delete enemy object
                delete enemies.at(i);
                //delete bullet object
                delete bullets.at(j);
                //erase enemy pointer in the vector
                enemies.erase(enemies.begin() + i);
                //erase bullet pointer in the vector
                bullets.erase(bullets.begin() + j);
                //decrement the iterator in order not to skip any enemy 
                i--;
                //decrement the iterator in order not to skip any bullet 
                j--;
            }
        }
        
        if(enemies[i]->getBounds().intersects(player->getBounds()))
        {
            //lose hp
            player->loseHp(enemies.at(i)->getDamage());
            //update health bar
            float percentage = static_cast<float> (player->getHp()) / player->getHpMax();
            hpSize.x = (window->getSize().x / 3) * percentage;
            hp.setSize(hpSize);
            //update GameOver
            if(player->getHp() <= 0)
                gameOver = true;
            
            //delete enemy object
            delete enemies.at(i);
            //erase enemy pointer in the vector
            enemies.erase(enemies.begin() + i);
            //decrement the iterator in order not to skip any enemy 
            i--;
        }
    }
}

void Game::updateGui()
{
    //update text
    std::stringstream ss;
    ss << "points: " << points ;
    text.setString(ss.str());
    

}

void Game::update()
{
    updateInput();

    updateCollision();

    updateBullets();
    
    player->update();

    updateEnemies();
    
    updateCompate();
    
    updateGui();
}

void Game::renderGui(sf::RenderTarget *target)
{
    if(gameOver)
        target->draw(gameOverText);
    target->draw(text);
    target->draw(hp);
    target->draw(hpReverse);
}

void Game::render()
{
    //handling gameOver
    if(gameOver)
    {
        //clear 
        window->clear();
        //drawBackground
        window->draw(worldBackground);
        //draw text
        renderGui(window);
    }
    else
    {
        //clear 
        window->clear();
        
        //draw
        window->draw(worldBackground);
        player->render(window);
        
        //draw bullets
        for(auto b : bullets)
        {
            b->render(window);
        }
        
        //draw enemies
        for(auto e : enemies)
        {
            e->render(window);
        }
        
        //draw text
        renderGui(window);
    }
    
    //display
    window->display();

}



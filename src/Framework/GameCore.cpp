#include "GameCore.hpp"

GameCore::GameCore()
{
    gameWindow.create((sf::VideoMode){800, 600, 32}, "Hello World", sf::Style::Default);
}

int GameCore::Update(CoreClock *coreClock)
{
   sceneManager.GetSceneTest().Update(coreClock->getClock().restart().asMilliseconds());
}

int GameCore::Draw(sf::RenderWindow *gameWindow)
{
    sceneManager.GetSceneTest().Draw(gameWindow);
}

int GameCore::Run()
{
    while (this->gameWindow.isOpen()) {
        while (this->gameWindow.pollEvent(this->gameEvent)) {
            Update(&this->coreClock);
            Draw(&this->gameWindow);
        }
    }
}
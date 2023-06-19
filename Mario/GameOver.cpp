#include "GameOver.h"


GameOver::GameOver() {
    if (!font.loadFromFile("../assets/font.ttf")) {
        cerr << "Error: Could not load font file" << std::endl;
    }

    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(WINDOW_WIDTH/3, WINDOW_HEIGHT/2-50);
}

void GameOver::draw(sf::RenderWindow* window) {
    window->draw(gameOverText);
}
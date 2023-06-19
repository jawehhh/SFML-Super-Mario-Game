#include "ScoreBoard.h"

void ScoreBoard::setScore(int score) {
    this->score = score;
}

void ScoreBoard::setLives(int lives) {
    this->lives = lives;
}

int ScoreBoard::getScore() {
    return score;
}

int ScoreBoard::getLives() {
    return lives;
}

ScoreBoard::ScoreBoard() : score(0), lives(3) {
    // Load the font
    if (!font.loadFromFile("../assets/font.ttf")) {
        std::cerr << "Error: Could not load font file" << std::endl;
    }

    // Set up the score and lives text
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(10, 40);
}

void ScoreBoard::draw(RenderWindow* window) {
    // Update the score and lives text
    scoreText.setString("Score: " + std::to_string(score));
    livesText.setString("Lives: " + std::to_string(lives));

    // Draw the text on the window
    window->draw(scoreText);
    window->draw(livesText);
}


#include "Game.h"


Game::Game() {
    window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Super Mario Game");


    for (int i = 0; i < NUM_BRICKS; i++)//setting to position of bricks
        {
        Brick* brick = addBrick();
        if (i>=70)
        {
            if (i % 2 == 0)
            {
                brick->setPosition(Vector2f(float((i -70)*30/2), float(WINDOW_HEIGHT/3+50)));
            }
            else if (i % 2 == 1)
            {
            brick->setPosition(Vector2f(float(WINDOW_WIDTH - (i - 71) * 30/2), float(WINDOW_HEIGHT/3+50)));
            }
        }
 
        else if (i>57 )
        {
                brick->setPosition(Vector2f(float(30 * (i-57)+WINDOW_WIDTH/3), float(WINDOW_HEIGHT/2-100)));
      
        }
        else if (i > 30)
        {
            if (i % 2 == 0)
            {
                brick->setPosition(Vector2f(float((i - 32) * 15 ), float(150)));
            }
            else
            {
                brick->setPosition(Vector2f(float(WINDOW_WIDTH - (i - 31) * 15 ), float(150)));
            }
        }
        else if (i%2==0)
        {
            brick->setPosition(Vector2f(float(i * 15), float(420)));
        }
        else if(i%2==1)
        {
            brick->setPosition(Vector2f(float(WINDOW_WIDTH-(i-1) * 15), float(420)));
        }
        
        

       
        }
   
    
    for (int i = 0; i < NUM_PIPES; i++)//setting to position of pipes
    {
        Pipe* pipe = addPipe();
        pipe->setPosition(Vector2f(float(1150-1020*i), float(525+i*73)));
        pipe->flip(i*180.0f);
    }

    for (int i = 0; i < NUM_PIPES; i++)//setting to position of spipes
    {
        Spipe* spipe = addSpipe();
        spipe->setPosition(Vector2f(float(1100 - 920 * i), float(34 + i * 120)));
        spipe->flip(i * 180.0f);
    }

}



void Game::update(void) {//update method for game dynamics
    bool isGameOver = false;
    Mario* mario = addMario();
    Turtle* turtle = addTurtle();
    ScoreBoard scoreboard;
    GameOver gameover;
    mario->setPosition(Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));
    Floor* floor = addFloor();
    floor->setPosition(Vector2f(float(0), float(600)));
    while (window->isOpen()) {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            else if (Keyboard::isKeyPressed(sf::Keyboard::Left) && Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                mario->move(Mario::MoveDirection::JUMPLEFT);
                mario->jump(false);
            }
            else if (Keyboard::isKeyPressed(sf::Keyboard::Right) && Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                mario->move(Mario::MoveDirection::JUMPRIGHT);
                mario->jump(false);
            }
            else if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                mario->move(Mario::MoveDirection::LEFT);
            }
            else if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                mario->move(Mario::MoveDirection::RIGHT);
            }
            else if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                mario->jump(false);
            }
            else
            {
         
                mario->move(Mario::MoveDirection::STOP);
            }


        }
        Vector2f prevposmar = mario->getPosition();//getting position before collision
        if (onFloor(mario))
        {
            mario->setSpeedy(1);//sending response to mario class to set speed
            mario->setPosition(prevposmar);//getting previous position of mario
        }
        else
        {
            mario->setSpeedy(0);
        }
        if (onBrick(mario))
        {
            mario->setSpeedy(1);
            mario->setPosition(prevposmar);
        }

        int side{ 9 };




        if (checkCollision(turtle, mario, side)) //checking collision mario and turtle
        {
            mario->move(Mario::MoveDirection::DOWN);
            mario->fall();


        }
        window->clear();
        if (mario->getPosition().y <= WINDOW_HEIGHT-50)//gameover logic
        {
            drawObjects();
            drawBackground();
            scoreboard.draw(window);
            mario->jump(true);
            turtle->fall();
            turtle->move();

        }
        else
        {
            sleep(milliseconds(700));
            gameover.draw(window);
        }

        window->display();
        sleep(milliseconds(100));
    }

}


void Game::setPosition(Vector2f pos) {
    this->pos = pos;
    backgroundSprite.setPosition(pos);
}

Game::~Game() 
{

}

Brick* Game::addBrick(void)
{
    Brick* brick = new Brick();
    brick->next = Bgobjects;
    Bgobjects = brick;
    return brick;

}

Pipe* Game::addPipe(void)
{
    Pipe* pipe = new Pipe();
    pipe->next = Bgobjects;
    Bgobjects = pipe;
    return pipe;

}

Spipe* Game::addSpipe(void)
{
    Spipe* spipe = new Spipe();
    spipe->next = Bgobjects;
    Bgobjects = spipe;
    return spipe;

}

Mario* Game::addMario(void)
{
    Mario* mario = new Mario();
    mario->next = objects;
    objects = mario;
    return mario;

}

Turtle* Game::addTurtle(void)
{
    Turtle* turtle = new Turtle();
    turtle->next = objects;
    objects = turtle;
    return turtle;

}

Floor* Game::addFloor(void)
{
    Floor* floor = new Floor();
    floor->next = Bgobjects;
    Bgobjects = floor;
    return floor;
}

void Game::drawBackground(void)//drawing background objects
{
    Object* cur = Bgobjects;
    while (cur)
    {
        cur->draw(window);
        cur = cur->next;

    }
}

void Game::drawObjects(void)//Mario, turtles and floor
{
    Object* cur = objects;
    while (cur)
    {
        cur->draw(window);
        cur = cur->next;

    }
}

bool Game::onFloor(Object* obj)//checking object on floor or not
{
    Object* cur = Bgobjects;
    Object* other = obj;
    while (cur)
    {
        cout << "Intersect:" << cur->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds()) << endl;
        if (dynamic_cast<Floor*>(cur) == NULL)
        {
            cur = cur->next;
        }  
        //else if (cur!=other && cur->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds()))
        else if(other->getPosition().y + other->getGlobalBounds().height >= cur->getPosition().y-20)
        {
            cout << "onfloor" << endl;
            return true;
        }
            
        

        return false;

    }
}
bool Game::onBrick(Object* obj)
{
    Object* cur = Bgobjects;
    Object* other = obj;
    while (cur)
    {
        if (dynamic_cast<Brick*>(cur) != NULL)  // Use dynamic_cast to check if the object is a Brick
        {
            if (cur->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds()) && other->getPosition().y + other->getGlobalBounds().height >= cur->getPosition().y)
            {
                cout << "Brick" << endl;
                return true;
            }
        }
        cur = cur->next;
    }
    return false;
}

bool Game::collidesWith(Object* obj)// checking collison between background objects
{
    Object* cur = Bgobjects;
    Object* other = obj;
    while (cur)
    {
        if (cur->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds()))
            return true;
        cur = cur->next;
    }
    return false;
}

bool Game::checkCollision(Turtle* t, Mario* m, int& side) {//checking collison mario and turtle


    if (m->collidesWith(*t)) {
        // Determine from which side Mario collided with the turtle
        // 0 = Top, 1 = Bottom, 2 = Left, 3 = Right
        if (m->getPosition().y + m->getGlobalBounds().height <= t->getPosition().y) {
            side = 0; // Top
            //removeObject(t);

        }
        else if (m->getPosition().y >= t->getPosition().y + t->getGlobalBounds().height) {
            side = 1; // Bottom
            //removeObject(m);
        }
        else if (m->getPosition().x + m->getGlobalBounds().width <= t->getPosition().x) {
            side = 2; // Left
           // removeObject(m);
        }
        else if (m->getPosition().x >= t->getPosition().x + t->getGlobalBounds().width) {
            side = 3; // Right
            //removeObject(m);
        }
        switch (side) {
        case 0:
            std::cout << "top" << std::endl;
            break;
        case 1:
            std::cout << "bottom!" << std::endl;
            break;
        case 2:
            std::cout << "left!" << std::endl;
            break;
        case 3:
            std::cout << "right!" << std::endl;
            break;
        default:
            std::cout << "Unexpected collision side!" << std::endl;
            break;
        }
        return true;
    }
    return false;
}

void Game::handleCollision(void) {
    Object* cur = objects;
    Object* other;
    while (cur) {
        if (dynamic_cast<Turtle*> (cur) != NULL) {

            other = objects;
            while (other) {
                if (cur != other && other->sprite.getGlobalBounds().intersects(cur->sprite.getGlobalBounds())) {
                    //removeObject(cur);
                    if (dynamic_cast <Brick*>(other) == NULL) {

                       // removeObject(other);
                    }
                    return;
                }
                other = other->next;

            }
        }
        cur = cur->next;
    }

}

bool Game::handleObjecthit(Mario* mario) {//to check to hit

    Object* cur = objects;
    Object* other;
    while (cur) {

        if (cur != mario && cur->sprite.getGlobalBounds().intersects(mario->sprite.getGlobalBounds()))


            return true;

        cur = cur->next;

    }


}


void Game::removeObject(Object* obj) {//Method to remove objects
    Object* cur = objects;
    Object* prev = NULL;
    while (cur) {
        if (cur == obj) {
            if (prev) {
                prev->next = cur->next;
            }
            else {
                objects = cur->next;
            }
            delete cur;
            return;

        }
        prev = cur;
        cur = cur->next;
    }

}
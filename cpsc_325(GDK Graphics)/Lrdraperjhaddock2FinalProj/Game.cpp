// A class for storing primitive objects: cylinder, cube, disk, Steiner surface

#include "Game.h"
#include "Globals.h"

Game::Game()
{
    float spin = 0;
    float xChange = 0;
    float yChange = 0;

    int shootCount = 0;
    int moveCount = 0;
    int dribbleCount = 0;
    int dribbleDirection = -1;
    int score = 0;
}

Game::~Game()
{
    float spin = 0;
    float xChange = 0;
    float yChange = 0;
    float d = 11;

    int shootCount = 0;
    int moveCount = 0;
    int dribbleCount = 0;
    int dribbleDirection = -1;
    int score = 0;
    int xStart = 0.0, yStart = 0.0;
}

void Game::Shoot()
{

}

void Game::Dribble()
{
    shootRotation = ident;
        if (dribbleDirection == -1){
            yChange -= 0.5;
            dribbleCount += 1;
        }
        if (dribbleDirection == 1){
            yChange += 0.5;
            dribbleCount += 1;
        }
        if (dribbleCount == 5){
            dribbleCount = 0;
            if (dribbleDirection == 1)
                dribbleDirection -= 2;
            else
                dribbleDirection += 2;
        }
}

void Game::SideToSide()
{

}

void Game::Rotate()
{

}

void Game::Reset()
{
    dist = 0;
    xChange = 0;
    yChange = 0;
    sCount = 0;
    moveCount = 0;
    spin = 0;
    moveRotation = ident;
    shootRotation = ident;

    eye = eyeStart; // camera location
    calcUVN(VPN,VUP);
    xStart = 0.0;
    yStart = 0.0;
    //light_position = lightStart;
}


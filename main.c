/*
 * ECE243 Final Project 
 * Naruto vs Sasuke: A Game
 * 
 * Written by,
 * - Ramakrishna Natarajan
 * - Gaurav Ranganath
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// declaration of values and keys used
typedef struct currentLocation{
    int x;
    int y;
} loc;

int keyPressed;
int switchStatus;
loc sasukePos;
loc rasenganPos[8];
loc rasenganInitPos[8];
int currRasengan;
loc rasenganMoveDirection[8];
int scoreCounter = 0;
int rasenganSpeed = 10;

// functions
bool checkGameOver();
void checkGameStatus();
void drawBackground();
void drawGameOver();
void drawNaruto();
void drawSasuke();
void drawRasengan();
void drawScore();
void drawPauseScreen();
void controlSasuke();
void controlNaruto();
void controlRasengan();

// main code
int main() {

    // Rasengan Current Position
    // N
    rasenganPos[0].x = 160;
    rasenganPos[0].y = 0;
    // NE
    rasenganPos[1].x = 320;
    rasenganPos[1].y = 0;
    // E
    rasenganPos[2].x = 320;
    rasenganPos[2].y = 120;
    // SE
    rasenganPos[3].x = 320;
    rasenganPos[3].y = 240;
    // S
    rasenganPos[4].x = 160;
    rasenganPos[4].y = 240;
    // SW
    rasenganPos[5].x = 0;
    rasenganPos[5].y = 240;
    // W
    rasenganPos[6].x = 0;
    rasenganPos[6].y = 120;
    // NW
    rasenganPos[7].x = 0;
    rasenganPos[7].y = 0;

    // Rasengan Init Position
    // N
    rasenganInitPos[0].x = 160;
    rasenganInitPos[0].y = 0;
    // NE
    rasenganInitPos[1].x = 320;
    rasenganInitPos[1].y = 0;
    // E
    rasenganInitPos[2].x = 320;
    rasenganInitPos[2].y = 120;
    // SE
    rasenganInitPos[3].x = 320;
    rasenganInitPos[3].y = 240;
    // S
    rasenganInitPos[4].x = 160;
    rasenganInitPos[4].y = 240;
    // SW
    rasenganInitPos[5].x = 0;
    rasenganInitPos[5].y = 240;
    // W
    rasenganInitPos[6].x = 0;
    rasenganInitPos[6].y = 120;
    // NW
    rasenganInitPos[7].x = 0;
    rasenganInitPos[7].y = 0;

    // Rasengan Delta
    // N
    rasenganMoveDirection[0].x = 0;
    rasenganMoveDirection[0].y = 1;
    // NE
    rasenganMoveDirection[1].x = -1;
    rasenganMoveDirection[1].y = 1;
    // E
    rasenganMoveDirection[2].x = -1;
    rasenganMoveDirection[2].y = 0;
    // SE
    rasenganMoveDirection[3].x = -1;
    rasenganMoveDirection[3].y = -1;
    // S
    rasenganMoveDirection[4].x = 0;
    rasenganMoveDirection[4].y = -1;
    // SW
    rasenganMoveDirection[5].x = 1;
    rasenganMoveDirection[5].y = -1;
    // W
    rasenganMoveDirection[6].x = 1;
    rasenganMoveDirection[6].y = 0;
    // NW
    rasenganMoveDirection[7].x = 1;
    rasenganMoveDirection[7].y = 1;

    // main game loop
    while (checkGameOver()) {
        // check game pause or play
        checkGameStatus(); 

        // game logic
        controlSasuke();
        controlNaruto();
        controlRasengan();

        // draw the game
        drawBackground();
        drawNaruto();
        drawSasuke();
        drawRasengan();
        drawScore();
    }
    
    return 0;
}

bool checkGameOver() {
    if (sasukePos.x == rasenganPos[currRasengan].x && sasukePos.y == rasenganPos[currRasengan].y) {
        return true;
    }

    return false;
}

void checkGameStatus() {
    // if switch 0 is on, start game
    while(switchStatus > 0) {
        drawPauseScreen();
    }

    return;
}

void checkRasenganSpeed() {
    if (scoreCounter % 10 == 0) {
        rasenganSpeed += 10;
    }

    return;
}

void drawBackground() {
    return;
}

void drawGameOver() {
    return;
}

void drawNaruto() {
    // draw naruto based on rasenganInitPosition
    return;
}

void drawSasuke() {
    // draw sasuke based on sasukePosition
    return;
}

void drawRasengan() {
    // draw rasengan based on rasenganCurrPosition
    return;
}

void drawScore() {
    // draw or HEX display the score counter
    // draw or HEX display the wave counter, which is =scoreCounter%10
    return;
}

void drawPauseScreen() {
    // pause screen responds to switchStatus
    // also used as start screen?
    return;
}

void controlSasuke() {
    
    if (keyPressed == 1) {
        // N
        sasukePos.x = 160;
        sasukePos.y = 100;
    } else if (keyPressed == 2) {
        // NE
        sasukePos.x = 180;
        sasukePos.y = 100;
    } else if (keyPressed == 3) {
        // E
        sasukePos.x = 180;
        sasukePos.y = 120;
    } else if (keyPressed == 4) {
        // SE
        sasukePos.x = 180;
        sasukePos.y = 140;
    } else if (keyPressed == 5) {
        // S
        sasukePos.x = 160;
        sasukePos.y = 140;
    } else if (keyPressed == 6) {
        // SW
        sasukePos.x = 140;
        sasukePos.y = 140;
    } else if (keyPressed == 7) {
        // W
        sasukePos.x = 140;
        sasukePos.y = 120;
    } else if (keyPressed == 8) {
        // NW
        sasukePos.x = 140;
        sasukePos.y = 100;
    } else if (keyPressed == 100) {
        // enable god mode - invincible?
        sasukePos.x = 160;
        sasukePos.y = 120;
    } else {
        // centre
        sasukePos.x = 160;
        sasukePos.y = 120;
    }

    return;
}

void controlNaruto() {
    // if currRasegan reach center, reset and respawn at other location
    // use rasenganInitposition for Naruto too
    if (rasenganPos[currRasengan].x == 160 && rasenganPos[currRasengan].y == 120) {
        currRasengan = rand() % 8;
        rasenganPos[currRasengan].x = rasenganInitPos[currRasengan].x;
        rasenganPos[currRasengan].y = rasenganInitPos[currRasengan].y;
        scoreCounter += 1;
    }

    return;
}

void controlRasengan() {
    rasenganPos[currRasengan].x += rasenganMoveDirection[currRasengan].x * rasenganSpeed;
    rasenganPos[currRasengan].y += rasenganMoveDirection[currRasengan].y * rasenganSpeed;

    return;
}
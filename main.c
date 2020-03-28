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

void drawBackground() {
    return;
}

void drawGameOver() {
    return;
}

void drawNaruto() {
    return;
}

void drawSasuke() {
    return;
}

void drawRasengan() {
    return;
}

void drawScore() {
    return;
}

void drawPauseScreen() {
    return;
}

void controlSasuke() {
    
    if (keyPressed == 1) {
        // N
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 2) {
        // NE
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 3) {
        // E
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 4) {
        // SE
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 5) {
        // S
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 6) {
        // SW
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 7) {
        // W
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 8) {
        // NW
        sasukePos.x = 0;
        sasukePos.y = 0;
    } else if (keyPressed == 100) {
        // enable god mode - invincible?
    }

    return;
}

void controlNaruto() {
    // if currRasegan is reach center, reset and respawn at other location
    if (rasenganPos[currRasengan].x == 100 && rasenganPos[currRasengan].y == 100) {
        rasenganPos[currRasengan].x = rasenganInitPos[currRasengan].x;
        rasenganPos[currRasengan].y = rasenganInitPos[currRasengan].y;

        currRasengan = rand() % 8;
    }

    return;
}

void controlRasengan() {
    rasenganPos[currRasengan].x += rasenganMoveDirection[currRasengan].x;
    rasenganPos[currRasengan].y += rasenganMoveDirection[currRasengan].y;

    return;
}
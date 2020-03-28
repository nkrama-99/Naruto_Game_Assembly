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
    
    return;
}

bool checkGameOver() {
    // game over if sasuke touches position of one rasengan
    for (int i=0; i<=8; i++) {
        if (sasukePos.x == rasenganPos[i].x && sasukePos.y == rasenganPos[i].y) {
            return true;
        }
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
    return;
}

void controlNaruto() {
    return;
}

void controlRasengan() {
    // if currRasegan is reach center, reset and respawn at other location
    if (rasenganPos[currRasengan].x == 100 && rasenganPos[currRasengan].y == 100) {
        rasenganPos[currRasengan].x = rasenganInitPos[currRasengan].x;
        rasenganPos[currRasengan].y = rasenganInitPos[currRasengan].y;

        currRasengan = rand() % 9;
    }

    return;
}


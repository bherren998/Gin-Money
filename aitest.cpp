#include "pile.h"
#include "player.h"
#include "interface.h"
#include "ai.h"

// this is for testing the AI
int main() 
{
    // defining containers
    Pile draw("Draw");
    Pile trash("Trash");
    AI lilguy("lilguy");
    
    draw.makeDeck();
    
    //give some cards to the lil dude
    for (int i = 1; i <= 10; i++)
        lilguy.recieveCard(draw.sendCard());
        
    Card blank;
    trash.recieveCard(blank);
    trash.recieveCard(draw.sendCard());
    
    int count = 0;
    while(!lilguy.willKnock() && !draw.isEmpty() && count < 50) {
        std::cout << "[???] " << trash.getTopCard() << "    ";
        lilguy.displayDebug();
        std::cout << std::endl;
        
        lilguy.takeTurn(&draw, &trash);
        
        trash.recieveCard(draw.sendCard());
        
        count++;
    }
    
    if(!draw.isEmpty() && count < 49) {
        std::cout << "The absolute madman knocked!!!!" << std::endl;
        std::cout << "[???] " << trash.getTopCard() << "  ";
        lilguy.displayDebug();
    }
    else
        std::cout << "No more cards" << std::endl;
}
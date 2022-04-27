#include <iostream>
#include <vector>
#include "include/ise102.h"
#include "include/handy_functions.h"
#include "Card.h"
#include "SkateDeck.h"
using namespace std;

void printDeck(SkateDeck deck)
{
    print("Deck: ---------------------------------------\n");
    print("\tBrand: {0}\n", deck.brand);
    if(deck.isSignatureModel())
    {
        print("\tThis {0} signature deck is {1} inches wide, ", 
            deck.skater_name, deck.width_inches); // just broken up into 2 lines
    } else
    {
        print("\tThis team deck is {0} inches wide, ", deck.width_inches);
    }
    print("with a {0} concave.\n", deck.getConcave());
    print("\tCarbon Fibre Layer: {0}\n\n", toYesNo(deck.carbon_fibre));
    print("\n");
    return;
}

/// Prompts the user to input values for a new deck.
/// @return the newly created deck.
SkateDeck getNewDeckFromUser()
{
    SkateDeck newDeck;
    print("ADD NEW DECK ========================\n");
    // When using 'cin <<' we only get single words.
    // Use getline to grab multiple words, like "Santa Cruz"
    print("\tEnter the brand name > ");
    getline(std::cin, newDeck.brand);
    print("\tWhat is the width in inches? > ");
    cin >> newDeck.width_inches;
    print("\n");

    return newDeck;
}

int main() {
    // Initialise property by property as we did in week 9 class
    SkateDeck baker_basic;
    baker_basic.brand = "Baker";
    baker_basic.width_inches = 7.75f;
    
    SkateDeck powell_dc;
    powell_dc.brand = "Powell";
    powell_dc.width_inches = 8.5f;
    powell_dc.skater_name = "Dan Corrigan"; // a signature model

    // Print them out.
    printDeck(baker_basic);
    printDeck(powell_dc);

    //------------- Now, using vectors/collections! ------------------
    
    print("Now do it again using a collection and a loop.\n\n");

    // Create a container to hold a collection of skateboard decks
    // 'vector' is a kind of container, '<SkateDeck>'s are what it can hold.
    vector<SkateDeck> decks;      
    decks.push_back(baker_basic);    // Add a deck to the end (or start if it's empty)
    decks.push_back(powell_dc);      // Add another deck. Now baker is at 0, powell is at 1.
    // You can also initialise a vector when you create it using "set" notation:
    // vector<SkateDeck> decks {baker_basic, powell_dc};
  
    // Printing things out using a loop scales up easily to n decks.
    // A *ranged* loop doesn't need 'int i' and 'i++'. It knows how many things are 
    // in the collection called `decks`, and their type `SkateDeck`. It says:
    // "for every SkateDeck in 'decks', call it 'deck' (temporarily) and 
    // do {this stuff} to it..""
    for(auto deck: decks)    
    {
        printDeck(deck);     // print a single deck (each time through loop)
    }

    //-------------- Create a deck with the user inputting values -------------
    SkateDeck user_deck = getNewDeckFromUser();  
    decks.push_back(user_deck);        // Add to the collection
    clearScreen();                     // Clear the screen of clutter
    // We're using this again.. it should probably be in a function.
    for(auto deck: decks)    // Get each deck in the decks collection and..
    {
        printDeck(deck);     // print each one 
    }
}
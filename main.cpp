#include <iostream>
#include <vector>
#include "include/ise102.h"
#include "include/handy_functions.h"
#include "SkateDeck.h"
using namespace std;

// Displays a trading card for the provided deck.
// NOTE: the deck parameter is passed by reference to avoid unnecessary copy.
// To avoid potential changes to the deck, we designated it const (constant)
void displayDeckCard(const SkateDeck& deck)
{

    print("~~~~~~~ Skate Deck ~~~~~~~~\n");
    print("\t{0}", deck.brand);
    if(deck.isSignatureModel())
    {
        print("\tTeam Model\n");
    } else
    {
        print("\t{0} Signature Model\n", deck.skater_name);
    }
    print("\tWidth: {0} inches\n", deck.width_inches);
    print("\n");
    // TODO: Display more data and format your card more like a graphic 
    // representation of a card (e.g. coloured border, alignment, spacing) 
    // with the styling and layout parts of the {fmt} library. 
    return;
}

/// Prompts the user to input values for a new deck.
/// @return the newly created deck.
// NOTE: Only collects brand name and skater name for this demonstration.
SkateDeck getNewDeckFromUser()
{
    SkateDeck new_deck;
    print("\n➕ Create New Deck ➕\n");
    print("Enter brand name > ");
    getline(std::cin, new_deck.brand);
    print("Who's signature model is it? If noone, just hit ENTER \n> ");
    getline(std::cin, new_deck.skater_name);
    print("New deck added ✅\n");
    return new_deck;
}

void clearAllSigModel(vector<SkateDeck>& decks)
{
    for (SkateDeck& deck : decks)
    {
        deck.skater_name = "";     // 
    }
}

// Display the decks in the supplied collection, one per row.
// NOTE: Only displays the brand and signature model status (true/false)
void listDecks(vector<SkateDeck>& decks)
{
    print("\n -- Skate Decks ------- \n");
    for( SkateDeck deck : decks)
    {
        print("\tBrand: {0} Signature model: {1}\n", deck.brand, deck.isSignatureModel());        
    }

}

void editSkateDeck(SkateDeck& deck_to_edit)
{
    // ask user to supply a value for each field they want to edit.
    // change the monster with user values
}

int main() {
//------------------------------------------------------------ CREATE DECKS
    // one team, one signature board, one input by user.
    SkateDeck baker_team;  // team board
    baker_team.brand = "Baker";
    SkateDeck powell_sig;
    powell_sig.brand = "Powell";
    powell_sig.skater_name = "Dan Corrigan";     // a signature model
    SkateDeck user_deck = getNewDeckFromUser();   
    // Collect all the board cards in a database.
    vector<SkateDeck> skate_decks = { baker_team, powell_sig, user_deck };      

//--------------------------------------------------------- ASSIGN A COPY
    // Let's see the decks before and after we attempt to clear any skater names
    listDecks(skate_decks);
    print ("\nAttempting to CLEAR skater name from all models 🧹🧹\n");
    for (SkateDeck deck : skate_decks)
    {
        deck.skater_name = "";     // 
    }
    listDecks(skate_decks);

//----------------------------------------------------- CREATE A REFERENCE
    print("\n========= NOW WITH REFERENCES ===========================\n");
    // Now the exact same code except for a single `&`. Will anything change?
    listDecks(skate_decks);
    print ("\nAttempting to CLEAR skater name from all models 🧹🧹\n");
    clearAllSigModel(skate_decks);
    listDecks(skate_decks);
        
}

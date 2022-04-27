#include <iostream>
#include "include/ise102.h"
#include "Card.h"

/// Print out the attributes of a dog (except its id), ideally
/// with user friendly formatting.
void printDoggoCard(Card dog)
{
    // TODO: print out each attribute of the dog except ID, accessing
    // each one with dot notation just like in main.
    print("\tName: {0} \n", dog.name);  // example using fmt print
}

int main() {
    
    Card doggo_0;
    doggo_0.id = 1;
    doggo_0.name = "Leroy";
    doggo_0.weight_kg = 19.12;
    doggo_0.is_smelly = true;
    
    Card doggo_1;
    doggo_1.id = 2;
    doggo_1.name = "Noszli";
    doggo_1.weight_kg = 28.65;
    doggo_1.is_smelly = false;

    // TODO: Add a dog that you've known in real life or on tv
    
    printDoggoCard(doggo_0);
    // TODO: print second doggo
}
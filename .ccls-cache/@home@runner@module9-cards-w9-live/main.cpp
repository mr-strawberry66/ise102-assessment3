#include <iostream>
#include "include/ise102.h"
#include "Card.h"
#include "KeycapSet.h"
using namespace std;

void printKeycapSet(KeycapSet set)
{
    print("Keycap Set: ---------------------------------------\n");
    // print out your keycap set
    print("Name: {:>30}\n", set.name);
    print("Profile: \n", set.profile);
    print("Manufacturer: {}\n", set.manufacturer);
    return;
}

int main() {
    
    KeycapSet scientific;
    scientific.name = "DSA Scientific";
    scientific.profile = Profile::DSA;
    scientific.manufacturer = "Signature Plastics";
    scientific.is_sculpted = false;

    printKeycapSet(scientific);
}
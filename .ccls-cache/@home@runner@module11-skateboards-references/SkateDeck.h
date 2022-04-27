#ifndef __SKATEDECK__  // SCREAMING_SNAKE (surround double underscores)
#define __SKATEDECK__
#include <string>

// A digital collectible Skateboard Deck card: it's a record/data structure to
// hold the details of one deck. 
// Note for non-Skateboarders: A deck is the wooden part of a skateboard, 
// which is almost always bought separately by skateboarders. Trucks, wheels,
// bearings etc are bought separately. Decks can also be bought to display
// on a wall, effectively an artwork or collectible in itself.
class SkateDeck   
{
public:
    std::string brand            = "BAKER";
    // Width, side to side, at widest point (inches)
    float width_inches         = 8.0f;       
    // If this is a signature deck, who's the pro skateboarder?
    std::string skater_name         = "";

    // Is this a skateboarder's signature/pro model? 
    bool isSignatureModel() const
    {
        // if there's a name attached, it's a signature model.
        return (skater_name != "");     
    }

    // Returns the deck's width at widest point in millimeters (metric)
    float widthMms()
    {
        return (width_inches * 25.4);
    }

};

#endif // __SKATEBOARD__
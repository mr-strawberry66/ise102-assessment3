#ifndef __SKATEDECK__  // SCREAMING_SNAKE (surround double underscores)
#define __SKATEDECK__
#include <string>
using namespace std;

// How sloped is something?
enum Incline 
{
    MELLOW,
    MEDIUM,
    STEEP
};

/// A basic example of a collectible or record card with 
/// some very generic properties. 
class SkateDeck   // in TitleCase
{
public:
    string brand            = "BAKER";
    /// Width, side to side, at widest point (inches)
    float width_inches         = 8.0f;       
    /// If this is a signature deck, who's the pro skateboarder?
    string skater_name         = "";
    /// How much to the sides slope up? 
    Incline concave         = MELLOW;     
    /// Has carbon fibre to prevent snapping (as much as possible)
    bool carbon_fibre   = false;

    // Is this a particular skateboarder's signature model? 
    bool isSignatureModel()
    {
        // if there's a name attached, it's a signature model.
        return (skater_name != "");     
    }

    // Returns the deck's width at widest point in mms
    float widthMms()
    {
        return (width_inches * 25.4);
    }

    // Get a string describing the incline/steepness of the concave
    string getConcave()
    {
        if(concave == MELLOW) return "mellow";
        if(concave == MEDIUM) return "medium";
        if(concave == STEEP) return "steep";
        return "unspecified"; // Ideally I need UNSPECIFIED_INCLINE I guess
    }    

};  // Note, a class needs a semi colon after the final curly "}"

#endif // __SKATEBOARD__
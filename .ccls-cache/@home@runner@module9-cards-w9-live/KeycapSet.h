#ifndef __KEYCAP_SET__  // SCREAMING_SNAKE (surround double underscores)
#define __KEYCAP_SET__
#include <string>
using namespace std;

enum Profile
{
    DSA,  
    SA,
    CHERRY,
    OEM,
    KAT
};

/// A basic example of a collectible or record card with 
/// some very generic properties. 
class KeycapSet   // in TitleCase
{
public:
    int id                  = 1;
    string name             = "";
    Profile profile         = CHERRY;
    string manufacturer     = "";
    bool is_sculpted        = true;
    float wall_thickness_mm = 1.5f;

    float getWallThicknessCm()
    {
        return wall_thickness_mm / 10;
    }

    string getIdString()
    {
        return to_string(id);
    }

};  // Note, a class needs a semi colon after the final }

#endif // __KEYCAP_SET__
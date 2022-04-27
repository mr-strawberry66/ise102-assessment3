#ifndef __CARD__
#define __CARD__
#include <string>

/// A basic example of a collectible or record card with 
/// some very generic properties. 
class Card
{
public:
    // A unique identifier number 
    int id = 0;
    std::string name;
    float weight_kg = 0.0f;
    bool is_smelly = false;  // benefit of the doubt
};  // Note, a class needs a semi colon after the final }

#endif // __CARD__
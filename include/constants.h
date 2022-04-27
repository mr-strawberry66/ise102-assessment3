/***************************************************
 * Constants
 ****************************************************************
 *
 * Place global constants in here: values that will be
 * used in various parts of your program. If they're
 * related, group them in an enum with a meaningful 
 * data type name like "Progress" or "GemType"
 ***************************************************/
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__
#include <string>
using namespace std;

const string GAME_NAME = "DUNGEONS OF PARRAMATTA LAKE BUSHWALK";

/** Constants that represent the levels of progress through the game, 
 *  from beginning to end. 
*/
enum Progress {
  NO_PROGRESS     = 0,
  FAILED_MINING   = 1,
  HAVE_SILVER = 2,  // and so on, enum handles the rest.
  FAILED_FORGING,
  HAVE_SILVER_KEY,
  HAVE_RUBY,
  HAVE_RUBY_KEY,
  COMPLETED_GAME
};

#endif // end of "header guard" for __CONSTANTS_H__

#ifndef __handy_functions__
#define __handy_functions__
// Get access to things in constants while coding on replit.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "ise102.h"
using namespace std;
using std::string;

// Takes in a minimum number (int) and a maximum number (int), returns a random
// number between the min and max (inclusive)
int randomInRange(int min, int max)
{
  int difference = max - min;
  int rand_in_range = min + (rand() % (difference+1));
  // send back the result.
  return rand_in_range;
}

string toYesNo(bool b)
{
    if (b) return "yes";
    return "no";
}

// Converts US/Imperial inches to metric (Système Internationale) cms.
int inchesToCms(int inches)
{
// TODO: Check if this works. Fix it if it doesn't (google inches to cms)
  int cms = inches / 3.54f;
  return cms;
}

#endif
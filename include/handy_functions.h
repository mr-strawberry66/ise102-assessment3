#ifndef __handy_functions__
#define __handy_functions__
// Get access to things in constants while coding on replit.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "ise102.h"


/* Take a string and return it as upper case.
 *
 * Args:
 *   input: std::string - The string to be converted to upper case.
 *
 * Returns: std::string
 *   The input string converted to upper case.
*/
std::string toUpperCase(std::string input) {
    transform(
        input.begin(),
        input.end(),
        input.begin(),
        ::toupper);

    return input;
}

/* Create a prompt for the player to enter one of two choices.
 *
 * If the player's choice is not one of the two choices, the prompt will
 * be repeated until the player enters one of the two choices.
 *
 * Args:
 *  choiceA: std::string - The first choice the player can make.
 *  choiceB: std::string - The second choice the player can make.
 *
 * Returns: std::string
 *  The player's choice as uppercase.
*/
std::string getPlayerChoice(std::string choiceA, std::string choiceB)
{
    std::string choice = "";
    const std::vector<std::string> CHOICES = {
        choiceA,
        choiceB,
    };

    while (true)
    {
        std::cout << "Enter your choice, " << choiceA << " or " << choiceB << "\n";
        std::cout << " > ";
        std::cin >> choice;

        choice = toUpperCase(choice);

        // Search the CHOICES vector for the player's choice.
        bool valid_choice = std::find(CHOICES.begin(), CHOICES.end(), choice) != CHOICES.end();

        if (valid_choice) return choice;

        std::cout << choice << " is not a valid choice.\n\n";
    }
}

/* Generate a random number betweena a minimum and a maximum (inclusive) value.
 *
 * Args:
 *   min: int - the lowest value to generate.
 *   max: int - the highest value to generate.
 *
 * Returns:
 *  int - a random number between min and max.
*/
int randomInRange(int min, int max) {
  int difference = max - min;
  int rand_in_range = min + (rand() % (difference+1));
  // send back the result.
  return rand_in_range;
}

/* Convert a boolean value to a string.
 *
 * Args:
 *   bool b:
 *     The boolean value to convert.
 *
 * Returns:
 *   std::string
 *     The string representation of the boolean value.
 */
std::string toYesNo(bool b) {
    if (b) return "yes";
    return "no";
}

/* Test to see if a std::string value can be converted to an integer.
 *
 * Args:
 *   input: std::string - The value to convert.
 *
 * Returns: bool
 *   Whether the input can be converted or not.
*/
bool canParseInt(std::string input) {
    try {
        std::stoi(input);
        return true;
    }
    catch (...) {
        return false;
    }
}

/* Convert imperial inches to metric centimeters.
 *
 * Args:
 *   inches: int - The number of inches to convert.
 *
 * Returns: int
 *   The number of inches converted to centimeters.
*/
int inchesToCms(int inches) {
    int cms = inches * 2.54f;
    return cms;
}

#endif

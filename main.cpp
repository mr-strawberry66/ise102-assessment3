#include <iostream>
#include <vector>

#include "cli_commands.h"
#include "guitar.h"
#include "io.h"
#include "include/json.hpp"
#include "include/fmt/format.h"
#include "include/fmt/color.h"
#include "include/handy_functions.h"


/* Main entry point.
 *
 * Get guitar data from a JSON file, then
 * display the menu and execute the user's
 * choice.
*/
int main() {
    // Get guitars from a JSON file or create a default guitar.
    std::string file_path = "guitars.json";
    std::vector<Guitar::Guitar> guitars = io::getGuitars(file_path);

    // Display the opening menu and check for the user's choice.
    while (true) {
        std::string ans = cli::openingMenuChoice();

        if (ans == "Q") {
            break;
        }
        else if (ans == "L") {
            cli::listGuitars(guitars);
        }
        else if (ans == "D") {
            cli::displayGuitar(guitars);
        }
        else if (ans == "A") {
            cli::addGuitar(guitars);
            io::writeGuitarsToFile(file_path, guitars);
        }
        else if (ans == "E") {
            cli::editGuitar(guitars);
            io::writeGuitarsToFile(file_path, guitars);
        }
        else if (ans == "R") {
            cli::deleteGuitar(guitars);
            io::writeGuitarsToFile(file_path, guitars);
        }
        else {
            fmt::print(fg(fmt::color::red), "Invalid choice.\n\n");
        }
    }

    return 0;
}

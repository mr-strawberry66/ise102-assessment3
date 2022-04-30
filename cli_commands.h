#include <iostream>
#include <vector>

#include "guitar.h"
#include "include/fmt/color.h"
#include "include/fmt/format.h"
#include "include/handy_functions.h"


/* Namespace for CLI operations */
namespace cli {

    /* Display the opening menu.
     *
     * Returns: std::string
     *   The user's choice.
    */
    std::string openingMenuChoice() {
        std::string answer;
        std::cout
            << "[L] List guitars\n"
            << "[D] Display a guitar\n"
            << "[A] Add new guitar\n"
            << "[E] Edit existing guitar\n"
            << "[R] Remove a guitar\n"
            << "[Q] Quit\n"
            << "\n"
            << "Enter your choice: ";

        std::ws(std::cin);
        std::getline(std::cin, answer);

        return toUpperCase(answer);
    }

    /* Display a list of guitars in a table format.
     *
     * Args:
     *   std::vector<Guitar> guitars:
     *     The vector of guitars to display.
    */
    void listGuitars(const std::vector<Guitar::Guitar> &guitars) {
        std::vector<std::string> fields = {
            "ID",
            "Brand",
            "Model",
            "Colour",
            "Body",
            "Neck",
            "Fretboard",
            "Artist",
            "Frets",
            "Strings"
        };
        fmt::print(
            fmt::emphasis::bold | fg(fmt::color::light_golden_rod_yellow),
            "Guitars:\n"
        );

        // Print out the table header.
        fmt::print(
            fmt::emphasis::bold | fg(fmt::color::white_smoke),
            "{:<5} {:<15} {:<15} {:<15} {:<15} {:<15} {:<15} {:<15} {:<15} {:<15}\n",
            fields[0],
            fields[1],
            fields[2],
            fields[3],
            fields[4],
            fields[5],
            fields[6],
            fields[7],
            fields[8],
            fields[9]);
        fmt::print(
            fmt::emphasis::bold | fg(fmt::color::white_smoke),
            "----------------------------------------------------------------------------------------------------------------------------------------------\n");

        // Iterate through the guitars and print them out.
        for (const Guitar::Guitar &guitar : guitars) {
            guitar.printSummary();
        }
        std::cout << "\n";
    }

    /* Display a guitar's details.
     *
     * Ask the user for the ID of the guitar
     * to display.
     *
     * Args:
     *   std::vector<Guitar> guitars:
     *     The vector of guitars to search and
     *     display from.
    */
    void displayGuitar(const std::vector<Guitar::Guitar> &guitars) {
        int id;
        fmt::print("Enter the ID of the guitar to display: ");
        std::ws(std::cin);
        std::cin >> id;
        std::cout << "\n";

        // Search for the correct guitar by ID, then display it
        // by calling the printCard() method.
        for (const Guitar::Guitar &guitar : guitars) {
            if (guitar.id == id) {
                guitar.printCard();
                return;
            }
        }

        // If the ID cannot be found, display an error.
        fmt::print("No guitar with ID {0} found.\n\n", id);
    }

    /* Add a new guitar to the dataset.
     *
     * Ask the user for the guitar's details, then
     * add it to the guitars vector.
     *
     * Args:
     *   std::vector<Guitar> &guitars:
     *     The vector of guitars to add the new
     *     guitar to.
    */
    void addGuitar(std::vector<Guitar::Guitar> &guitars) {
        fmt::print("~~~~~~~  Add a guitar ~~~~~~~~\n");
        Guitar::Guitar guitar = Guitar::fromUser(guitars);
        guitars.push_back(guitar);
    }

    /* Edit an existing guitar.
     *
     * Ask the user for the ID of the guitar
     * to edit, then ask for the new details.
     *
     * Args:
     *   std::vector<Guitar> &guitars:
     *     The vector of guitars to edit.
    */
    void editGuitar(std::vector<Guitar::Guitar> &guitars) {
        int id;
        fmt::print("Enter the ID of the guitar to edit: ");
        std::ws(std::cin);
        std::cin >> id;
        fmt::print("\n");

        // Search for the correct guitar by ID and call the update() method.
        for (Guitar::Guitar &guitar : guitars) {
            if (guitar.id == id) {
                guitar.update();
                return;
            }
        }

        // If the ID cannot be found, display an error.
        fmt::print("No guitar with ID {0} found.\n\n", id);
    }

    /* Remove a guitar from the dataset.
     *
     * Ask the user for the ID of the guitar
     * to remove, then remove it from the guitars
     * vector.
     *
     * Args:
     *   std::vector<Guitar> &guitars:
     *     The vector of guitars to remove from.
    */
    void deleteGuitar(std::vector<Guitar::Guitar> &guitars) {
        int id;
        int index = -1;
        fmt::print("Enter the ID of the guitar to delete: ");
        std::ws(std::cin);
        std::cin >> id;
        fmt::print("\n");

        // Find the index of the guitar to delete and store it.
        for (int i = 0; i < guitars.size(); i++) {
            if (guitars[i].id == id) {
                index = i;
                break;
            }
        }

        // If the index was not found, print an error message.
        if (index == -1) {
            fmt::print("No guitar with ID {0} found.\n\n", id);
            return;
        }

        // Check that the user really wants to delete the guitar.
        fmt::print(fg(fmt::color::orange), "Are you sure you want to delete this guitar? (Y/N)\n");
        std::string is_player_sure = getPlayerChoice("Y", "N");

        // Delete the guitar if the user is sure.
        if (is_player_sure == "Y") {
            guitars.erase(guitars.begin() + index);
            fmt::print(fg(fmt::color::orange), "Guitar with ID {0} deleted.\n\n", id);
        }

        // Otherwise, exit without deleting the guitar.
        else {
            fmt::print("Cancelling delete.\n\n");
        }
    }
}

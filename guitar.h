#ifndef __GUITAR__
#define __GUITAR__
#include <iostream>
#include <string>
#include <vector>

#include "include/json.hpp"
#include "include/fmt/color.h"
#include "include/fmt/format.h"


/* Namespace for working with Guitar objects. */
namespace Guitar {

    /* Class to represent a Guitar
     *
     * Attributes:
     *   id: int
     *     The unique ID of the guitar.
     *
     *   brand: std::string
     *     The brand of the guitar.
     *
     *   model: std::string
     *     The model of the guitar.
     *
     *   colour: std::string
     *     The colour of the guitar.
     *
     *   body_material: std::string
     *     What the body of the guitar is
     *     constructed from.
     *
     *   neck_material: std::string
     *     What the neck of the guitar is
     *     constructed from.
     *
     *   fretboard_material: std::string
     *     What material the fretboard is made
     *     of.
     *
     *   artist: std::string
     *     If the guitar is an artist model,
     *     the name of the artist.
     *
     *   number_of_frets: int
     *     How many frets the guitar has.
     *
     *   number_of_strings: int
     *     How many strings the guitar has.
    */
    class Guitar {
        public:
            int id = 0;
            std::string brand;
            std::string model;
            std::string colour;
            std::string body_material = "";
            std::string neck_material = "";
            std::string fretboard_material = "";
            std::string artist_name = "";
            int number_of_frets = 22;
            int number_of_strings = 6;

            /* Constructor. */
            Guitar( int _id = 0,
                    std::string _brand = "",
                    std::string _model = "",
                    std::string _colour = "",
                    std::string _body_material = "",
                    std::string _neck_material = "",
                    std::string _fretboard_material = "",
                    std::string _artist_name = "",
                    int _number_of_frets = 22,
                    int _number_of_strings = 6)
            {
                id = _id;
                brand = _brand;
                model = _model;
                colour = _colour;
                body_material = _body_material;
                neck_material = _neck_material;
                fretboard_material = _fretboard_material;
                artist_name = _artist_name;
                number_of_frets = _number_of_frets;
                number_of_strings = _number_of_strings;
            }

            /* Display the Guitar object in table format to the CLI.
             *
             * Used in conjunction with the cli::listGuitars() function
             * to display all guitars in table format.
            */
            void printSummary() const {
                std::vector<std::string> fields = {
                    std::to_string(id),
                    brand,
                    model,
                    colour,
                    body_material,
                    neck_material,
                    fretboard_material,
                    (artist_name == "") ? "N/A" : artist_name,
                    std::to_string(number_of_frets),
                    std::to_string(number_of_strings)
                };
                fmt::print(
                    fmt::emphasis::italic | fg(fmt::color::white_smoke),
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
                    fields[9]
                );
            }

            /* Display the guitar in a collectable card format to the CLI. */
            void printCard() const {
                fmt::print(
                    fmt::emphasis::bold | fg(fmt::color::light_golden_rod_yellow),
                    "~~~~~~~~~~~  Guitar ~~~~~~~~~~~\n"
                );
                fmt::print(
                    fmt::emphasis::italic | fg(fmt::color::light_golden_rod_yellow),
                    " ID: {0}\n"
                    " Brand: {1}\n"
                    " Model: {2}\n"
                    " Artist: {3}\n"
                    " Colour: {4}\n"
                    " Body Material: {5}\n"
                    " Neck Material: {6}\n"
                    " Fretboard Material: {7}\n"
                    " Number of Frets: {8}\n"
                    " Number of Strings: {9}\n"
                    "\n",
                    id, brand, model,
                    (artist_name == "") ? "N/A" : artist_name,
                    colour, body_material, neck_material,
                    fretboard_material, number_of_frets,
                    number_of_strings
                );
            }

            /* Update a the Guitar object from user input.
             *
             * Ask the user for each field of the Guitar object
             * via the CLI and update the object.
            */
            void update() {
                std::string _brand;
                std::string _model;
                std::string _colour;
                std::string _body_material;
                std::string _neck_material;
                std::string _fretboard_material;
                std::string _artist_name;
                int _number_of_frets;
                int _number_of_strings;

                fmt::print("ID: {0}\n", id);

                fmt::print("Brand: (was {0}): ", brand);
                std::ws(std::cin);
                std::getline(std::cin, _brand);
                if (_brand != "") {
                    brand = _brand;
                }

                fmt::print("Model: (was {0}): ", model);
                std::ws(std::cin);
                std::getline(std::cin, _model);
                if (_model != "") {
                    model = _model;
                }

                fmt::print("Artist: (was {0}): ", artist_name);
                std::ws(std::cin);
                std::getline(std::cin, _artist_name);
                if (_artist_name != "") {
                    artist_name = _artist_name;
                }

                fmt::print("Colour: (was {0}): ", colour);
                std::ws(std::cin);
                std::getline(std::cin, _colour);
                if (_colour != "") {
                    colour = _colour;
                }

                fmt::print("Body Material: (was {0}): ", body_material);
                std::ws(std::cin);
                std::getline(std::cin, _body_material);
                if (_body_material != "") {
                    body_material = _body_material;
                }

                fmt::print("Neck Material: (was {0}): ", neck_material);
                std::ws(std::cin);
                std::getline(std::cin, _neck_material);
                if (_neck_material != "") {
                    neck_material = _neck_material;
                }

                fmt::print("Fretboard Material: (was {0}): ", fretboard_material);
                std::ws(std::cin);
                std::getline(std::cin, _fretboard_material);
                if (_fretboard_material != "") {
                    fretboard_material = _fretboard_material;
                }

                fmt::print("Number of Frets: (was {0}): ", number_of_frets);
                std::ws(std::cin);
                std::cin >> _number_of_frets;
                if (_number_of_frets != 0) {
                    number_of_frets = _number_of_frets;
                }

                fmt::print("Number of Strings: (was {0}): ", number_of_strings);
                std::ws(std::cin);
                std::cin >> _number_of_strings;
                if (_number_of_strings != 0) {
                    number_of_strings = _number_of_strings;
                }

                fmt::print("\n");
            }
    };

    /* Create a JSON object from a Guitar object.
     *
     * Args:
     *   json: nlohmann::json&
     *     A nlohmann::json object to append to.
     *
     *   guitar: Guitar&
     *     The Guitar object to convert to JSON.
    */
    void toJson(nlohmann::json &json, const Guitar &guitar) {
        json = nlohmann::json{
            {"id", guitar.id},
            {"brand", guitar.brand},
            {"model", guitar.model},
            {"colour", guitar.colour},
            {"body_material", guitar.body_material},
            {"neck_material", guitar.neck_material},
            {"fretboard_material", guitar.fretboard_material},
            {"artist_name", guitar.artist_name},
            {"number_of_frets", guitar.number_of_frets},
            {"number_of_strings", guitar.number_of_strings}
        };
    }

    /* Construct a Guitar from JSON.
     *
     * Args:
     *   json: const nloghmann::json&
     *     JSON object to construct Guitar from.
     *
     * Returns: Guitar
     *   A Guitar object constructed from
     *   the JSON object.
    */
    Guitar fromJson(const nlohmann::json &json) {
        Guitar guitar = Guitar(
            json["id"].get<int>(),
            json["brand"].get<std::string>(),
            json["model"].get<std::string>(),
            json["colour"].get<std::string>(),
            json["body_material"].get<std::string>(),
            json["neck_material"].get<std::string>(),
            json["fretboard_material"].get<std::string>(),
            json["artist_name"].get<std::string>(),
            json["number_of_frets"].get<int>(),
            json["number_of_strings"].get<int>()
        );
        return guitar;
    }

    /* Generate a unique ID for a Guitar object.
     *
     * Check the highest current ID in the guitars
     * vector and add 1 to it.
     *
     * Args:
     *   guitars: std::vector<Guitar>&
     *     A vector of Guitar objects.
     *
     * Returns: int
     *   A unique ID for a Guitar object.
    */
    int generateId(const std::vector<Guitar> &guitars) {
        int id = 0;
        for (const Guitar &guitar : guitars) {
            if (guitar.id > id) {
                id = guitar.id;
            }
        }
        return id + 1;
    }

    /* Create a new Guitar object from user input.
     *
     * Args:
     *   guitars: const std::vector<Guitar>&
     *     The vector of guitar objects to be used
     *     for generating a unique ID.
     *
     * Returns: Guitar
     *   A new Guitar object with the user-inputted
     *   values.
    */
    Guitar fromUser(const std::vector<Guitar> &guitars) {
        Guitar guitar;

        // Create a unique ID for the guitar.
        guitar.id = generateId(guitars);

        // Ask the user for each field of the Guitar object.
        std::cout << "Enter the brand: ";
        std::getline(std::cin, guitar.brand);

        std::cout << "Enter the model: ";
        std::getline(std::cin, guitar.model);

        std::cout << "Enter the colour: ";
        std::getline(std::cin, guitar.colour);

        std::cout << "Enter the body material: ";
        std::getline(std::cin, guitar.body_material);

        std::cout << "Enter the neck material: ";
        std::getline(std::cin, guitar.neck_material);

        std::cout << "Enter the fretboard material: ";
        std::getline(std::cin, guitar.fretboard_material);

        std::cout << "Enter the artist name (If not an artist model, enter N/A): ";
        std::getline(std::cin, guitar.artist_name);

        std::cout << "Enter the number of frets: ";
        std::cin >> guitar.number_of_frets;

        std::cout << "Enter the number of strings: ";
        std::cin >> guitar.number_of_strings;

        std::cout << std::endl;

        return guitar;
    }

};
#endif

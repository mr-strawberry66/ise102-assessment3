#include <fstream>
#include <iostream>
#include <vector>

#include "guitar.h"
#include "include/json.hpp"
#include "include/fmt/format.h"


/* Namespace for handling input and output. */
namespace io {

    /* Return a json object of Guitars from a file.
     *
     * Args:
     *   file_path: std::string
     *     The path to the file to read from.
     *
     * Returns: nlohmann::json
     *   The JSON object of Guitars.
    */
    nlohmann::json readGuitarsFromFile(const std::string &file_path) {
        // Create a JSON object and a filestream to the desired path.
        nlohmann::json guitars;
        std::ifstream file(file_path);

        file >> guitars;

        file.close();
        return guitars;
    }

    /* Write a vector of Guitars to a JSON format file.
     *
     * Args:
     *   file_path: std::string
     *     The path to the file to write to.
     *
     *  guitars: std::vector<Guitar::Guitar>
     *    The vector of Guitars to write to the file.
     *
     * Returns: void
    */
    void writeGuitarsToFile(const std::string file_path, const std::vector<Guitar::Guitar> &guitars) {
        // Create a JSON object used for each Guitar,
        // as well as a container JSON object to store
        // all of the guitars.
        nlohmann::json guitar_json;
        nlohmann::json output_json;
        std::ofstream file(file_path);

        for (const Guitar::Guitar &guitar : guitars) {
            Guitar::toJson(guitar_json, guitar);

            // Append the guitar JSON to the container JSON.
            output_json.push_back(guitar_json);
        };

        // Write the container JSON to the file.
        file << output_json.dump(4) << "\n";
        file.close();
    }

    /* Check to see if a file exists or not.
     *
     * Args:
     *   file_path: const std::string&
     *     The path to the file to check exists.
     *
     * Returns: bool
     *   If the file exists or not.
    */
    bool fileExists(const std::string &file_path) {
        std::ifstream infile(file_path);
        return infile.good();
    }

    /* Populate a vector of Guitars from a JSON format file
     * if the file exists. Otherwise, create a generic
     * example Guitar and push that into the vector instead.
     *
     * Args:
     *   file_path: std::string
     *     The path to the file to read from.
     *
     *   guitars: std::vector<Guitar::Guitar>
     *     A vector to populate with Guitars from the
     *     JSON file.
     *
     * Returns: void
     *
     * Catches: nlohmann::detail::parse_error
     *   If the file is not valid JSON.
    */
    std::vector<Guitar::Guitar> getGuitars(const std::string &file_path) {
        std::vector<Guitar::Guitar> guitars;

        // Check to see if the JSON file exists.
        if (fileExists(file_path)) {

            // If exists, try to read the file and populate the vector.
            try {
                nlohmann::json json_guitars = readGuitarsFromFile(file_path);

                for (const nlohmann::json &json_guitar : json_guitars) {
                    guitars.push_back(Guitar::fromJson(json_guitar));
                }
            }

            // If a parse error occurs while reading the file,
            // tell the user an issue occured when reading it.
            catch (nlohmann::detail::parse_error &error) {
                fmt::print("Error parsing JSON file.\n");
            }
        }

        // If the file does not exist, or there was a problem
        // reading the file, let the user know that no guitars
        // could be read, and a default guitar is being used.
        if (guitars.empty()) {
            fmt::print("No guitars found. Generating default guitar.\n\n");

            Guitar::Guitar fender = Guitar::Guitar( 1, "Fender", "Stratocaster",
                                                    "Black", "Ash", "Maple",
                                                    "Maple", "Eric Clapton", 22, 6);
            guitars.push_back(fender);
        }

        return guitars;
    }
};

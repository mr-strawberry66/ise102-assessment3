# Assessment 3


## Note
Due to the number of fields stored in each card, I recommend you extend the width of the terminal, so the `list` funtion displays correctly.


## Design choices

### Namespacing
I decided to create 3 namespaces for the project, one for each module of the codebase. These include:
* `io` - Handles file in / out for the project.
* `Guitar` - Contains the Guitar class and related functions.
* `cli` - Stores the functions that deal with the user input from the main menu.

This allows for easy orgainisation of the modules and easy identification of which part of the system each function or class belongs to.


### JSON structure
When storing a vector of Guitar objects, I felt it made most sense to store the Guitars as an array of json objects. 

Due to the way `nlohmann::json` works, if only one json object is present, it isn't wrapped in an array by default. This is the behaviour I would expect, but for the purpose of this program, I always need the guitars to be inside an array, regardless of the count of guitars.

This is where the `output_json` variable comes in to play in the `writeGuitarsToFile` fuction in `io.h`.

```cpp
void writeGuitarsToFile(const std::string file_path, const std::vector<Guitar::Guitar> &guitars) {
    nlohmann::json guitar_json;
    nlohmann::json output_json;
    std::ofstream file(file_path);

    for (const Guitar::Guitar &guitar : guitars) {
        Guitar::toJson(guitar_json, guitar);

        output_json.push_back(guitar_json);
    };

    file << output_json.dump(4) << "\n";
    file.close();
}
```

By appending the JSON formatted guitar to the `output_json` variable, it will always encase the guitars in an array, even if there is only one guitar.

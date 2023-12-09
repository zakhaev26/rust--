#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream infile("dua.png", std::ios::binary);

    if (!infile) {
        std::cerr << "Error Occurred" << std::endl;
        return 1;  // Return an error code
    }

    // Read the contents of the file into a stringstream
    std::stringstream buffer;
    buffer << infile.rdbuf();

    // Close the input file
    infile.close();

    // Open a new file for writing
    std::ofstream outfile("new_dua.png", std::ios::binary);

    if (!outfile) {
        std::cerr << "Error creating new file" << std::endl;
        return 1;  // Return an error code
    }

    // Write the contents of the stringstream to the new file
    outfile << buffer.rdbuf();

    // Close the output file
    outfile.close();

    std::cout << "File copied successfully." << std::endl;

    return 0;
}
    
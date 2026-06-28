



#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // File path to copy
    const auto FilePath = "FileToCopy";

    // Check if file exists
    if (fs::exists(FilePath)) {  // if (filesystem::exists(FilePath)) {
        // Get file size
        const auto FileSize = fs::file_size(FilePath);   //filesystem::file_size(FilePath)

        // Temporary directory path
        fs::path tmpPath{"/tmp"};  // filesystem::path

        // Check if enough space is available
        if (fs::space(tmpPath).available > FileSize) {
            // Create a new directory inside /tmp
            fs::create_directory(tmpPath / "example");

            // Copy file into new directory with new name
            fs::copy_file(FilePath, tmpPath / "newFile");

            std::cout << "File copied successfully!\n";
        } else {
            std::cout << "Not enough space available.\n";
        }
    } else {
        std::cout << "File does not exist.\n";
    }

    return 0;
}

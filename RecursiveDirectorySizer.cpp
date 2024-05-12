//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

uintmax_t calculate_directory_size(const fs::path& directory, bool follow_symlinks) {
    uintmax_t total_size = 0;
    for (auto& entry : fs::recursive_directory_iterator(directory,follow_symlinks ? fs::directory_options::follow_directory_symlink : fs::directory_options::none)) {
        if (fs::is_regular_file(entry.symlink_status())) {
            total_size += fs::file_size(entry.path());
        }
    }
    return total_size;
}

int main() {
    std::string path;
    std::cout << "Enter the directory path: ";
    std::cin >> path;
    bool follow_links;
    std::cout << "Follow symbolic links? (1 for yes, 0 for no): ";
    std::cin >> follow_links;

    uintmax_t directory_size = calculate_directory_size(path, follow_links);
    std::cout << "The size of the directory is: " << directory_size << " bytes\n";

    return 0;
}

#include <fstream>
#include <iostream>
#include <sstream>

bool toFileBinaryString(const std::string &file_path,
                        std::string &binary_string) {
  std::ifstream fs(file_path.c_str(), std::ios::binary);

  if (!fs.is_open()) {
    std::cout << "[ERROR][io::toFileBinaryString]" << std::endl;
    std::cout << "\t is_open failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  std::ostringstream ss;
  ss << fs.rdbuf();

  fs.close();

  binary_string = ss.str();

  return true;
}

bool toBinaryStringFile(const std::string &binary_string,
                        const std::string &file_path) {
  std::ofstream fs(file_path.c_str(), std::ios::binary);

  if (!fs.is_open()) {
    std::cout << "[ERROR][io::toBinaryStringFile]" << std::endl;
    std::cout << "\t is_open failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  fs << binary_string;

  if (fs.bad()) {
    std::cout << "[ERROR][io::toBinaryStringFile]" << std::endl;
    std::cout << "\t file is bad!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  fs.close();

  return true;
}

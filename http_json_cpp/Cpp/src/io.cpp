#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

bool loadFile(const std::string &file_path, std::string &data_string,
              const bool &is_binary) {
  std::ios::openmode mode = std::ios_base::in;
  if (is_binary) {
    mode = std::ios::binary;
  }

  std::ifstream fs(file_path.c_str(), mode);

  if (!fs.is_open()) {
    std::cout << "[ERROR][io::loadFile]" << std::endl;
    std::cout << "\t is_open failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  std::ostringstream ss;
  ss << fs.rdbuf();

  fs.close();

  data_string = ss.str();

  return true;
}

bool saveFile(const std::string &data_string, const std::string &file_path,
              const bool &is_binary, const int &indent) {
  std::ios::openmode mode = std::ios_base::in;
  if (is_binary) {
    mode = std::ios::binary;
  }

  std::ofstream fs(file_path.c_str(), mode);

  if (!fs.is_open()) {
    std::cout << "[ERROR][io::saveFile]" << std::endl;
    std::cout << "\t is_open failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  if (indent > 0) {
    fs << std::setw(indent) << data_string;
  } else {
    fs << data_string;
  }

  if (fs.bad()) {
    std::cout << "[ERROR][io::saveFile]" << std::endl;
    std::cout << "\t file is bad!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  fs.close();

  return true;
}

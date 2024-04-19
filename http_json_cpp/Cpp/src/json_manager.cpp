#include "json_manager.h"
#include "io.h"
#include <fstream>
#include <iostream>

JsonManager::JsonManager() {}

JsonManager::~JsonManager() {}

bool JsonManager::loadJsonFile(const std::string &file_path, json &json_data) {
  std::ifstream fs(file_path);

  if (!fs.is_open()) {
    std::cout << "[ERROR][JsonManager::loadJsonFile]" << std::endl;
    std::cout << "\t is_open failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  json_data = json::parse(fs);

  return true;
}

bool JsonManager::saveJsonFile(const json &json_data,
                               const std::string &file_path) {
  std::ofstream fs(file_path.c_str());

  if (!fs.is_open()) {
    std::cout << "[ERROR][JsonManager::saveJsonFile]" << std::endl;
    std::cout << "\t is_open failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  const std::string json_string = json_data.dump();

  fs << std::setw(4) << json_string << std::endl;

  if (fs.bad()) {
    std::cout << "[ERROR][JsonManager::saveJsonFile]" << std::endl;
    std::cout << "\t file is bad!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  fs.close();

  return true;
}

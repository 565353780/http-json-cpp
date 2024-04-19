#include "json_manager.h"
#include "io.h"
#include <iostream>

JsonManager::JsonManager() {}

JsonManager::~JsonManager() {}

bool JsonManager::loadJsonFile(const std::string &file_path, json &json_data) {
  std::string json_string;

  if (!loadFile(file_path, json_string, false)) {
    std::cout << "[ERROR][JsonManager::loadJsonFile]" << std::endl;
    std::cout << "\t loadFile failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  json_data = json::parse(json_string);

  return true;
}

bool JsonManager::saveJsonFile(const json &json_data,
                               const std::string &file_path) {
  const std::string json_string = json_data.dump();

  if (!saveFile(json_string, file_path, false, 4)) {
    std::cout << "[ERROR][JsonManager::saveJsonFile]" << std::endl;
    std::cout << "\t saveFile failed!" << std::endl;
    std::cout << "\t file_path:" << file_path << std::endl;
    return false;
  }

  return true;
}

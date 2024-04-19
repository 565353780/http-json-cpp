#include "json_manager.h"
#include <fstream>

JsonManager::JsonManager() {}

JsonManager::~JsonManager() {}

const json JsonManager::loadJsonFile(const std::string &file_path) {
  std::ifstream f(file_path);

  const json data = json::parse(f);

  return data;
}

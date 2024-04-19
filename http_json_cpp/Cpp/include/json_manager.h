#pragma once
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class JsonManager {
public:
  JsonManager();
  ~JsonManager();

  const json loadJsonFile(const std::string &file_path);

public:
};

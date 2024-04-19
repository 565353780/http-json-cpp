#pragma once
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class JsonManager {
public:
  JsonManager();
  ~JsonManager();

  bool loadJsonFile(const std::string &file_path, json &json_data);
  bool saveJsonFile(const json &json_data, const std::string &file_path);

public:
};

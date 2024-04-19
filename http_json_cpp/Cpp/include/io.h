#include <string>

bool loadFile(const std::string &file_path, std::string &data_string,
              const bool &is_binary = false);

bool saveFile(const std::string &data_string, const std::string &file_path,
              const bool &is_binary = false, const int &indent = -1);

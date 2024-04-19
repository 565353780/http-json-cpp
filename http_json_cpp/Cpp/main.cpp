#include "json_manager.h"
#include <nlohmann/json.hpp>

int main(int argc, char **argv) {
  JsonManager json_manager = JsonManager();

  std::string a("test");
  std::cout << a << std::endl;

  return 1;
}

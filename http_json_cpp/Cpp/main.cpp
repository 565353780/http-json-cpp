#include "json_manager.h"
#include <iostream>

int main(int argc, char **argv) {
  JsonManager json_manager = JsonManager();

  std::string a("test");
  std::cout << a << std::endl;

  return 1;
}

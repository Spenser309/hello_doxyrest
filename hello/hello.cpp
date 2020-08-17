#include <iostream>
#include "world.h"
#include "bar.h"

int main() {
  std::cout << "HELLO" << std::endl;
  auto myworld = hello::world();
  auto mybar   = myworld.getBar();

  mybar.print();
}

#include <iostream>
#include "world.h"
#include "bar.h"

namespace hello {
   Bar world::getBar() {
     return this->myBar;
   }
   void world::print() {
     std::cout << "WORLD" << std::endl;
   }
}

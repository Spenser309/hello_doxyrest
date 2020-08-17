#include <iostream>
#include "bar.h"

#pragma once

namespace hello {
   class world {
     Bar myBar;
     public:
     void print();
     Bar getBar();
   };
}

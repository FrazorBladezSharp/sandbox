#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "ECS.h"


namespace Night
{

    enum class Components
    {
        COMP_POSITION,
        COMP_TOTAL
    };

    struct Position
    {
        float x;
        float y;
    };


}



#endif // COMPONENTS_H

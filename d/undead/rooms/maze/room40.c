#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "north"     :MAZ+"room23",
        "south"     :MAZ+"room37"
             ]));

}

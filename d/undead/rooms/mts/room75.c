#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
    "north"     :MTS+"room74",
    "south"     :MTS+"room76"
             ]));

}

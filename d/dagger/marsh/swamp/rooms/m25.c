#include <std.h>
#include "../marsh.h"

inherit MINH;

void create() 
{
    ::create();
    set_exits((["north": RPATH "m24",
	            "south": RPATH "m26",
    ]));
}
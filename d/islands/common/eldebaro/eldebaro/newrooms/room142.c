#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"157",
        "east" : ELROOMSD+"143",
        //"south" : ELROOMSD+"126",
        "west" : ELROOMSD+"141",
        
    ]));
}

#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"109",
        "east" : ELROOMSD+"96",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"94",
        
    ]));
}

#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^The bank of a "+
    "large %^BLUE%^lake%^BOLD%^%^BLACK%^ is visible to the east "+
    "of here.%^RESET%^");
    add_items(({"lake","large lake","shadowlord lake"}),"%^BLUE%^"+
    "Only the bank of this large lake is visible from here and "+
    "what you can make out of its surface paints it a "+
    "blue-green.%^RESET%^");

    set_exits(([
       "west" : F_ROOMS"34-3",
       "east" : F_ROOMS"32-3",
       "north" : F_ROOMS"33-4",
       "south" : F_ROOMS"33-2",
       "southeast" : F_ROOMS"32-2",
       "southwest" : F_ROOMS"34-2",
       "northeast" : F_ROOMS"32-4",
       "northwest" : F_ROOMS"34-4",
    ] ));
}

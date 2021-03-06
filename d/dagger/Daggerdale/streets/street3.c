#include <std.h>
#include "../dagger.h"
inherit CROOM;

void create(){
    set_monsters(({MON"ghost"}),({1}));
    ::create();
    set_repop(35);
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("A ruined street");
    set_short("%^BOLD%^%^BLACK%^A ruined street%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand on a ruined street. It was obviously the scene of a %^RESET%^%^RED%^"
"bloody battle%^BOLD%^%^BLACK%^, as the ground is pockmarked with small craters and the fine cobblestones have "
"been mostly ruined.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "west" : STREETS"street2",
      "east" : STREETS"street4",
     ]));
}
#include <std.h>
inherit ROOM;
void create (){
::create ();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
set_property ("light", 1);
set_property("indoors", 1);
set_short("caves");
set_long("The cave dead ends here.
There are patches of dampness on the <walls>.");

set_smell("default", "You smell the smell of stagnant water.");
set_listen("default", "You hear the very faint sound of trickling water,
but from where?");
set_exits( ([
"northwest" : "/d/dagger/cave1/rooms/room7",
]) );
set_items( ([
"walls" : "The patches of dampness on the wall are green and slimy, they
also don't smell very good. You wonder where the water is coming from."
]) );
}

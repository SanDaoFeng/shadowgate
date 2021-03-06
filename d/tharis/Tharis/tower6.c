// /d/tharis/Tharis/tower6.c //
#include <std.h>
#include "../tharis.h"

inherit ROOM;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(1);
   set_short("One of the watch Towers");
    set_long(
@OLI
        You are in one of the watch towers above the North Gate.
The room is barren, except for a table and some chairs. The
guards now use this for a lounge and common room. There are often
off duty guards in here.
        There are staircases to the upper part of the tower and to the
ground. To the east is the wall and to the west leads over the gate.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"east" : "/d/tharis/Tharis/wall12",
"west":"/d/tharis/Tharis/over_gate",
"up":"/d/tharis/Tharis/tower6t",
"down":ROOMS"main1"
 ] ));
set_items(([
"table":"The table is cluttered with various papers and a mug or two."
]));
}
void reset(){
int num;
int i;
 ::reset();
  if(!present("patrol") && !random(4)) {
num=random(4);

for(i=0;i<num;i++){
  new("d/tharis/monsters/wall_patrol")->move(TO);
}
}
}

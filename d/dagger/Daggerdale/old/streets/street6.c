#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
set_property("light", 2);
  set_short("A Street in Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^You are on East Bakers Avenue.
The street runs East and West from here.
The Crossroads lie to the West.
A metal pole holds an unlit lantern aloft here.
The backside of a building lies to the North of the street.
The high city wall lies to the South of the street.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on East Bakers Avenue.
The street runs East and West from here.
The Crossroads lie to the West.
A metal pole here holds a lit lantern aloft and brightens the night.
The backside of a building lies to the North.
The high city wall lies to the South of the street.
GIL
);
set_smell("default", "You catch the scent of baking bread.");
set_listen("default", "You can hear the sounds of villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
"grate" : "It's a metal sewer grate, the rainwater goes down here and you can be sure that nasty, filthy, things live down there.",
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/streets/street5",
"east" : "/d/dagger/Daggerdale/streets/street7",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}

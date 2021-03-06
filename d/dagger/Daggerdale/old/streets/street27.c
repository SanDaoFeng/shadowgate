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
%^ORANGE%^You are in the Northwest corner of the Market Square.
The street runs South and East from here.
A metal pole holds an unlit lantern aloft here.
Many carts line the square here.
A sign hangs outside of a Bar to the West of here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are in the Northwest corner of the Market Square.
The street runs South and East from here.
A metal pole here holds a lit lantern aloft and brightens the night.
Many locked carts line the square here.
A sign hangs outside of a Bar to the West of here.
GIL
);
set_smell("default", "You catch the scent of Ale on the breeze.");
set_listen("default", "You can hear the sounds of a Bar fight.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
"shop" : "This is where you can drink, eat and be merry.",
"sign" : "<--- Ye Ole Drunken Drow Bar",
"carts" : "These carts carry and sell many things not available in the shops.",
"square" : "This is the central square of Daggerdale, many people sell their wares here.",
]));

  set_exits(([
"south" : "/d/dagger/Daggerdale/streets/street21",
"east" : "/d/dagger/Daggerdale/streets/street28",
"west" : "/d/dagger/Daggerdale/shops/bar",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}

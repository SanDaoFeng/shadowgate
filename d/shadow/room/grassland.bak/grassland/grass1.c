inherit "/std/room";
create() {
::create();
set_light(2);
set_indoors(1);
set_short("grass lands");
set_long("You are somewhere in the grass lands, but you are not sure where.
The 7 ft. high grass, makes you feel like you may never find your way out.
You see a small pond to the west.");
set_exits( ([ "north" : "/d/shadow/room/grassland/grass4.c",
"west" : "/d/shadow/room/grassland/long_pond.c",
]) );
}

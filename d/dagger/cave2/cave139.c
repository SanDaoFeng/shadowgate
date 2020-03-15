#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(3);
    ::create();
    set_long(
      "You are in the lowest levels of this cavern system.  The dark pathways seem to close in upon you, though you can see better from a strange red glow that permeates the tunnels and rooms, though it has no visible source.  The rock here has been blackened, and a deep sense of hatred can almost be tasted in the air."
    );
    set_exits( ([
	"east" : "/d/dagger/cave2/cave140",
	"south" : "/d/dagger/cave2/cave133",
	"southwest" : "/d/dagger/cave2/cave132",
	"southeast" : "/d/dagger/cave2/cave134",
      ]));
    set_items( ([
	"glow" : "Its dark red and menacing.",
	"rock" : "The rocks have more claw marks than fistmarks here.",
      ]) );
}

void init(){
    ::init();

}

void reset(){
    ::reset();

}
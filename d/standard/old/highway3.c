#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("no castle", 1);
    set("short", "The Western Highway in the shadows of the Daroq Mountains");
    set("long",
	"The Daroq Mountains tower above you to the west, blocking "
	"out the sky so much that an eerie twilight covers the land.  "
        "There is a small overgrown path to the south heading towards "
        "some rather ominous-looking peaks in the distance.  "
	"The Great Western Highway, which provides a route of travel "
	"east, ends just west of here in a mountain pass.  There is only "
	"a small break in the forest that surrounds you to the north.");
    set_items(
	(["peaks" : "The peaks you see are the twin peaks of the "
	  "Destiny Mountains.",
	  "path" : "The path is very overgrown and seems to go in "
	    "the direction of the peaks in\nthe distance.",
	  "mountains" : "A huge mountain range that seperates the "
	    "barren Qajip Desert from the fertile lands of the east.",
	  "mountain" : "Kateihl Mountain, a known stronghold of goblins.",
	  "highway" : "The Great Western Highway ends here at a "
	    "mountain pass.",
	  ({"pass", "break"}) : "It is just large enough for you to get "
	    "through.",
	  "forest" : "A very dark, uninviting forest."]) );
    set_exits( 
	      (["west" : "/d/standard/pass1",
		"east" : "/d/standard/highway2"])  );
}

int go_north() {
    this_player()->move_player("/d/standard/orc_valley/guard", "north");
    return 1;
}


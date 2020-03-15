//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/06/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "It smells of decay and horrid death.");
    set_listen("default", "The wind whistles slowly through the trees.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "A cool breeze whistles through the forest chilling you "+
        "to the bone.  High above you, the tree branches are locked in "+
        "a twisted battle of survival effectivly blotting out the sky "+
        "and any light or warmth it provides.  Many dark shadows dance "+
        "about causing a feeling like you are being watched.  The "+
        "forest floor is matted with many rotting leaves and old "+
        "brittle sticks.  You notice a few breaks through the maze of "+
        "ancient trees to the west and north.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
    ]) );
    set_exits( ([
        "north": ROOM_DIR+"forest16",
        "west": ROOM_DIR+"forest14",
    ]) );
}
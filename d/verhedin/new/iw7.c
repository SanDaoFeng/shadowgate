


// Imperial Way, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// som4.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Imperial Way, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Imperial Way, Verhedin%^RESET%^

You can go east, southwest, or west down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"iw8",
    "west" : VNEW+"iw6",
    "southwest" : VNEW+"rr1"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}

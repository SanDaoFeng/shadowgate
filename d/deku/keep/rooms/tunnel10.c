#include <std.h>
#include "../keep.h"
inherit TUNNELU;

void create() {
    ::create();
		set_climb_exits((["climb":({ KEEPR+"tunnel11",20,30,100}),"descend":({KEEPR +"tunnel9",20,30,100})]));

}


#include <std.h>
inherit ROOM;
void create(){
object ob;
:: create();
set_light(2);
set_property("indoors", 0);
set_climate("desert");
set_short("
%^ORANGE%^You are wandering in a desert.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^You are wandering in a desert.%^RESET%^
The wind feels not as warm. The sand is still drifting and the dunes seem to be getting bigger the father south you go. Wildlife runs across your path from time to time but yet the feeling of desolation is still upon you. You feel alone.

ZERINA
);

set_items(([

]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/des180.c",
"northeast" : "/d/attaya/crafters/desert/des181",
"southwest" : "/d/attaya/crafters/desert/des220.c",
"southeast" : "/d/attaya/crafters/desert/des221.c",

]));

set_smell("default", "You can smell nothing.");
set_listen("default", "You can hear the wind as it blows the sand.");

}

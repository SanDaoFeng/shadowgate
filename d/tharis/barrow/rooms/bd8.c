#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("outdoors",1);
    set_long( (:TO,"lng_fun" :) );
    set_short( (:TO, "shrt_fun" :) );
    set_listen("default",
 	"You hear a low cackle in the wind."
    );
    set_smell("default",
	"There is a distasteful odour in the air."
    );
    set_items(([
	"mound":"The large mound is of the barrow type used to "
	"house the dead bodies of long lost warriors.",
	"large mound":"The large mound is of the barrow type used to "
	"house the dead bodies of long lost warriors.",
        ({"hole","stonebrick hole","large stonebrick hole"}):
	"%^BOLD%^%^BLACK%^The hole into the large mound is dark and musty. "
	"You swear you hear voices in your mind as you gaze upon it.",
	"grass":"All the brush grass is dead and withered as though it was "
	"slowly strangled.%^RESET%^",
	"trees":"The dead trees creak in the blowing wind and probably are "
	"responsible for the eerie moaning sounds you hear.%^RESET%^",
    ]));
    set_exits(([
	"west": RPATH "bd9",
	"northwest": RPATH "bd10",
	"north": RPATH "bd7"
    ]));
    set_pre_exit_functions(({"northwest"}),({"exit_fun"}));
    set_pre_exit_functions(({"west"}),({"exit_fun"}));
    set_pre_exit_functions(({"north"}),({"exit_fun"}));
}
void init() {
    ::init();
    add_action("enter_hole","enter");
}
string lng_fun(string str) {
    if(random(10) > 0) {
	str =
            "%^BLUE%^You stand within an %^WHITE%^ancient "
	    "burial field%^BLUE%^ southeast of a large burial mound. "
	    "To the "
	    "northwest is the top of the large burial mound. "
	    "In the side of the burial mound "
	    "is a large stonebrick hole. All around you dead and "
	    "withered %^ORANGE%^trees%^BLUE%^ stand creaking in "
	    "the wind. The brush "
	    "grass here has all died. You notice the temperature drop "
	    "a few degrees in the area.%^RESET%^";
    } else {
	str =
	    "%^BOLD%^%^BLACK%^You are suddenly seized be a sharp pain "
	    "inside your head. Your vision becomes pitch black and you "
	    "fall to the ground screaming in pain. Your body begins to "
	    "writhe in agony and you taste dirt in your mouth.\n\n"
	    "%^RED%^A Voice tells you: "
	    "%^RESET%^Welcome "+TPQCN+". You have entered "
	    "my domain now and i wanted you to know i am aware of your "
	    "presence. I can control your body and mind as i wish...but "
	    "soon i will control your soul!\n\n%^BOLD%^%^BLACK%^"
	    "Suddenly, as fast as it came, the pain vanishes and you slowly "
	    "regain control of your body and mind. You have difficulty "
	    "remembering where you were and where you were going prior to "
	    "the strange possession.%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    if(random(10) > 0) {
	str = "%^BLUE%^Barrow downs.%^RESET%^";
    } else {
	str =
	    "%^BOLD%^%^BLACK%^You are suddenly seized be a sharp pain "
	    "inside your head. Your vision becomes pitch black and you "
	    "fall to the ground screaming in pain. Your body begins to "
	    "writhe in agony and you taste dirt in your mouth.\n\n"
	    "%^RED%^A Voice tells you: "
	    "%^RESET%^Welcome "+TPQCN+". You have entered "
	    "my domain now and i wanted you to know i am aware of your "
	    "presence. I can control your body and mind as i wish...but "
	    "soon i will control your soul!\n\n%^BOLD%^%^BLACK%^"
	    "Suddenly, as fast as it came, the pain vanishes and you slowly "
	    "regain control of your body and mind. You have difficulty "
	    "remembering where you were and where you were going prior to "
	    "the strange possession.%^RESET%^";
    }
    return str;
}

int exit_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^BOLD%^%^BLACK%^A sleepy feeling comes over you while moving "
	"through the barrow downs.%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" gets a glazed "
	"and strange look on "+TPP+" face as "+TPSX+" wanders off.%^RESET%^"
    ,TP);
    return 1;
}	
int enter_hole(string str) {
    if(!str) {
	notify_fail("Enter what?\n");
	return 0;
    }
    if(str == "mound") {
	notify_fail("Enter what?\n");
	return 0;
    } else {
	write("%^BOLD%^%^BLACK%^You clamber down into the cold and dark "
	"hole.%^RESET%^"); 
	tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" clambers down into the cold and dark "
       "hole.%^RESET%^",TP);
        TP->move_player( RPATH "mound6.c" );
	return 1;
    }
}    

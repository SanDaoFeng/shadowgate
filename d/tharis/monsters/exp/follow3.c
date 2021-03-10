#include <std.h>
inherit MONSTER;
object collared, me, sicked;
string collarname, myname, sicname;
int release;
void create() {
  ::create();
   set_name("eagle");
set_id(({"eagle"}));
  set_short("A bald eagle (following "+myname+")");
  set_level(10);
  set_long("This eagle is an awesome pet.  You can buy one.\n");
set_gender("male");
set("race","eagle");
}
void init(){
	::init();
	add_action("follow_set","say");
      set_heart_beat(1);
}
int follow_set(string str){
	if(str!="please follow me") return 0;
	else{
		me = TP;
		myname = TPQCN;
    set_short("A bald eagle (following "+myname+")"); 
    set_heart_beat(1);
return 0;
}
}
int heart_beat() {
      if(environment(TO) !=environment(me)) {
  tell_room(environment(TO), "The eagle flies after "+myname+".\n");
     tell_room(environment(me), "An eagle wings into the room.\n");
      move_object(TO, environment(me));
      }
  ::heart_beat();
}

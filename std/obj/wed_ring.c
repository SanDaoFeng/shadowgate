//	/obj/wed_ring.c
//	from the Nightmare mudlib
//	a wedding ring for the married ones of the mud
//	created by Descartes of Borg august 1992

#include <std.h>
inherit ARMOUR;

string me, spouse;
int jealous;

set_spouse(str) { spouse = str; }
set_me(str) { me = str; }

void init() {
    ::init();
     // Added by Garrett so that animated wedding rings wouldn't go berzerk.
     if (ETO != TP) return;
//removed by Obsidian 080999
//    add_action("remove_ring","remove");
//    add_action("remove_ring","unwear");
    //add_action("notify_spouse","honey");
    call_out("wear", 2, "band");
}

void create() {
    ::create();
    set_id( ({ "band", "night_wed_ring", "wedding ring" }) );
    set_name("band");
    set_short( (:this_object(), "short_fun" :));
    set_long("A Wedding Ring\n");
    set_ac(0);
    set_type("ring");
    set_limbs( ({ "left hand","right hand" }) );
    set_weight(0);
    set_value(0);
    set_property("no animate",1);
}

notify_spouse(str) {
    if(!find_living(spouse)) {
        write(capitalize(spouse)+" is not around.\n");
        return 1;
    }
    //if(!TP->is_monster()) str= "daemon/language_d"->translate(str, TP->query_spoken(), TP);
    message("honey","%^BOLD%^%^RED%^Honey: %^RESET%^"+str+"\n",find_living(spouse));
    message("honey","%^BOLD%^%^RED%^You tell your spouse: %^RESET%^"+str+"\n",TP);
    return 1;
}

void unwear() {
   tell_object(query_worn(),"You may only remove your wedding band through divorce!");
   return;
}

string extra_look() {
    return (capitalize(me)+" is married to "+capitalize(spouse)+".\n"); }

void get() {
// Added the following line to allow an animated wedding ring to be reclaimed.
// Garrett.
  if (objectp(TP) && objectp(ETP) && ETP==ETO && (string)TP->query_name() == me)
    return 1;
    return 0;
}

void drop() { return 1; }

mixed *query_auto_load() {
    return ({ "/std/obj/wed_ring", ({ me, spouse, jealous }) });
}

void init_arg(mixed *arg) {

    me = arg[0];
    spouse = arg[1];
    jealous = arg[2];
    notify_spouse("I'm home.");
}

wear(str) { 
	set_short( (:this_object(), "short_fun" :));
	set_long("A solid gold band.  There is some writing on it.\n");
	set("read", "From "+capitalize(spouse)+" with love.\n");
  if(objectp(ETO) && interactive(ETO))
	ETO->force_me("wear band");
}

  string short_fun() {return ("$&$"+me+"$&$'s wedding band");}
	

string query_spouse() { return spouse; }
string query_me() { return me; }

restore_me(){return 1;}
save_me(){return 1;}

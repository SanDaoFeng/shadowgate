#include <std.h>
inherit "/std/armour";

int uses;
int query_uses(){return uses;}
object ob, ob1;

void create() {
   ::create();
      set_name("%^BOLD%^%^RED%^F%^RESET%^%^RED%^i%^BOLD%^%^RED%^re %^RESET%^%^RED%^Sash%^RESET%^");
      set_short("%^BOLD%^%^RED%^F%^RESET%^%^RED%^i%^BOLD%^%^RED%^re %^RESET%^%^RED%^Sash%^RESET%^");
      set_obvious_short("%^RESET%^%^RED%^A beautiful scarlet colored sash%^RESET%^");
      set_id(({"sash","fire sash","Sash","Fire Sash","Fire sash"}));
      set_long("%^RESET%^%^RED%^This is a beautifully embroidered %^BOLD%^scarlet"+
		" %^RESET%^%^RED%^colored sash.  Along the length of the sash, %^BOLD%^%^RED%^bright"+
		" fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes %^RESET%^%^RED%^are"+
		" embroidered with gently %^BOLD%^%^RED%^g%^WHITE%^l%^YELLOW%^o%^RESET%^"+
		"%^ORANGE%^w%^BOLD%^%^RED%^i%^YELLOW%^n%^WHITE%^g%^RESET%^%^RED%^ runes.  "+
		"%^RESET%^%^RED%^The %^BOLD%^%^RED%^fires %^RESET%^%^RED%^on the sash seem"+
		" to %^YELLOW%^dance %^RESET%^%^RED%^and %^BOLD%^%^RED%^glow %^RESET%^%^RED%^as the"+
		" wearer moves, giving it a seductively soothing appearance.%^RESET%^\n");
      set_weight(5);
      set_value(7200);
      set_ac(0);
      set_type("clothing");
      set_limbs(({"waist"}));
      set_size(-1);
      while((int)TO->query_property("enchantment") != 5) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment",5);
      uses = random(1000)+100;
      }
      set_wear((:TO,"wearme":));
      set_remove((:TO,"unwearme":));
      set_item_bonus("influence",5);
   set_lore(
      "These sashes are common among high ranking members of the Church of Kossuth. T"+
      "hey are made by priests of the Church so that others can identify their status."+
      "  Though in recent times the sashes have also been seen on Sunites, though embroidered"+
      " with golden threads in honor of the fabled Sash of Sune, a holy relic of the faith.");
}

int wearme(string str){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The sash doesn't seem to fit you.");
     return 0;
   }
   tell_room(environment(ETO),"%^RED%^"+ETOQCN+" carefully wraps the beautiful sash around "+ETO->query_possessive()+" waist.%^RESET%^",ETO);
   tell_object(ETO,"%^RED%^You carefully wrap the beautiful sash around your waist.%^RESET%^");
   return 1;
}

int unwearme(string str){
   tell_room(environment(ETO),"%^RED%^"+ETOQCN+" slowly removes the sash.%^RESET%^",ETO);
   tell_object(ETO,"%^RED%^You feel dissapointment as you slowly remove the sash.%^RESET%^");
   return 1;
}

void init(){
    ::init();
    add_action("read_runes","read");
    add_action("start","start");
    add_action("escape_fun","escape");
    add_action("dance","dance");
}

int read_runes(string str){
    if(!str) notify_fail("Read What?");
    if(str!="runes") return 0;
    write("%^BOLD%^%^RED%^Long be gone the days of safety.\nLet this sash protect you.\nSimply %^RESET%^%^RED%^'start the fire'%^BOLD%^, and I shall serve you.\n%^RESET%^%^RED%^'Dance' %^BOLD%^and another shall come.\n%^RESET%^%^RED%^'Escape' %^BOLD%^and join me in my plane.%^RESET%^");
    return 1;
}

int start(string str){
   if(!str) notify_fail("What are you trying to do.  You mean start a fire?");
   if(str == "fire"||str=="the fire"||str=="a fire"){             
      tell_room(environment(ETO),"%^RED%^"+ETOQCN+" slowly removes the sash and holds it high in the air.  Turning quickly, "+ETO->query_subjective()+" wraps the sash around "+ETO->query_objective()+"self and the sash bursts into a massive wall of protective fire!%^RESET%^",ETO);
      tell_object(ETO,"%^MAGENTA%^You pull the sash off and hold it high in the air.  Then turning quickly, you wrap the sash around yourself and it bursts into a protective wall of fire!%^RESET%^");
      new("/cmds/spells/w/_wall_of_fire")->use_spell(ETO,"me",10,100,"mage");
      return 1;
   }
}
int escape_fun() {
    if(!(TO->query_worn())) {
	notify_fail("You must be wearing your sash!\n");
    	return 0;
    }
  if (!objectp(ETO)){
    return 0;
  }
  if(ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()){
  ETO->set_paralyzed_message("info",ETO);
  return 1;
  }
    if(ETO->query_current_attacker() == 0) {
	notify_fail("You are not in any danger!\n");
	return 0;
    }
    if (objectp(EETO)){
      if(EETO->query_property("no teleport")) {
      notify_fail("A magical barrier halts your escape!");
      return 0;
      }
    }
    if(uses<1){
	tell_object(TP,"%^BOLD%^%^RED%^The sash has no more magic.%^RESET%^");
   return 1;
   } 
    write("%^BOLD%^%^RED%^Spinning around, you pull the sash from your waist and disappear within its folds!");
    say("%^BOLD%^%^RED%^"+TPQCN+" quickly removes the sash and spins around!\n%^BOLD%^%^RED%^"+TPQCN+" vanishes beneath the folds of the sash!%^RESET%^",TP);
    TP->move_player("/d/antioch/ruins/portal/p1.c","in a fiery blaze");
    TP->set_paralyzed(2,"%^MAGENTA%^You are stunned from the plane shift!%^RESET%^");
     uses --;
    return 1;
}

int dance(){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(TP,"%^BOLD%^%^RED%^You must be wearing the sash to make use of its magic!%^RESET%^");
   return 1; 
   }
   if(present("elemental",environment(ETO))){
	tell_object(TP,"%^RESET%^%^ORANGE%^There are already elementals protecting you!%^RESET%^");
   return 1; 
   }
   if(uses<1){
	tell_object(TP,"%^BOLD%^%^RED%^The sash has no more magic.%^RESET%^");
   return 1;
   } 
	tell_object(TP,"%^BOLD%^%^RED%^You roll your hips seductively while waving the sash in hypnotic motions, summoning great elementals to your side!%^RESET%^");
     tell_room(environment(ETO),"%^BOLD%^%^RED%^As "+ETOQCN+" waves the sash in hypnotic motions and rolls "+ETO->query_possessive()+" hips seductively, great elementals come to aid "+ETO->query_objective()+"!%^RESET%^",ETO);
      ob=new("/d/magic/obj/felemental.c");
      ob->move(environment(ETO));
      ob->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob);
      ob1=new("/d/magic/obj/felemental.c");
      ob1->move(environment(ETO));
      ob1->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob1);
      uses --;
      return 1;
}
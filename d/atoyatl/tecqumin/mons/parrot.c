#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
#define COLOURS ({"%^BOLD%^%^YELLOW%^", "%^BOLD%^%^BLUE%^", "%^BOLD%^%^RED%^", "%^BOLD%^%^YELLOW%^",\
"%^BOLD%^%^CYAN%^", "%^BOLD%^%^GREEN%^", "%^BOLD%^%^GREEN%^"})

inherit MONSTER;

mapping sayings;
string owner;
int cloned;
string short_desc();
string long_desc();
void settle_down();

void create(){
  ::create();
   set_long((:TO, "long_desc":));
   set_name("parrot");
      set_property("not random monster", 1);
   set_short("%^BOLD%^%^BLUE%^br%^RED%^igh%^CYAN%^tl%^BLUE%^y"
     +" p%^YELLOW%^l%^BLUE%^u%^CYAN%^m%^YELLOW%^e%^BLUE%^d"
     +" %^BLUE%^pa%^RED%^rr%^BLUE%^ot%^RESET%^");
   set_id(({"parrot","bright parrot", "brightly plumed parrot", "jungle parrot"}));
  if (random(2)){
    set_gender("male");
  } else {
    set_gender("female");
  }
  set_race("bird");
  cloned = 0;
  set_heart_beat(1);
  set_no_clean(1);
  set_property("no animate",1);
  set_property("no random treasure", 1);
}

void set_sayings(mapping s){
  sayings = s;
}

void report(string str){
//  "/daemon/reporter_d.c"->report("lujke", str);
}

mapping query_sayings(){
  return sayings;
}

void output(string what, string language){
  set_lang(language, 100);
  set_spoken(language);
  set("speech string", "%^BOLD%^%^YELLOW%^squawk");
  force_me("say " + what);
}

void squawk(){
  int count, total, i, x, y, roll, num;
  string * ks, * usables, msg, speech, describe, language, colour, saylias, saylias_start, saylias_end, * alks, junk, new_key;
  object onr, * ps;
  mapping als;
  if (!mapp(sayings) || sizeof(sayings)<1) return;
  ks = keys(sayings);
  count = sizeof(ks);
  if (count<1){
    return;
  }
  onr = find_player(owner);
  if (!objectp(onr))
  {
    report("finding owner in immediate environment");
    ps = all_living(ETO);
    ps -= ({TO});
    foreach(onr in ps){
      if (interactive(onr)) break;
    }
    if (!objectp(onr))
    {
      ps = children("/std/user.c");
      foreach(onr in ps){
        if (interactive(onr)) break;
      }
    }
  }
  if (objectp(onr) && interactive(onr))
  {
    als = onr->query_aliases();
    if(mapp(als) && sizeof(als)>0)
    {
      alks = keys(als);
      if (member_array("say", alks)!= -1) 
      {
        saylias = als["say"];
        if (stringp(saylias) && strlen("saylias")>0)
        {
          saylias = "/daemon/stripper_d"->stripcolors(saylias);
          saylias = saylias[4..strlen(saylias)-1];
          report ("sscanffing saylias: " + saylias);
          num = sscanf(saylias, "%s$*%s", saylias_start, saylias_end);
          report ("Saylias sscanffed");
        } else 
        {
          saylias_start = "";
          saylias_end = "";
        }
      }
    }
  } else 
  {
    report("Onr is not an object");
  }
  report("Saylias: " + saylias);
  report ("Saylias_start: " + saylias_start + "|End of Saylias_start");
  report(" Saylias_end: " + saylias_end + "|End of Saylias_end");
  total = 0;
  usables = ({});
  for (i=count-1;i>=0;i--){
    x = sayings[ks[i]][0];
    msg = ks[i];
    if (num>0)
    {
      if(strlen(saylias_start)>0 && interact(saylias_start, ks[i]))
      {
        report ("sscanffing ks[i]: " + ks[i]);
        sscanf (ks[i], "%s"+ saylias_start+"%s", junk, new_key);
        report ("ks[i] sscanffed");
        new_key = junk + new_key;
        sayings[new_key] = sayings[ks[i]];
        map_delete(sayings, ks[i]);
      } else 
      {
        report(ks[i] + " does not contain " + saylias_start);
      }
    }
    if (num>1)
    {
      if(strlen(saylias_end)>0 && interact(saylias_end, ks[i]))
      {
        sscanf (ks[i], "%s"+ saylias_end+"%s", junk, new_key);
        new_key = junk + new_key;
        sayings[new_key] = sayings[ks[i]];
        map_delete(sayings, ks[i]);
      } else 
      {
        report(ks[i] + " does not contain " + saylias_end);
      }
    }
    if (x<3 && random(500)) continue; //Just occasionally, it might squawk out something it only heard once or twice.
    usables += ({ks[i]});
    total += x;
  }
  count = sizeof(usables);
  if (count<1){
    report("There are no usable usables");
    return;
  }
  report("%^BOLD%^%^CYAN%^About to actually squawk!");
  y = 0;
  roll = random(total);
  for (i = 0; i<count; i++){
    report("Actually squawking. i: " + i);
    if (sizeof(usables)<=i) 
    {
      report("%^BOLD%^%^YELLOW%^Size of usables: " + sizeof(usables) + " i: " + i);
      continue;
    }
    if ( member_array(usables[i], ks) == -1 )
    {
      report("%^BOLD%^%^MAGENTA%^usables[i]: " + usables[i] + " is not a member of sayings");
      continue;
    }
    x = sayings[usables[i]][0];
    y += x;
    report ("%^BOLD%^%^BLACK%^x: " + x + " y: " + y);
    if (roll <y){
      report("%^BOLD%^%^MAGENTA%^roll: " + roll +" < y: " + y);
      language = sayings[usables[i]][1];
      speech =  sayings[usables[i]][2];
      describe =  sayings[usables[i]][3];
      set("describe string", ""+ describe );
      colour = COLOURS[random(sizeof(COLOURS))];
      
      output("'"+ colour + usables[i] + "'", language);
      break;
    } 
  }
  report("Finished actually squawking");
  if (random(4)){
    call_out("squawk", 1 + random(4));
  }
}


void catch_say(string str){
  mixed * details;
  int num, sentences, i, n;
  string language, speech, describe, sentence1, sentence2, sentence3, sentence4, sentence5, sentence6, saylias, saylias_start, saylias_end;
  string * ks, * alks;
  mapping als;
  if (TP->id("parrot")){
    return;
  } 
  if (mapp(sayings) && sizeof(sayings)>0) ks = keys (sayings);
  else ks = ({});
  language = TP->query_language();
  if (catch(  str = "/daemon/stripper_d.c"->stripcolors(str))) return;
  if (interactive(TP))
  {
    report("TP is interactive");
    als = TP->query_aliases();
    if (mapp(als) && sizeof(als)>0)
    {
      report("TP has some aliases");
      alks = keys(als);
      if (member_array("say", alks)!=-1)
      {
        report("TP has an alias for 'say'");
        saylias = als["say"];
        if (catch( saylias = "/daemon/stripper_d.c"->stripcolors(saylias))) return;
        report("Colour stripped saylias: " + saylias);
        while (str[0]==" ") str = str[1..strlen(str)-1];
        report("Colour stripped heard string: " + str);
        n = sscanf(saylias, "%s$*%s", saylias_start, saylias_end);
        if (n>1)
        {
          report("saylias_end: " + saylias_end);
          str = str[0..strlen(str)-1-strlen(saylias_end)];
          while (str[0]==" ") str = str[1..strlen(str)-1];
          report("str with saylias_end removed: " + str);
        }
        if (n>0)
        {
          report("saylias_start: " + saylias_start);
          saylias_start = saylias_start[4..strlen(saylias_start)-1];
          str = str[strlen(saylias_start)..strlen(str)-1];
          while (str[0]==" ") str = str[1..strlen(str)-1];
          report("str with saylias_start removed: " + str);
        }
      }
    }
  }
  sentences = sscanf(str, "%s.%s.%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4, sentence5, sentence6);
  switch (sentences){
  case 0:
    sentence1 = str;
    sentences = 1;
    break;
  case 1:
    sentences = sscanf(str, "%s.%s", sentence1, sentence2);
    break;
  case 2:
    sentences = sscanf(str, "%s.%s.%s", sentence1, sentence2, sentence3);
    break;
  case 3:
    sentences = sscanf(str, "%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4);
    break;
  case 4:
    sentences = sscanf(str, "%s.%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4, sentence5);
    break;
  case 5:
    sentences = sscanf(str, "%s.%s.%s.%s.%s.%s", sentence1, sentence2, sentence3, sentence4, sentence5, sentence6);
 }
  speech = TP->query("speech string");
  if (speech == 0) speech = "say";
  speech += "s";
  describe = TP->query("describe string");
  if (describe == 0) describe = "";
  for (i=0;i<sentences;i++){
    switch(i){
    case 0:
      str = sentence1;
      break;
    case 1:
      str = sentence2;
      break;
    case 2:
      str = sentence3;
      break;
    case 3:
      str = sentence4;
      break;
    case 4:
      str = sentence5;
      break;
    case 5:
      str = sentence6;
      break;
    }
    if (strlen(str)>1 && str[0..0] == " "){
      str = str[1..strlen(str)-1]; //remove any starting space from sentence
    } 
    if (catch(str = FILTERS_D->filter_colors(str))) return;
    if (sizeof(ks) <1 || member_array(str, ks)!= -1){
      num = sayings[str][0];
      num++;    
    } else {
      num = 1;
    }
    details = ({num, language, speech, describe});
    sayings[str] = details;
  }
  return;
}

string remove_saylias(string str, string saylias){
  
}


void heart_beat(){
  object *players, *obs, own, env;
  int i, count;
  if (!stringp(owner)) {return;}
  if (!objectp(ETO)){ return;}
  if (!present(owner, ETO)){
    players = children("/std/user.c");
    count = sizeof(players);
    if (count <1) {return;}
    for (i=0;i<count;i++){
      if ((string)players[i]->query_name() == owner){
        own = players[i];
        break;
      }
    }
    if (objectp(own)){
      env = environment(own);
      if (objectp(env)){
        tell_room(ETO, "The parrot flies off");
        tell_room(env, "A parrot flies in and lands close by " + own->QCN, own);
        tell_object(own, "A parrot flies in and lands next to you.");
        move(env);
        own->add_follower(TO);
      } else {
        tell_room(ETO, "The parrot looks distressed, as its owner's environment is broken");
      }
    } else {
      tell_room(ETO, "The parrot looks distressed, as it can't find its owner");
    }
  }
}

void init(){
  if (cloned ==1){// This check prevents abuse by dropping and insta-getting
    remove();
    return;
  }
  ::init();
  add_action("stroke", "stroke");
  add_action("get_me", "get");
}

int get_me(string str){
  if (id(str)){
    return notify_fail("The "+query_short()+"%^RESET%^ is feeling too flighty to let"
     +" you pick it up at the moment. Perhaps you could <stroke> it first, to help it"
     +" settle down?");
  }
}

string long_desc(){

  string desc;
  if (cloned == 1){remove(); return "";}
  desc = "A %^BOLD%^%^BLUE%^br%^RED%^igh%^CYAN%^tl%^BLUE%^y f%^YELLOW%^ea"
     +"%^BLUE%^th%^CYAN%^er%^YELLOW%^e%^BLUE%^d%^RESET%^, perky"
     +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l"
     +"%^BOLD%^e %^BLUE%^pa%^RED%^rr%^BLUE%^ot%^RESET%^. It has a cheerful"
     +" looking %^BOLD%^%^YELLOW%^bright yellow beak%^RESET%^, and beady"
     +" %^GREEN%^br%^BOLD%^i%^RESET%^%^GREEN%^g%^BOLD%^ht"
     +" gr%^RESET%^%^GREEN%^ee%^BOLD%^n eyes%^RESET%^.\nIt looks in too"
     +" flighty a mood to be handled at the moment, but perhaps if you"
     +" were to <stroke> it a bit, it might let you pick it up.\n";

  if (!objectp(ETO)){desc += "%^BOLD%^%^RED%^ERROR - the parrot is in a"
    + " broken environment. Please make a bug report on the parrot.\n\n";}
  if (stringp(owner) && present(find_player (owner), ETO)){
    if (find_player(owner) == TP){
      desc += "The parrot flaps around happily near you.";
    } else {
      desc += "It seems to be mostly flapping around near " +find_player (owner)->QCN;
    }
  } else {
    desc+= "It seems to be flapping around on its own at the"
      +" moment";
  }
  return desc;
}

int is_living(){
  return 1;
}

int stroke(string str){
  if (!id(str)){ return notify_fail("Stroke what?");}
  if (cloned == 1){
    remove();
    return;
  }
  if (!objectp(ETO)){
    return notify_fail("ERROR - the parrot's environment is broken."
     +" Please make a bug report on the room you are in");
  }
  tell_object(TP, "You scratch the parrot on the top of its head and tickle it under the chin. It cocks its head, assenting to be picked up");
  tell_room(ETO, TPQCN + " scratches the parrot on the top of its head and tickles it under the chin. It cocks its head, assenting to be picked up",
TP);
  settle_down(); //separated some code out, so it can be used with 
  return 1;     //different messages - Lujke
}

void set_cloned(int cl){
  cloned = cl;
}

void settle_down(){
  object ob, * conts;
  int i, count;
  if (!objectp(ETO)){return;}
  ob = new(OBJ + "parrot.c");
  if (!objectp(ob)){
    tell_room(ETO, "ERROR - parrot isn't working. Please tell Lujke");
  }
  ob->set_sayings(([]));
  if (mapp(sayings)){
    ob->set_sayings(sayings);
  }
  ob->set_cloned(-1);
  ob->move(ETO);
  if (stringp(owner)){
    ob->set_owner(owner);
  }
  cloned = 1;
  set_name("broken");
  set_race("cloned object");
  set_id(({"clonedparrot"}));
  call_out ("remove", 1);
  return 1;
}

int is_parrot(){
  return 1;
}

int set_owner(string own){
  object leader;
  if (cloned == 1){remove();}
  if (!stringp(own)){ return -1;}
  owner = own;
  leader = find_player(owner);
  if (!objectp(leader)){
    leader = present(owner, ETO);
  }
  if (!objectp(leader)){
    return -1;
  }
  leader->add_follower(TO);
  tell_player(leader, "The parrot is now following you!\n");
  return 1;
}

string query_owner(){
  return owner;
}

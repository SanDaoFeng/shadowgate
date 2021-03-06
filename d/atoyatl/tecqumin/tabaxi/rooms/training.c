#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;
object * trainees;

void create() {
  ::create();
  trainees = ({});
  set_short("Training field");
  set_long("%^GREEN%^This field has been set up with a %^RESET%^circular sparring area%^GREEN%^ and a"
          +" number of %^ORANGE%^straw padded targets%^GREEN%^ for weapons practice. To the north,"
          +" there are some %^RESET%^archery targets%^GREEN%^. To the south, you can see a somewhat"
          +" overgrown field with some %^ORANGE%^catapults%^GREEN%^ in it.");
  set_exits( ([ "south" : TABAXROOM + "catapaults" ,
               "east": TABAXROOM + "stockade"
             ]) );
}

void init(){
  ::init();
  add_action("train_em", "train");
  set_had_players(3);
}

void reset(){
  int i, j, flag;
  object war, * commanders, *stuff;
  ::reset();
  if (sizeof(trainees)>0){
  tell_room(TO, "%^ORANGE%^Another batch of tabaxi trainees graduate to warrior status");
    for(i=0;i<sizeof(trainees);i++){
      if (!present(trainees[i], TO)){
        continue;
      }
      war = new (MOB + "tabaxi_warrior");
      war->move(TO);
      commanders = trainees[i]->query_commanders();
      if (sizeof(commanders)>0){
        for (j=0;j<sizeof(commanders);j++){
          war->add_commander(commanders[j]);
        }
      }
      war->set_gender(trainees[i]->query_gender());
      stuff=all_inventory(trainees[i]);
      if (sizeof(stuff)>0){
        for (j=0;j<sizeof(stuff);j++){
          flag = 0;
          if (stuff[j]->query_worn()){
            flag = 1;
          }
          if (member_array(stuff[j], trainees[i]->query_wielded())!=-1){
            flag = 2;
          }
          stuff[j]->move(war);
          if (flag ==1){
            war->force_me("wear " + stuff[j]->QCN);
          }
          if (flag ==2){
            war->force_me("wield " + stuff[j]->QCN);
          }
        }
      }
      trainees[i]->remove();
    }
  }
}

int train_em(string str){
  object * wielded;
  if (TP->id("tabaxi peasant")){
    if (sizeof(TP->query_wielded())<1){ 
      tell_room(TO, TPQCN + " would like to train, but doesn't have a weapon in hand to train with");
      return 1;
    }
    trainees += ({TP});
    wielded = TP->query_wielded();
    TP->force_me("emote sets about training with " + TP->QP + " " +
                    (string)wielded[0]->query_short() );
    TP->force_me("pose training with " + TP->QP + " " + (string)wielded[0]->query_short() );
    return 1;
  }
  return 0;
}

object * query_trainees(){
  return trainees;
}
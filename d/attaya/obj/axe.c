#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/double_axe.c";


void create()
{
    ::create();
    set_name("Battleaxe of the Dominion");
    set_id( ({"Battleaxe of the Dominion","battleaxe","axe","dominion axe","axe of the dominion", "dominion battleaxe","double axe","double bladed axe"}) );
    set_short("%^BLUE%^Battleaxe of the %^RED%^Dominion%^RESET%^");
    set_obvious_short("%^BLUE%^a massive dark%^RESET%^-%^RED%^bladed %^RESET%^%^BOLD%^double-%^BLUE%^axe%^RESET%^");

    set_long("%^BLUE%^This massive double-bladed %^RED%^axe%^BLUE%^ is forged from some sort of %^RESET%^material%^BLUE%^ that is almost "
        "impossibly light weight.  It gives the axe a heft that rivals much lighter %^MAGENTA%^blades%^BLUE%^.  Two double-bladed axe heads "
        "rest on either end of a %^RESET%^%^BOLD%^long %^YELLOW%^haft%^RESET%^%^BLUE%^.  Each of the axe heads is a %^RESET%^crecent "
        "%^BOLD%^moon %^RESET%^%^BLUE%^shape, longer towards the point, almost sword-like, while thicker and more rounded towards the "
        "base of the axe head.  The axe heads are thin and are shaped so that %^CYAN%^wind%^BLUE%^ resistance passing over them allows "
        "the wielder the ability to alter the direction of his swings with hardly more than the twist of a wrist.  The %^RESET%^%^BOLD%^shaft "
        "%^RESET%^%^BLUE%^of the axe is made of an %^RESET%^%^BOLD%^%^BLACK%^inky material%^RESET%^%^BLUE%^ that fluctuates between the "
        "darkest black and midnight blue.  Dark shapes can be seen swirling inside the material and it has an almost %^BOLD%^%^BLACK%^oily "
        "%^RESET%^%^BLUE%^texture to the touch.  A %^YELLOW%^handgrip%^RESET%^%^BLUE%^ has been fashioned onto the center of the haft to allow for "
        "a firm grasp of the %^RED%^weapon%^BLUE%^.  The handgrip looks to be made of some kind of ancient "
        "%^YELLOW%^hide%^RESET%^%^BLUE%^.  Even though the hide is clearly %^RESET%^%^BOLD%^ancient%^RESET%^%^BLUE%^, it is still soft and supple "
        "as if it were tanned only yesterday.  Whatever enchantment protects this weapon must be powerful indeed.%^RESET%^");

    set_lore("%^CYAN%^Little is known about this devestating weapon.  "
        "It is said to have once belonged to a great warrior god who lead a "
        "distant empire.  The Battleaxe of the Dominion has changed hands many "
        "times.\n"
        "It has been present at some of the bloodiest battles in history and "
        "carries many memories.");

    set_weight(5);
    set("value",150000);
    set_property("no curse",1);
    set_property("enchantment",6);

    set_item_bonus("strength",4);
    set_item_bonus("constitution",4);
    set_item_bonus("armor bonus",4);

    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"extra_unwield":));
    set_hit((:TO, "extra_hit":));
    set_weapon_prof("exotic");
}


void init()
{
    ::init();
    if(!objectp(ETO) || !living(ETO)) { return; }
    TO->set_size(ETO->query_size()+1);
    tell_object(ETO,"The axe seems to change size in your hands, shaping itself so it would take two hands to use!");
    if((string)TO->query_weapon_prof() != "exotic") TO->set_weapon_prof("exotic"); // changing to exotic kthx - Nienne.
}


int extra_wield()
{
    string quest = "%^RESET%^%^YELLOW%^Returned the Dominion Warrior to eternal rest.%^RESET%^";
    if(!objectp(TO) || !objectp(ETO)) { return 0; }

    if(avatarp(ETO)) { return 1; }

    if((int)ETO->query_level() < 40)
    {
        tell_object(ETO,"%^BOLD%^%^RED%^A shadowy presence tells you: %^RESET%^You pathetic little fool, you cannot handle such power!");
        return 0;
    }
    if(ETO->query_name() == "Cruiser Tetron") { return 1; }

    if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
        tell_object(ETO,"You find it impossible to lift two such mighty weapons!",ETO);
        return 0;
    }

    if(member_array(quest,ETO->query_mini_quests()) == -1 && member_array("Achieved: " + quest,ETO->query_mini_quests()) == -1)
    {
        write("%^MAGENTA%^You have not yet earned the right to wield such a weapon.");
        return 0;
    }

    ETO->set_property("master weapon",1);
    tell_object(ETO,"%^BLUE%^Ancient forces are at work here...  Be wary. ");
    tell_object(ETO,"%^RED%^You tightly grasp the ancient double axe.");
    tell_room(EETO,"%^RED%^"+ETO->QCN+" tightly grasps the ancient double axe.%^RESET%^",ETO);
    return 1;
}


int extra_unwield()
{
    if(!objectp(TO)) { return 1; }
    if(!objectp(ETO)) { return 1; }

    tell_object(ETO,"%^GREEN%^You shudder as you release the ancient double axe.");
    ETO->set_property("master weapon",-1);
    tell_room(EETO,"%^GREEN%^"+ETO->QCN+" shudders as "+ETO->QS+" release the ancient double axe.",ETO);
    return 1;
}


int extra_hit(object targ)
{
    int rand,size;
    object head;
    rand = roll_dice(1,10);

    if(!objectp(targ)) { return 0; }
    if(!objectp(ETO))  { return 0; }
    if(!objectp(EETO)) { return 0; }

    size = TO->query_size();
    size += 2;

    if(roll_dice(1,100) > 37) { return roll_dice(1,size); }

    size = size*2;

    if(rand > 0 && rand < 5) // between 1 and 4 or 40%
    {
        tell_object(ETO,"%^GREEN%^You spin the heavy axe quickly and turn your body, using the momentum to deliver a devastating blow on "+targ->QCN+"!%^RESET%^");
        tell_object(targ,"%^GREEN%^"+ETO->QCN+" spins "+ETO->QP+" heavy axe quickly and turns "+ETO->QP+" body, using the momentum to hit you with devastating force!%^RESET%^");
        tell_room(EETO,"%^GREEN%^"+ETO->QCN+" spins "+ETO->QP+" heavy axe quickly and turns "+ETO->QP+" body, using the momentum to hit "+targ->QCN+" with a devastating blow!%^RESET%^",({targ,ETO}));
        targ->do_damage("torso",roll_dice(5,size));
    }

    if(rand > 2 && rand < 6) // between 3 and 5 or 30%
    {
        tell_object(ETO,"%^RED%^You roar as you bring one end of the ancient double axe down on "+targ->QCN+" in a deadly overhead chop!%^RESET%^");
        tell_object(targ,"%^RED%^"+ETO->QCN+" roars as "+ETO->QS+" brings one end of "+ETO->QP+" ancient double axe down on you in a deadly overhead chop!%^RESET%^");
        tell_room(EETO,"%^RED%^"+ETO->QCN+" roars as "+ETO->QS+" brings one end of "+ETO->QP+" ancient double axe down on "+targ->QCN+" in a deadly overhead chop!%^RESET%^",({targ,ETO}));
        targ->do_damage("torso",roll_dice(7,size));
    }

    if(rand > 4 && rand < 7) // between 4 and 6 or 20%
    {
        tell_object(ETO,"%^CYAN%^You twirl the massive axe quickly and send the haft down low, sweeping under "+targ->QCN+" and knocking "+targ->QO+" down!%^RESET%^");
        tell_object(targ,"%^CYAN%^"+ETO->QCN+" twirls the massive axe quickly and sends the haft down low, sweeping under you and knocking you down!%^RESET%^");
        tell_room(EETO,"%^CYAN%^"+ETO->QCN+" twirls the massive axe quickly ands sends the haft down low, sweeping under "+targ->QCN+" and knocking "+targ->QP+" down!%^RESET%^",({targ,ETO}));
        targ->set_paralyzed(roll_dice(1,10) + 10, "%^GREEN%^You are struggling to stand up!%^RESET%^");
    }

    if(rand > 6 && rand < 10) // between 7 and 9 or 20%
    {
        tell_object(ETO,"%^RESET%^%^BOLD%^You snap the flat of one axe blade down atop "+targ->QCN+"'s head and use the force of the rebound to launch another attack!%^RESET%^");
        tell_object(targ,"%^RESET%^%^BOLD%^"+ETO->QCN+" snaps the flat of one axe blade down atop yourhead and uses the force of the rebound to launch another attack!%^RESET%^");
        tell_room(EETO,"%^RESET%^%^BOLD%^"+ETO->QCN+" snaps the flat of one axe blade down atop "+targ->QCN+"'s head and uses the force of the rebound to launch another attack!%^RESET%^",({targ,ETO}));
        if(sizeof(ETO->query_attackers())) { ETO->execute_attack(); }
    }

    if(rand == 10)
    {
        if((member_array("neck",targ->query_limbs()) != -1) && !random(10) && !targ->reflex_save(25) && !targ->query_property("no death") && !FEATS_D->usable_feat(targ,"death ward"))
        {
            tell_object(ETO,"%^RED%^You drop to one knee and snap the blade of the massive axe in a deadly upwards arc!%^RESET%^");
            tell_object(ETO,"%^BLUE%^You can see the blade sink cleanly into "+targ->QCN+"'s neck and pass through almost without resistance.%^RESET%^");
            tell_object(ETO,"%^B_RED%^"+targ->QCN+"'s head falls away and "+targ->QP+" body drops lifelessly to the ground.%^RESET%^");
            tell_object(targ,"%^RED%^"+ETO->QCN+" drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^");
            tell_object(targ,"%^BLUE%^You grimace and then open your eyes in sudden stark terror as you feel the bite of the axe entering your neck!%^RESET%^");
            tell_object(targ,"%^B_RED%^Your world thumbles and then stops as you roll to spot on the ground, just in time to see your body fall next to you!%^RESET%^");
            tell_object(targ,"%^B_BLUE%^%^BOLD%^%^BLACK%^"+ETO->QCN+" just cut off your head..  blackness overtakes you as you watch your body twitching on the ground.%^RESET%^");
            tell_room(EETO,"%^RED%^"+ETO->QCN+" drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^",({targ,ETO}));
            tell_room(EETO,"%^RED%^You can see the blade of "+ETO->QCN+"'s axe sink cleanly into "+targ->QCN+"'s neck and pass cleanly through!%^RESET%^",({targ,ETO}));
            tell_room(EETO,"%^B_RED%^"+targ->QCN+"'s head falls away and "+targ->QP+" body drops lifelessly to the ground!%^RESET%^",({targ,ETO}));
            head = new("/std/obj/body_part.c");
            head->set_limb(targ->QCN,"head");
            ETO->set_property("noMissChance",1);
            targ->set_hp(-1*roll_dice(100000,100000));
            targ->do_damage("neck",roll_dice(500000,500000));
            ETO->set_property("noMissChance",1);
            head->move(EETO);
            return 1;
        }
        tell_object(ETO,"%^RED%^You drop to one knee and snap the blade of the massive axe in a deadly upwards arc!%^RESET%^");
        tell_object(ETO,"%^BLUE%^At the last instant, "+targ->QCN+" manages to dodge out of the way, avoiding the fatal strike!%^RESET%^");
        tell_object(ETO,"%^GREEN%^The axe slices across "+targ->QCN+"'s eyes, blinding "+targ->QO+"!%^RESET%^");

        tell_object(targ,"%^RED%^"+ETO->QCN+" drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^");
        tell_object(targ,"%^BLUE%^At the last instant, you manage to dodge out of the way, avoiding the fatal strike!%^RESET%^");
        tell_object(targ,"%^GREEN%^The axe slices across your eyes, blinding you!%^RESET%^");

        tell_room(EETO,"%^RED%^"+ETO->QCN+" drops to one knee and snaps the blade of the massive axe in a deadly upwards arc!%^RESET%^",({targ,ETO}));
        tell_room(EETO,"%^BLUE%^At the last instant, "+targ->QCN+" manages to dodge out of the way, avoiding the fatal strike!%^RESET%^",({targ,ETO}));
        tell_room(EETO,"%^GREEN%^The axe slices across "+targ->QCN+"'s eyes, blinding "+targ->QO+".%^RESET%^",({targ,ETO}));

        targ->set_paralyzed(roll_dice(5,5) + 25, "%^CYAN%^You are in too much pain to do anything!%^RESET%^");
        if(!targ->will_save(40)) { targ->set_temporary_blinded(roll_dice(1,4)); }
        return 1;
    }

    return 0;
}

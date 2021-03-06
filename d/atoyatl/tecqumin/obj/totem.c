//Coded by Lujke

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("Stone totem");
    set_id( ({"totem","stone","stone totem"}) );
    set_short("Stone totem");
    set_obvious_short("Stone totem");
    set_weight(100);
    set_long("The totem is carved in the form of a feathered serpent curling" 
+ " around an up tilted spear. The carving is well executed, but at once simple"
+ " and slightly abstract. It is noticeably different to any stonework you"
+ " might recognise from the main cultures of the realms. On the back of the"
+ " totem, a meandering line leads down past a pyramid before splitting in two"
+ " around a circle. Further lines shoot up and out from the circle, in an"
+ " abstracted fountaining effect."
+"\n /n" 

+" FRONT:\n"

+"%^RESET%^                                           _/ \n"
+"%^MAGENTA%^                          ____________  %^RESET%^ _/ / \n"
+"%^MAGENTA%^                         / _\\_________\\%^ORANGE%^_%^RESET%^/  |\n"
+"%^MAGENTA%^                        /    / \\ \\ \\ \\ \\   %^ORANGE%^/%^GREEN%^___\n"
+"%^MAGENTA%^                       /    /   \\ \\%^GREEN%^_%^MAGENTA%^\\ "
+"%^GREEN%^_%^MAGENTA%^\\%^GREEN%^_%^MAGENTA%^\\%^GREEN%^_/  %^BOLD%^%^RED%^o"
+"%^RESET%^%^GREEN%^ \\%^BOLD%^%^GREEN%^__/%^RESET%^\n"
+"%^MAGENTA%^                      /    /   /\\%^RESET%^%^GREEN%^/_____________"
+"/  %^BOLD%^%^GREEN%^\\%^RESET%^\n"
+"%^MAGENTA%^                      \\___/\\__/  \\_%^ORANGE%^/    / %^GREEN%^|\n"
+"%^MAGENTA%^                    ______________%^ORANGE%^/%^GREEN%^____"
+"%^ORANGE%^/ %^GREEN%^/ \n"
+"%^MAGENTA%^                   / _\\_________\\%^GREEN%^_______/ \n"
+"%^MAGENTA%^                  /    / \\ \\ \\ \\ \\   %^ORANGE%^/%^GREEN%^ |\n"
+"%^MAGENTA%^                 /    /   \\ \\_\\_\\_\\_%^ORANGE%^/ %^GREEN%^ / \n"
+"%^MAGENTA%^                /    /   /\\%^GREEN%^/__________/ \n"
+"%^MAGENTA%^                \\___/\\__/  \\_%^ORANGE%^/    / %^GREEN%^|\n"
+"%^MAGENTA%^               _____________%^ORANGE%^/%^GREEN%^____%^ORANGE%^/"
+"%^GREEN%^  / \n"
+"%^MAGENTA%^              / _\\_________\\%^GREEN%^_______/ \n"
+"%^MAGENTA%^             /    / \\ \\ \\ \\ \\   %^ORANGE%^/%^GREEN%^ |\n"
+"%^MAGENTA%^            /    /   \\ \\%^GREEN%^_%^MAGENTA%^\\%^GREEN%^_"
+"%^MAGENTA%^\\%^GREEN%^_%^MAGENTA%^\\%^GREEN%^_%^ORANGE%^/  %^GREEN%^/ \n"
+"%^MAGENTA%^           /    /   /\\%^GREEN%^/__________/ \n"
+"%^MAGENTA%^           \\___/\\__/  \\_/ %^ORANGE%^   /%^GREEN%^ | \n"
+"%^GREEN%^                   ___%^ORANGE%^/%^GREEN%^____%^ORANGE%^/  "
+"%^GREEN%^/ \n"
+"%^GREEN%^                  /__________/ \n"
+"%^ORANGE%^                    /    / \n"
+"%^ORANGE%^                   /    / \n"
+"%^ORANGE%^                  /    / \n"
+"\n"
+"\n%^RESET%^BACK: \n"

+"%^BLUE%^                  |\n"
+"%^BLUE%^                   \\_\n"
+"%^BLUE%^                     \\__\n"
+"%^BLUE%^                         \\ \n"
+"%^BLUE%^                          |\n"
+"%^BLUE%^                         / \n"
+"%^BLUE%^                      __~\n"
+"%^BLUE%^                     / \n"
+"%^BLUE%^                __-~\n"
+"%^BLUE%^              / \n"
+"%^BLUE%^             /\\ \n"
+"%^BLUE%^            /  \\ \n"
+"%^BLUE%^          _~    ~_\n"
+"%^BLUE%^       __/        \\__\n"
+"%^BLUE%^      /  %^BOLD%^%^CYAN%^  /\\   /\\   %^RESET%^%^BLUE%^\\ \n"  
+"%^BLUE%^     /   %^BOLD%^%^CYAN%^ / ^\\ /^ \\  %^RESET%^%^BLUE%^ \\ \n"
+"%^BLUE%^    |    %^BOLD%^%^CYAN%^/ /  ^   \\\\ %^RESET%^%^BLUE%^  |\n"
+"%^BLUE%^     \\   %^ORANGE%^    / \\ %^BLUE%^     / \n"
+"%^BLUE%^      \\__%^ORANGE%^    |_| %^BLUE%^  __/ \n"
+"%^BLUE%^         \\_      _/ \n"
+"%^BLUE%^           \\    / \n"
+"%^BLUE%^            ~  ~\n"
+"%^BLUE%^             \\/ \n"
+"%^BLUE%^             / \n"
+"%^BLUE%^           -~\n"
+"%^BLUE%^        __/ \n"
+"%^BLUE%^       ~\n"
+"%^BLUE%^      / \n"
+"%^BLUE%^     |\n"
+"%^BLUE%^      \\_\n"
+"%^BLUE%^        \\__\n"
+"%^BLUE%^           \\ \n"
+"%^BLUE%^           |");
    set_lore("The priests of the %^ORANGE%^Tecqumin%^RESET%^ presided"
            +" over a cult of death and human sacrifice. The"
            +" %^RED%^blood%^RESET%^ of the souls offered up in the"
            +" '%^CYAN%^flowery death%^RESET%^', as they called it, was"
            +" supposed to go to feed the %^BOLD%^%^YELLOW%^S%^BOLD%^"
            +"%^WHITE%^u%^YELLOW%^n L%^BOLD%^%^WHITE%^o%^YELLOW%^rd"
            +" %^RESET%^and the other %^MAGENTA%^Gods%^RESET%^, to enable"
            +" them to ensure that the sun could make its journey across"
            +" the %^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^k%^BOLD%^%^CYAN%^y"
            +"%^RESET%^ each day and the other natural processes could"
            +" occur as they were supposed to. The body parts of the"
            +" sacrifices were supposed to hold some special powers."
            +" Limbs would be eaten in acts of %^RED%^ritual cannibalism"
            +" %^RESET%^and skulls or preserved heads were usually kept"
            +" as tokens or trophies. The higher the %^CYAN%^status"
            +" %^RESET%^of the victim, the more power was ascribed to his"
            +" or her remains. No story survives to explain how the"
            +" %^ORANGE%^Tecqumin%^RESET%^ came to believe these things,"
            +" nor how their once mighty civilisation ceased to exist.");
  set_property("lore",30);
}



#include <stdio.h>
#include "cards.h"

int main() {
    card_t c1 = card_from_letters('A','s'); // Ace of Spades
    card_t c2 = card_from_num(0);           // 0→2 of SPADES
    print_card(c1); printf("\n");
    print_card(c2); printf("\n");
    printf("%c %c\n", value_letter(c1), suit_letter(c1));
    return 0;
}

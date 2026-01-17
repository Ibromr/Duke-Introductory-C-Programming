#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS );
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r) {
      case STRAIGHT_FLUSH:   return "STRAIGHT_FLUSH";
      case FOUR_OF_A_KIND:   return "FOUR_OF_A_KIND";
      case FULL_HOUSE:       return "FULL_HOUSE";
      case FLUSH:            return "FLUSH";
      case STRAIGHT:         return "STRAIGHT";
      case THREE_OF_A_KIND:  return "THREE_OF_A_KIND";
      case TWO_PAIR:         return "TWO_PAIR";
      case PAIR:             return "PAIR";
      case NOTHING:          return "NOTHING";
      default:               return "UNKNOWN";
  }
}

char value_letter(card_t c) {
  if (c.value >= 2 && c.value <= 9) {
        return '0' + c.value;  // 2 → '2', 3 → '3', etc.
    }
    switch (c.value) {
        case 10: return '0';
        case 11: return 'J';
        case 12: return 'Q';
        case 13: return 'K';
        case 14: return 'A';
        default: return '?';
    }
}


char suit_letter(card_t c) {
  switch (c.suit) {
        case SPADES:   return 's';
        case HEARTS:   return 'h';
        case DIAMONDS: return 'd';
        case CLUBS:    return 'c';
        default:       return '?';
    }  
}

void print_card(card_t c) {
    printf("%c%c", value_letter(c), suit_letter(c));
}


card_t card_from_letters(char value_let, char suit_let) {
    card_t temp;

    // Value
    if (value_let >= '2' && value_let <= '9') {
        temp.value = value_let - '0'; // '2' → 2, '5' → 5
    } else {
        switch(value_let) {
            case '0': temp.value = 10; break;
            case 'J': temp.value = 11; break;
            case 'Q': temp.value = 12; break;
            case 'K': temp.value = 13; break;
            case 'A': temp.value = 14; break;
            default: 
                fprintf(stderr, "Invalid Card\n");
                exit(EXIT_FAILURE);
        }
    }

    // Suit
    switch(suit_let) {
        case 's': temp.suit = SPADES; break;
        case 'h': temp.suit = HEARTS; break;
        case 'd': temp.suit = DIAMONDS; break;
        case 'c': temp.suit = CLUBS; break;
        default:
            fprintf(stderr, "Invalid Card\n");
            exit(EXIT_FAILURE); // Security check
    }

    return temp;
}


card_t card_from_num(unsigned c) {
    card_t temp;
    temp.value = (c % 13) + 2;        // 0→2, 12→14 (A)
    temp.suit  = c / 13;              // 0-12 → SPADES, 13-25 → HEARTS, etc.
    assert_card_valid(temp);          // Security check
    return temp;
}


/**********************************************************************************
Solution for: https://leetcode.com/problems/valid-number/
Simple state machine implementation of a Problem #65 -- Valid Number.
O(n) solution time. Loops through the string once, compares the current char
with the previous and uses states to determine whether it's valid or not.
**********************************************************************************/

#define INITIAL         0   // initial
#define NUMBER          1   // number (0-9)
#define PERIOD          2   // .
#define EXPONENT        3   // e or E
#define SIGN            4   // - or +

bool isNumber(char * s){
    // if we were crazy tight on memory, we could turn all the states values into a single
    // unsigned char and do some annoying bitwise math, but that's just extra
    unsigned int got_sign = 0, got_exp = 0, got_dec = 0, got_num = 0;
    unsigned int last_part = INITIAL;
    unsigned int iii = 0;
    while(1){
        if(s[iii] >= '0' && s[iii] <= '9'){ // regular number
            last_part = NUMBER; // there's no cases where this fails, so we just keep going
            got_num = 1;
        }
        else if(s[iii] == '.'){ // period
            if(got_exp || got_dec || (last_part == INITIAL && s[iii+1] == 0)){
                return false;
            }
            got_dec = 1;
            last_part = PERIOD;
        }
        else if(s[iii] == 'E' || s[iii] == 'e'){ // exponent
            if(last_part == SIGN || last_part == INITIAL || got_exp || !got_num){
                return false;
            }
            got_exp = 1;
            got_sign = 0;   // we do this so that cases like +6e-4 don't fail; IE: signs after exponents work
            last_part = EXPONENT;
        }
        else if(s[iii] == '+' || s[iii] == '-'){ // SIGN
            if(last_part == PERIOD || last_part == NUMBER || got_sign){
                return false;
            }
            got_sign = 1;
            last_part = SIGN;
        }
        else if(s[iii] == 0){   // NULL TERMINATOR
            if(last_part == NUMBER || (last_part == PERIOD && got_num)){
                return true;
            }
            return false;
        } else { // anything we don't expect; doesn't matter what
            return false;
        }
        iii++;
    } return false;
}

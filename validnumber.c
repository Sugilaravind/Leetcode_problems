#include <stdbool.h>
#include <string.h>

bool isNumber(char* s) {
    bool seenDigit = false;
    bool seenDot = false;
    bool seenExponent = false;

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            seenDigit = true;
        } 
        else if (c == '+' || c == '-') {
            // Signs can only appear at index 0 or immediately after an 'e' or 'E'
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
        } 
        else if (c == '.') {
            // A dot cannot appear after an exponent or if another dot is already seen
            if (seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } 
        else if (c == 'e' || c == 'E') {
            // Exponents cannot appear twice or before any digit has been recorded
            if (seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false; // Reset to ensure an integer follows the exponent
        } 
        else {
            // Any other character (like alphabets or special characters) is invalid
            return false;
        }
    }

    return seenDigit;
}

#include "twelve_days.h"

#include <map>
#include <vector>

namespace twelve_days {

std::map<int, std::vector<std::string>> int_to_string {
    {1, {"first", "a Partridge in a Pear Tree"}},
    {2, {"second", "two Turtle Doves"}},
    {3, {"third", "three French Hens"}},
    {4, {"fourth", "four Calling Birds"}},
    {5, {"fifth", "five Gold Rings"}},
    {6, {"sixth", "six Geese-a-Laying"}},
    {7, {"seventh", "seven Swans-a-Swimming"}},
    {8, {"eighth", "eight Maids-a-Milking"}},
    {9, {"ninth", "nine Ladies Dancing"}},
    {10, {"tenth", "ten Lords-a-Leaping"}},
    {11, {"eleventh", "eleven Pipers Piping"}},
    {12, {"twelfth", "twelve Drummers Drumming"}}
};
    
std::string recite(const int verse_1, const int verse_2) {
    std::string song{};
    for (int i = verse_1; i <= verse_2; ++i) {
        auto verse = int_to_string[i];
        auto stanza = "On the " + verse[0] + " day of Christmas my true love gave to me: ";
        for (int j = i; j >= 1; --j) {
            verse = int_to_string[j];
            if (j>1 || j==i) {
                stanza += (j==i) ? verse[1] : ", " + verse[1];
            } else {
                stanza += ", and " + verse[1];
            }
        }
        song += stanza + ".\n";
        song += (i == verse_2) ? "" : "\n";
    }
    return song;
}
    
}  // namespace twelve_days

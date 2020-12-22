#pragma once
#include <string>
/*this function calulates the levenshtein distance (editor distance), in modified version:
/*according to task cases, no replacements are allowed, also, 2 insertions or deletions per row are impermissive
/*Function gets 2 strings as parametres, counts, how many insertions or deletions are required to convert 1 string to another.
/*According to the task cases, if lengths of strings differ for 2 and more symbols, function return 3 (not fit case for edition the word)*/
int calculate_lev_dist_mod(const std::string& s1, const std::string& s2);
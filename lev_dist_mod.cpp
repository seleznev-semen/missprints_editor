#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
//function counts the levenshtein distance (editor distance), modified: 
//no replaces are allowed, also returns value 3 (not fit by task cases)
//if to perform the edition, two or more inserts or deletes (one after another) are required
int calculate_lev_dist_mod(const std::string& s1, const std::string& s2)      
{
    if (s1.size() < s2.size())
        return calculate_lev_dist_mod(s2, s1);
    int M = s1.size() + 1;
    int N = s2.size() + 1;
    if (M - N >= 2)         //if one word is bigger than other for 2 or more letters, 2 inserts (or delete actions) will be needed,
        return 3;           // which is impermissive according to a task cases. Returns 3 wich is more than 2 edits, permissible by case
    int ins_cost = 1, del_cost = 1; 
    std::vector< std::vector<int> > L(N, std::vector<int> (M));
    L[0][0] = 0;
    for (int j = 1; j < M; ++j) 
    {
        L[0][j] = L[0][j - 1] + ins_cost;
    }
    for (int i = 1; i < N; ++i)
    {
        L[i][0] = L[i - 1][0] + del_cost;
        for (int j = 1; j < M; ++j)
        {
            if (s1[j - 1] == s2[i - 1])
            {
                L[i][j] = L[i - 1][j - 1];
            }
            else 
            {
                L[i][j] = std::min(L[i - 1][j] + del_cost, L[i][j - 1] + ins_cost); 
            }
        }
    }

    //for (int i = 0; i < N; ++i)       //for debug
    //{
    //    for (int j = 0; j < M; ++j)
    //    {
    //        std::cout << L[i][j] << ' ';
    //    }
    //    std::cout << std::endl;
    //} 

    return L[N - 1][M - 1];
}
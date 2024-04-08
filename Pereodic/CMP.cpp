#include"CMP.h"

void computeLPS(std::string pat, int* lps)
{
    using namespace std;
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
std::vector<int> KMPSearch(const std::string& pat, const std::string& txt)
{
    using namespace std;
    vector<int> find;
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);

    int i = 0;
    int j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) {
            // cout << "Found pattern at index" << i - j << endl; // Отладочная для меня дурака
            find.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return find;
}
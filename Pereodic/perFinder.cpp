#include "perFinder.h"

std::string pt_gen(const std::string& txt, int l, int r) { // генератор строки - лень каждый раз ту страшную штуку писать.
    return std::string(txt.begin() + l, txt.begin() + r);
} // не пригодилось кстати! оптимизировал выходит?

int find_pereodic(std::string& txt) {
    std::string now_pat; // текущий паттерн
    now_pat.append(1, txt.at(0)); // костыль! но я не вспомнил как дёрнуть первый символ без итератора

    for (int i = 1; i < (txt.size() / 2); ++i) {
        now_pat.append(1, txt.at(i)); // причина по которой pt_gen не пригодилась.

        size_t now_size = KMPSearch(now_pat, txt).size(); // дёргаем размерность массива с подстроками.
        //проверяем - совпадает ли колличество 
        if (!(txt.size() % now_size) && (txt.size() / now_pat.size()) == now_size) {
            return txt.size() / now_size;
        }
    }
    return 0;
}

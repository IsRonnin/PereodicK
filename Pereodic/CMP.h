#pragma once
#include<string>
#include<iostream>
#include<vector>

// ну это стащено из 12.5 - по факту единственное отличие - 
// KMPSearch теперь возвращает вектор со всеми подходящими под pattern индексами.


void computeLPS(std::string pat, int* lps); 
std::vector<int> KMPSearch(const std::string& pat, const std::string& txt);
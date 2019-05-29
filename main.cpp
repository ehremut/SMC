#include <iostream>
#include <fstream>
#include <iomanip>
#include "Scaner.h"
#include <time.h>

int main() {
    std::ofstream fout;
    std::ifstream fin;
    fout.open("t_res.txt");
    fin.open("tests.txt");
    if(!(fin.is_open() && fout.is_open())){
        std::cout<<"Errore of opening files";
        return 0;
    }
    Scaner scaner;
    std::string conflict;
    std::string str;
    clock_t TIME;
    clock_t a,b;
    while(std::getline(fin, str)) {
        a = clock();
        conflict = scaner.scan_str(str);
        if(conflict != "incorrect") {
            fout << "Correct|Conflict: "<<conflict<<"\n";
        } else {
            fout << "Incorrect.\n";
        }
    b = clock();
    TIME += b-a;
    }
    std::cout<<"TIME = "<<TIME<<std::endl;
    std::cout << "That's all, buy!" << std::endl;
    return 0;
}

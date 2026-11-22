#include <iostream>
#include "SyntaxHighlighting.h"
#include <string>

int main(){

    initColors();
    
    std::string line = "for(int i = 0; i < 50; i++){}";


    std::cout << highlightLine(line);


}

#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

namespace Syntax{
    inline std::unordered_map<std::string, const char*> colors;
    inline char alphabet[42] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'Z'
    };
}


namespace Color{
    
    inline const char* Reset = "\033[0m";

    //TEXT
    inline const char* Black   = "\033[30m";
    inline const char* Red     = "\033[31m";
    inline const char* Green   = "\033[32m";
    inline const char* Yellow  = "\033[33m";
    inline const char* Blue    = "\033[34m";
    inline const char* Purple = "\033[35m";
    inline const char* Cyan    = "\033[36m";
    inline const char* White   = "\033[37m";
    inline const char* Default = "\033[39m";

    //BRIGHT
    inline const char* BrightBlack   = "\033[90m";
    inline const char* BrightRed     = "\033[91m";
    inline const char* BrightGreen   = "\033[92m";
    inline const char* BrightYellow  = "\033[93m";
    inline const char* BrightBlue    = "\033[94m";
    inline const char* BrightPurple = "\033[95m";
    inline const char* BrightCyan    = "\033[96m";
    inline const char* BrightWhite   = "\033[97m";
}

inline void add(std::initializer_list<const char*> words, const char* color) {
    for (auto w : words) Syntax::colors[w] = color;
}

inline void initColors(){

    add({"(", ")", "[", "]"}, Color::BrightBlue);

    add({"{", "}"}, Color::BrightPurple);

    add({"1","2","3","4","5","6","7","8","9","0"}, Color::BrightGreen);

    add({"for", "while", "do", "if", "else", "switch", "case", "default",
         "break", "continue", "return", "goto", "try", "catch", "throw"}, Color::Purple);

    add({"int", "float", "char", "bool", "void", "double", "auto", "size_t",
         "long", "short", "signed", "unsigned", "string", "vector",
         "uint8_t", "uint16_t", "uint32_t", "uint64_t",
         "int8_t", "int16_t", "int32_t", "int64_t"}, Color::Blue); 

    add({"true", "false", "nullptr", "NULL"}, Color::Yellow);

    add({"const", "constexpr", "static", "inline", "extern", "volatile",
         "mutable", "virtual", "override", "final", "explicit"}, Color::Cyan);

    add({"class", "struct", "enum", "union", "namespace", "template",
         "typename", "using", "typedef", "public", "private", "protected",
         "this", "new", "delete", "operator", "friend"}, Color::Green);
}


inline void colors(){
    


}

inline std::vector<std::string> split(std::string const line){
    std::vector<std::string> words;
    std::string word;
    bool find = false;

    for(int i = 0; i < line.size(); i++){
        find = false;
        for(int j = 0; j < 42; j++){
            if(line[i] == Syntax::alphabet[j]){
                word += line[i];
                find = true;
            }
        }
        if(!find){
            words.push_back(word);
            words.push_back(std::string(1, line[i]));
            word.erase();
        }
        
        
    }

    return words;

}

inline std::string highlightLine(std::string line){
    std::string coloredLine;
    std::vector<std::string> word = split(line);
    bool contain = false;
    for(int i = 0; i < word.size(); i++){
        if(Syntax::colors.contains(word[i])) contain = true;
        else contain = false;

        if(contain) coloredLine += Syntax::colors.at(word[i]);
        
        coloredLine += word[i];

        if(contain) coloredLine += "\033[0m";
        
    }

    return coloredLine;


}
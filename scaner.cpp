#include <iostream>
#include "Scaner.h"

void Scaner::reset_all(){
    word_length = 0;
    number = 0;
    commaNumber = 0;
    buffer = "";
    conflict = "";
    isRightString = 0;
}


void Scaner::len_and_buf_reset(){
    word_length = 0;
    buffer = "";
}


bool Scaner::chk_is_type(){
    return (this->buffer == "int" || this->buffer == "short" || this->buffer == "long");
}

bool Scaner::chk_is_name(){
    if(((this->buffer[1] > 64 && this->buffer[1] < 91) || (this->buffer[1] > 97 && this->buffer[1] < 123)) &&
          this->buffer[0] ==' ')
        return 1;
    else
        return 0;
}


void Scaner::getConflict(){
    std::string name = this->buffer;
    name.erase(0,1);
    this->conflict = "none";
    if(name == "int" ){
        this->conflict = "int";
        used_names.push_back(name);
        return;
    }
    if(name == "short" ){
        this->conflict = "short";
        used_names.push_back(name);
        return;
    }
    if(name == "long" ){
        this->conflict = "long";
        used_names.push_back(name);
        return;
    }
    if(find_name(name) == 1)
    {
        this->conflict = name;
        used_names.push_back(name);
        return;
    }
    used_names.push_back(name);
}


void Scaner::getNumber(){
    std::string num = this->buffer;
    num.erase(0,1);
    int mul = 1;
    for(int i = word_length-2; i>=0; i--)
    {

        number = number + (num[i]-48)*mul;
        mul *= 10;
    }
}


bool Scaner::chk_is_list(){
    if(this->buffer[1] != '=')
        return 0;
    if(this->buffer[2] != '{')
        return 0;
    if(this->buffer[word_length-1] != '}')
        return 0;
    if( commaNumber != number - 1)
        return 0;
    return 1;
}


bool Scaner::find_name(std::string name){
    for(int i = used_names.size() - 1; i>=0; i--)
    {
        if(used_names[i] == name)
            return 1;
    }
    return 0;
}


bool Scaner::chk_minus(){
    if(buffer[word_length-1] == ',' || buffer[word_length-1] == '{')
        return 1;
    else
        return 0;
}

bool Scaner::chk_comma(){
    if(buffer[word_length-1]>='0' && buffer[word_length-1]<='9')
        return 1;
    else
        return 0;
}



std::string Scaner::scan_str(std::string &scanning_stroke){
    const char *str = scanning_stroke.c_str();
    _fsm.enterStartState();
    _fsm.RESET();
    while (*str != '\0'){
            switch (*str){
            case ' ':
                _fsm.space(*str);
                break;
            case '=':
                _fsm.equal(*str);
                break;
            case '[':
                    _fsm. open_scobe(*str);
                    break;
            case ']':
                    _fsm. close_scobe(*str);
                    break;
            case '{':
                    _fsm.open_bracket(*str);
                    break;
            case '}':
                    _fsm.close_bracket(*str);
                    break;
            case ',':
                    _fsm.comma(*str);
                    break;
            case '-':
                    _fsm.minus(*str);
                    break;
            default:{
                if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')){
                    _fsm.letter(*str);
                    break;
                }
                if(*str >= '0' && *str <= '9') {
                    _fsm.digit(*str);
                    break;
                }
                _fsm.unknown();
            }

        }
            str++;
    }
    _fsm.EOS();
    if(isRightString == 1)
        return this->conflict;
    else
        return "incorrect";
}

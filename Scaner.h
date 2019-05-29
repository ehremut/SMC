#ifndef SCANER_H
#define SCANER_H

#include <string>
#include "Scaner_sm.h"
#include <vector>


class Scaner{
private:
   int word_length;
   int number;
   int commaNumber;
   std::string conflict;
   std::vector<std::string> used_names;
   bool isRightString;
   ScanerContext _fsm;
public:
   Scaner():_fsm(*this){}

   ~Scaner(){}

   inline void Right(){
          isRightString=1;
   }

   inline bool chk_len(){
           return word_length < 17;
   }

   inline bool chk_count_len(){
           return word_length < 10;
   }

   inline void inc_len(){
           word_length++;
   }

   inline void inc_CommaNumber(){
          commaNumber++;
   }

   void len_and_buf_reset();

   void reset_all();

   bool chk_is_type();

   bool chk_is_name();

   void getConflict();

   void getNumber();

   bool chk_comma();

   bool chk_minus();

   bool chk_is_list();

   bool find_name(std::string name);

   std::string scan_str(std::string &scanning_stroke);

   std::string buffer;
 };




#endif // SCANER_H

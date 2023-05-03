/* ------------------------------------------------------
Workshop 6 part 1
Name: Juan Pablo Martinez Carett
Module: Train
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:4/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
      bool validID(const char* name,long long number, const char vCode[], const char sNumber[]) const; // ok
      void setEmpty();// do this // ok
      void allocateAndCopy(const char* name);// ok
      void extractChar(std::istream& istr, char ch) const; // ok    
     
   public:
       std::ostream& printIDInfo(std::ostream& ostr)const;// ok
       operator bool() const;
       void set(const char* name, long long number, const char vCode[], const char sNumber[]);// ok but with change

       HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});//ok
       
       HealthCard(const HealthCard& hc);// ok but with changes 
       
       HealthCard& operator=(const HealthCard& hc);// ok
       
       std::ostream& print(std::ostream& ostr, bool toFile = true) const;//  PRINT FALTA ALGO
       
       std::istream& read(std::istream& istr);
       
       ~HealthCard();
       
       friend std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
       friend std::istream& operator>>(std::istream& istr, HealthCard& hc);
   };
   

}
#endif // !SDDS_HealthCard_H



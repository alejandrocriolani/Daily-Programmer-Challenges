#include <iostream>
using std::cout;
using std::endl;

#include "President.hpp"
//Constructors

President::President()
{
  is_dead = true;
}

President::President(string name, string birth_date, string birth_place, string death_date, string death_location)
{
  //cout << name << " " << birth_date << " " << birth_place << " " << death_date << " " << death_location << endl;
  is_dead = true;
  full_name = name;
  place_of_birth = birth_place;
  date_of_birth = StringToFecha(birth_date);

  if(death_date.length() < 2)
    is_dead = false;
  if(is_dead == true)
    date_of_death = StringToFecha(death_date);
  location_of_death = death_location;
}

//Public functions member
int President::GetYearOfBirth(void) const
{
  return date_of_birth.GetAnio();
}

int President::GetYearOfDeath(void) const
{
  return date_of_death.GetAnio();
}

bool President::IsDead(void) const
{
  return is_dead;
}

void President::Print(void) const
{
  cout << "********************************************************************" << endl;
  cout << "Nombre: " << full_name << endl;
  cout << "Fecha de nacimiento: ";
  date_of_birth.Imprimir();
  cout << endl;
  cout << "Lugar de nacimiento: " << place_of_birth << endl;
  if(is_dead)
  {
    cout << "Fecha de fallecimiento: ";
    date_of_death.Imprimir();
    cout << endl;
    cout << "Lugar de fallecimiento: " << location_of_death << endl;
  }
}

//Private functions member
Fecha President::StringToFecha(string date)
{
  if(date.length() > 9)
  {
    //cout << date.length() << "  -> " << date << endl;

    string s_month = date.substr(0, 3);
    string s_day = date.substr(4, 2);
    string s_year = date.substr(7, 4);

    int day, month, year;

    year = stoi(s_year);
    day = stoi(s_day);

    if(s_month == "Jan")
      month = 1;
    else if(s_month == "Feb")
      month = 2;
    else if(s_month == "Mar")
      month = 3;
    else if(s_month == "Apr")
      month = 4;
    else if(s_month == "May")
      month = 5;
    else if(s_month == "Jun")
      month = 6;
    else if(s_month == "Jul")
      month = 7;
    else if(s_month == "Aug")
      month = 8;
    else if(s_month == "Sep")
      month = 9;
    else if(s_month == "Oct")
      month = 10;
    else if(s_month == "Nov")
      month = 11;
    else if(s_month == "Dec")
      month = 12;
    else
      month = 1;

    Fecha fecha(day, month, year);
    return fecha;
  }

  Fecha fecha;
  return fecha;
  }

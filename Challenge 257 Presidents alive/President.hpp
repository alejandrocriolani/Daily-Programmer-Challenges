#ifndef PRESIDENTS_HPP
#define PRESIDENTS_HPP

#include <string>
using std::string;
using std::stoi;

#include "Fecha.hpp"

class President
{
public:
  President(void);
  President(string name, string birth_date, string birth_place, string death_date, string death_location);
  void Print(void) const;
  void SetFullName(string name);
  void SetDateOfBirth(string birth_date);
  void SetDateOfBirth(Fecha birth_date);
  void SetDateOfDeath(string death_date);
  void SetDateOfDeath(Fecha death_date);
  void SetLocationDeath(string death_location);
  int GetYearOfBirth(void) const;
  int GetYearOfDeath(void) const;
  bool IsDead(void) const;

private:
  Fecha StringToFecha(string date);

  string full_name;
  string location_of_death;
  string place_of_birth;
  Fecha date_of_birth;
  Fecha date_of_death;
  bool is_dead;
};

#endif

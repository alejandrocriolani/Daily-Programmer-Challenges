#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ios;
using std::getline;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <list>
using std::list;

#include "President.hpp"

list<President> get_presidents(void);
list<int> calculate_years(list<President>);

list<President> get_presidents(void)
{
  ifstream file;
  list<President> list_pres;

  file.open("presidents.csv", ios::in);
  if(!file.is_open())
  {
    cerr << "No se pudo abrir el archivo correctamente" << endl;
    return list_pres;
  }

  string name, date_of_birth, place_of_birth, date_of_death, location_of_death;
  int i = 0; //this aux value if for not to save the headers of .cvs

  while(!file.eof())
  {
    getline(file, name, ',');
    getline(file, date_of_birth, ',');
    getline(file, place_of_birth, ',');
    getline(file, date_of_death, ',');
    getline(file, location_of_death);

    //cout << name << " " << date_of_birth << " " << place_of_birth << " " << date_of_death << " " << location_of_death << endl;

    if( i > 0)
    {
      list_pres.push_back(President(name, date_of_birth, place_of_birth, date_of_death, location_of_death));
    }
    i++;
  }
  list_pres.pop_back();

  return list_pres;
}

list<int> calculate_years(list<President> list_pres)
{
  int current_year = 2016;
  int min_year = current_year;

  for( President pres : list_pres)
  {
    if(pres.GetYearOfBirth() < min_year)
      min_year = pres.GetYearOfBirth();
  }

  int len_array_years = current_year - min_year + 1;
  int array_int[len_array_years] = {0};

  for(President pres : list_pres)
  {
    for(int i = min_year; i <= current_year; i++)
    {
      if(i >= pres.GetYearOfBirth() )
      {
        if(pres.IsDead())
        {
          if( i <= pres.GetYearOfDeath())
            ++array_int[i-min_year];
        }
        else
        {
          ++array_int[i-min_year];
        }

      }
      if(i > pres.GetYearOfDeath())
        break;
    }
  }

  int max_president_alives = 0;

  for(int i = 0; i < len_array_years; i++)
  {
    if(max_president_alives < array_int[i])
      max_president_alives = array_int[i];
  }

  list<int> list_int;

  for(int i = 0; i < len_array_years; i++)
  {
    if(array_int[i] == max_president_alives)
      list_int.push_back(i + min_year);
  }

  return list_int;
}

int main(void)
{
  list<President> list_pres;
  list<int> list_years;
  list_pres = get_presidents();
  list_years = calculate_years(list_pres);
  for(int i : list_years)
  {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}

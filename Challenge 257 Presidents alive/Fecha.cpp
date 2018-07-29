#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

#include "Fecha.hpp"


Fecha::Fecha(int d, int m, int y)
{
  Asignar_anio(y);
  Asignar_mes(m);
  Asignar_dia(d);
}

Fecha::~Fecha()
{

}

void Fecha::Imprimir() const
{
  cout << setfill('0') << setw(2) << dia << '/' << setw(2) << mes << '/' << anio << setfill(' ');
}

void Fecha::Next_day()
{
  dia++;
  if(dia > 31 && (mes == ENERO || mes == MARZO || mes == MAYO || mes == JULIO || mes == AGOSTO || mes == OCTUBRE || mes == DICIEMBRE))
  {
    dia = 1;
    if(mes != DICIEMBRE)
      mes++;
    else
    {
      mes = ENERO;
      anio++;
    }
    return;
  }
  if(dia > 30 && (mes == ABRIL || mes == JUNIO || mes == SEPTIEMBRE || mes == NOVIEMBRE))
  {
    mes++;
    dia = 1;
    return;
  }
  if(dia > 28 && mes == FEBRERO && !EsBisiesto(anio))
  {
    dia = 1;
    mes++;
  }
  if(dia > 29 && mes == FEBRERO && EsBisiesto(anio))
  {
    dia = 1;
    mes++;
  }
}

int Fecha::GetDia() const
{
    return dia;
}

int Fecha::GetMes() const
{
    return mes;
}

int Fecha::GetAnio() const
{
    return anio;
}

int Fecha::GetDiferenciaDias(const Fecha & fechaAnterior) const
{
    if(&fechaAnterior == this)
        return 0;
    if(fechaAnterior.anio == anio && fechaAnterior.mes == mes)
        return DifDiaMismoMesYAnio(dia, fechaAnterior.dia);
    if (fechaAnterior.anio == anio && ! (fechaAnterior.mes == mes))
        return DifDiaMismoAnio(fechaAnterior);
    if(fechaAnterior.anio != anio)
        return DifDiaDisMesYAnio(fechaAnterior);
    return 0;

}

int Fecha::GetDiferenciaAnios( Fecha & fecha2) const
{
    return anio - fecha2.GetAnio();
}

int Fecha::DifDiaMismoMesYAnio(int dia1, int dia2) const
{
        return dia1 - dia2;
}

int Fecha::DifDiaMismoAnio(const Fecha &fecha1) const
{
    int mesMenor, mesMayor, diaMesMenor, diaMesMayor;
    int cantDias = 0;
    bool fecha1EsMenor = true;

    if(mes < fecha1.mes)
    {
        fecha1EsMenor = false;
        mesMenor = mes;
        diaMesMenor = dia;
        mesMayor = fecha1.mes;
        diaMesMayor = fecha1.dia;
    }
    else
    {
        mesMenor = fecha1.mes;
        diaMesMenor = fecha1.dia;
        mesMayor = mes;
        diaMesMayor = dia;
    }

    for(int i = mesMenor ; i <= mesMayor; i++ )
    {
        switch (i)
        {
        case ENERO:
        case MARZO:
        case MAYO:
        case JULIO:
        case AGOSTO:
        case OCTUBRE:
        case DICIEMBRE:
            if(mesMenor == i)
            {
                cantDias += (31 - diaMesMenor + 1);
            }
            else if (mesMayor == i)
            {
                cantDias += diaMesMayor - 1;
            }
            else
            {
                cantDias += 31;
            }
            break;
        case ABRIL:
        case JUNIO:
        case SEPTIEMBRE:
        case NOVIEMBRE:
            if(mesMenor == i)
            {
                cantDias += (30 - diaMesMenor + 1);
            }
            else if (mesMayor == i)
            {
                cantDias += diaMesMayor - 1;
            }
            else
            {
                cantDias += 30;
            }
            break;
        case FEBRERO:
            if(EsBisiesto(this->anio))
            {
                if(mesMenor == i)
                {
                    cantDias += (29 - diaMesMenor + 1);
                }
                else if (mesMayor == i)
                {
                    cantDias += diaMesMayor - 1;
                }
                else
                {
                    cantDias += 29;
                }
            }
            else
            {
                if(mesMenor == i)
                {
                    cantDias += (28 - diaMesMenor + 1);
                }
                else if (mesMayor == i)
                {
                    cantDias += diaMesMayor - 1;
                }
                else
                {
                    cantDias += 28;
                }
            }
            break;
        default:
            break;
        }
    }
    if(fecha1EsMenor)
      return cantDias;
    else
      return -cantDias;
}

int Fecha::DifDiaDisMesYAnio(const Fecha &fecha1) const
{

  int anioMenor, anioMayor;
  int cantDias = 0;
  bool fecha1EsMenor = true;

  if(anio < fecha1.anio)
  {
    fecha1EsMenor = false;
    anioMenor = anio;
    anioMayor = fecha1.anio;
  }
  else
  {
    anioMenor = fecha1.anio;
    anioMayor = anio;
  }

  Fecha aux = *this;
  Fecha auxMenor(1,1,anioMenor);
  Fecha auxMayor(31,12, anioMayor);

  for(int i = anioMenor; i <= anioMayor; i++)
  {
    if(EsBisiesto(i))
      cantDias += 366;
    else
      cantDias += 365;
  }

  if(fecha1EsMenor)
  {
    cantDias -= fecha1.GetDiferenciaDias(auxMenor);
    cantDias -= auxMayor.GetDiferenciaDias(aux);
    cantDias--;
  }
  else
  {
    cantDias -= aux.GetDiferenciaDias(auxMenor);
    cantDias -= auxMayor.GetDiferenciaDias(fecha1);
    cantDias--;
  }

  aux.~Fecha();
  auxMayor.~Fecha();
  auxMenor.~Fecha();

  if(fecha1EsMenor == false)
    return -cantDias;
  return cantDias;
}

void Fecha::Asignar_anio(int y)
{
  if(y > 0)
    anio = y;
  else
    anio = 1;
}

void Fecha::Asignar_mes(int m)
{
  if( m > 0 && m < 13)
    mes = m;
  else
    mes = 1;
}

void Fecha::Asignar_dia(int d)
{
  if( d > 0 && d < 32)
  {
    if((mes == ENERO || mes == MARZO || mes == MAYO || mes == JULIO || mes == AGOSTO || mes == OCTUBRE || mes == DICIEMBRE))
    {
      dia = d;
      return;
    }
    if(mes == FEBRERO && d < 30)
    {
      if( EsBisiesto(anio) && d == 29)
      {
        dia = d;
        return;
      }
      if( d < 29 )
      {
        dia = d;
        return;
      }
      else
        dia = 1;
      return;
    }
    if((mes == ABRIL || mes == JUNIO || mes == SEPTIEMBRE || mes == NOVIEMBRE) && d <= 30)
    {
      dia = d;
      return;
    }
    else
    {
      dia = 1;
      return;
    }
  }
  dia = 1;
}

bool Fecha::EsBisiesto(const int y) const
{
  if( ( y % 400 == 0) || ((y % 4 == 0) && !(y % 100 == 0)) )
    return true;
  return false;
}

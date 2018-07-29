#ifndef FECHA_HPP
#define FECHA_HPP

typedef enum {ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE} MES;

class Fecha
{
public:
  Fecha(int = 1, int = 1, int = 2000);
  ~Fecha();
  void Imprimir() const;
  void Next_day();
  int GetDia() const;
  int GetMes() const;
  int GetAnio() const;
  int GetDiferenciaDias(const Fecha &) const;
  int GetDiferenciaAnios(Fecha &) const;
private:
  int DifDiaMismoMesYAnio(int, int) const;
  int DifDiaMismoAnio(const Fecha &) const;
  int DifDiaDisMesYAnio(const Fecha &) const;
  void Asignar_dia(int);
  void Asignar_mes(int);
  void Asignar_anio(int);
  bool EsBisiesto(const int) const;

  int dia;
  int mes;
  int anio;
};

#endif

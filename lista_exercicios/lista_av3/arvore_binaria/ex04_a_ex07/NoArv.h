#ifndef NOARV_H_INCLUDED
#define NOARV_H_INCLUDED

class NoArv
{
public:
  NoArv(){};
  ~NoArv(){};
  void setEsq(NoArv *p) { esq = p; };
  void setInfo(int val) { info = val; };
  void setAltura(int alt) { altura = alt; };
  void setDir(NoArv *p) { dir = p; };
  NoArv *getEsq() { return esq; };
  int getInfo() { return info; };
  int getAltura() { return altura; };
  NoArv *getDir() { return dir; };

private:
  NoArv *esq; // ponteiro para o filho a esquerda
  int info;   // informa��o do No (int)
  int altura; // armazena altura do n ́o da AB
  NoArv *dir; // ponteiro para o filho a direita
};

#endif // NOARV_H_INCLUDED

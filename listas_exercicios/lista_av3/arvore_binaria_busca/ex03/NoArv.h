#ifndef NOARV_H_INCLUDED
#define NOARV_H_INCLUDED

#include <string>
using namespace std;

class NoArv
{
public:
  NoArv(){};
  ~NoArv(){};
  void setEsq(NoArv *p) { esq = p; };
  void setDir(NoArv *p) { dir = p; };
  void setMatricula(int val) { matricula = val; };
  void setNome(string val) { nome = val; };
  void setDisciplina(string val) { disciplina = val; };
  void setTurma(string val) { turma = val; };
  void setMedia(float val) { media = val; };
  NoArv *getEsq() { return esq; };
  NoArv *getDir() { return dir; };
  int getMatricula() { return matricula; };
  string getNome() { return nome; };
  string getDisciplina() { return disciplina; };
  string getTurma() { return turma; };
  float getMedia() { return media; };

private:
  NoArv *esq; // ponteiro para o filho a esquerda
  NoArv *dir; // ponteiro para o filho a direita
  int matricula;
  string nome;
  string disciplina;
  string turma;
  float media;
};

#endif // NOARV_H_INCLUDED

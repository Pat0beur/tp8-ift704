#include <set>
#include "cum_mediane.h"

int cum_mediane(const double* données_ptr, const int taille, double* sortie_ptr){
  std::set<double> données;
  std::set<double>::iterator Méd = données.end();
  int N = 0;
  for(int i=0; i<taille; i++){
    auto résultat = données.insert(données_ptr[i]);
    if(!résultat.second) return ERROR_DONNÉES_RÉPÉTÉES;
    N++;
    if(N==1){
      Méd = résultat.first;
    }else if(N%2==0 && données_ptr[i] < *Méd){
      Méd--;
    }else if(N%2==1 && données_ptr[i] > *Méd){
      Méd++;
    }
    if(N%2==1){
      sortie_ptr[i] = *Méd;
    }else{
      std::set<double>::iterator Méd_droit = Méd;
      Méd_droit++;
      sortie_ptr[i] = (*Méd + *Méd_droit)/2.0;
    }
  }
  return SUCCESS;
}

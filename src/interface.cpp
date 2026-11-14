#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "cum_mediane.h"

namespace py = pybind11;

py::array_t<double> cum_mediane_interface(py::array_t<double> données){
  py::buffer_info buf = données.request();
  if(buf.ndim != 1) throw std::runtime_error("Le tableau doit être à 1 dimension");
  const double* données_ptr = static_cast<const double*>(buf.ptr);
  const int taille = (int)buf.shape[0];
  auto sortie = py::array_t<double>(taille);
  py::buffer_info buf2 = sortie.request();
  double* sortie_ptr = static_cast<double*>(buf2.ptr);
  int status = cum_mediane(données_ptr, taille, sortie_ptr);
  if(status == ERROR_DONNÉES_RÉPÉTÉES)
    throw std::runtime_error("Données répétées");
  return sortie;
}

PYBIND11_MODULE(cum_mediane, m){
  m.doc() = "Médiane cumulative d'une série de nombres.\n\n"
            "Module écrit en C++ et exposé en Python via pybind11.\n"
            "Calcule la médiane cumulative de chaque préfixe du tableau "
            "d'entrée en temps O(n log n) à l'aide d'un ensemble trié.";

  m.def("cum_mediane", &cum_mediane_interface,
        py::arg("données"),
        "Calcule la médiane cumulative de chaque préfixe du tableau de "
        "doubles passé en entrée.\n\n"
        "Parameters\n"
        "----------\n"
        "données : numpy.ndarray de doubles à 1 dimension\n"
        "    Série de nombres dont on veut la médiane cumulative.\n\n"
        "Returns\n"
        "-------\n"
        "numpy.ndarray\n"
        "    Tableau de mêmes dimensions, dont l'élément i est la médiane "
        "cumulative de données[0..i].\n\n"
        "Raises\n"
        "------\n"
        "RuntimeError\n"
        "    Si le tableau contient des valeurs répétées.\n"
        "RuntimeError\n"
        "    Si le tableau n'est pas à 1 dimension.");
}

cum_mediane Documentation
=========================

Le module ``cum_mediane`` calcule les médianes cumulées d'une série de
nombres. Il est écrit en C++ et exposé en Python via pybind11.

.. toctree::
   :maxdepth: 2
   :caption: Contenu

   cum_mediane


Installation et usage
---------------------

.. code-block:: python

   import numpy as np
   import cum_mediane

   données = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
   cum_mediane.cum_mediane(données)

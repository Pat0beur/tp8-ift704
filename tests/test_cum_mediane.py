import numpy as np
import pytest
import cum_mediane

def test_données_répétées():
    with pytest.raises(RuntimeError):
        cum_mediane.cum_mediane(np.array([1.0, 2.0, 2.0, 3.0]))

def test_exemple_diapo():
    données = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
    attendu = np.array([2.0, 2.5, 2.0, 1.5, 2.0])
    np.testing.assert_allclose(cum_mediane.cum_mediane(données), attendu)

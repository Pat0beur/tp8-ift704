from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "cum_mediane",
        ["src/interface.cpp", "src/cum_mediane.cpp"],
    ),
]
setup(
    name="cum-mediane",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.9",
)

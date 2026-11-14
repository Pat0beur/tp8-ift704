# Configuration Sphinx pour la doc du module cum_mediane
import os
import sys

# Chemin vers le package src (pour que Sphinx trouve le module compilé)
sys.path.insert(0, os.path.abspath(".."))

project = "cum_mediane"
copyright = "2026, Julien Bougues"
author = "Julien Bougues"
release = "0.1.0"

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.intersphinx",
    "sphinx.ext.napoleon",
    "sphinx_rtd_theme",
]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

# Thème ReadTheDocs (celui qu'on utilise en ligne)
html_theme = "sphinx_rtd_theme"

intersphinx_mapping = {
    "python": ("https://docs.python.org/3", None),
    "numpy": ("https://numpy.org/doc/stable/", None),
}

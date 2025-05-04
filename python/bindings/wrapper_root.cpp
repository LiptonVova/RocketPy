#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../../cpp/simcalc/calc.hpp"
#include "../../cpp/vroot/root.hpp"

namespace py = pybind11;

void draw_graph_wrapper(fvec& dfinal, int index1, int index2) {
    int argc = 0;
    char** argv = nullptr;
    TApplication app("root_app", &argc, argv);

    draw_graph(dfinal, index1, index2);

    app.Run();
}

PYBIND11_MODULE(rocket_root, m) {
    m.def("draw_graph", &draw_graph_wrapper, py::arg("dfinal"), py::arg("index1"), py::arg("index2")); 
}
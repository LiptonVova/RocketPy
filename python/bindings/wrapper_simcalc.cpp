#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../../cpp/simcalc/calc.hpp"

namespace py = pybind11;

PYBIND11_MODULE(rocket_core, m) {
    //globals
    m.attr("dragCd") = dragCd;
    m.attr("Xarea") = Xarea;
    m.attr("stmass") = stmass;
    m.attr("wind") = wind;

    m.attr("tstep") = tstep;
    m.attr("thrust") = thrust;
    m.attr("btime") = btime;    
    m.attr("promass") = promass;
    m.attr("tmass") = tmass;
    m.attr("para") = para; 
    m.attr("vintx") = vintx; 
    m.attr("vinty") = vinty;
    m.attr("par") = par;
    m.attr("thcurv") = thcurv;

    m.attr("pp0") = pp0;
    m.attr("pp1") = pp1;
    m.attr("pp2") = pp2;
    m.attr("pp3") = pp3;
    m.attr("pp4") = pp4;
    m.attr("pp5") = pp5;
    m.attr("pp6") = pp6; 

    py::class_<vec>(m, "vec")
        .def(py::init<>())
        .def_readwrite("x", &vec::x)
        .def_readwrite("y", &vec::y);

    py::class_<prock>(m, "prock")
        .def(py::init<>())
        .def_readwrite("d", &prock::d)
        .def_readwrite("v", &prock::v)
        .def_readwrite("Ft", &prock::Ft)
        .def_readwrite("m", &prock::m);

    py::class_<frock>(m, "frock")
        .def(py::init<>())
        .def_readwrite("fd", &frock::fd)
        .def_readwrite("fw", &frock::fw)
        .def_readwrite("ft", &frock::ft)
        .def_readwrite("fg", &frock::fg);

    py::class_<fvec>(m, "fvec")
        .def(py::init<>())
        .def_readwrite("v", &fvec::v)
        .def_readwrite("d", &fvec::d);

    //main functions
    m.def("initialize", &initialize);

    m.def("use_thrustCurve", &use_thrustCurve);

    //--------------Calc & Sum forces---------------//
    m.def("calc_forces", &calc_forces);

    //------------------Kinematics-----------------//
    m.def("calc_kinematics", &calc_kinematics);

    //-------------------logdata---------------------//
    m.def("log_data", &log_data);

    m.def("mag", &mag);

    //------------------setters------------------//
    m.def("set_thrust", &set_thrust);
    m.def("set_stmass", &set_stmass);
    m.def("set_dragCd", &set_dragCd);
    m.def("set_Xarea", &set_Xarea);
    m.def("set_wind", &set_wind);

    m.def("get_btime", &get_btime);

    m.def("deploy_Chute", &deploy_Chute);
}
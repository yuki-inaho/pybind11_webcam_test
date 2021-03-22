#include "pybind11/pybind11.h"
#include "ndarray_converter.h"
#include "webcam.h"

namespace py = pybind11;

PYBIND11_MODULE(pywebcam, m) {
    NDArrayConverter::init_numpy();
    py::class_<WebcamCpp>(m, "Webcam")
        .def(py::init<int32_t>(), py::arg("video_idx"))
        .def("update", &WebcamCpp::update)
        .def("get", &WebcamCpp::get);
}
#include <string>
#include "pybind11/pybind11.h"
#include "ndarray_converter.h"
#include "struct.h"
#include "webcam.h"

namespace py = pybind11;

PYBIND11_MODULE(pybind_webcam_test, m) {
    NDArrayConverter::init_numpy();
    py::class_<CameraInformation>(m, "CameraInformation")
        .def(
            py::init<const std::string&>(),
            py::arg("device_id")
        );

    py::class_<WebcamCpp>(m, "Webcam")
        .def(py::init<CameraInformation>(), py::arg("camera_info"))
        .def("update", &WebcamCpp::update)
        .def("get", &WebcamCpp::get);
}
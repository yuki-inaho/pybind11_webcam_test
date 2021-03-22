import toml
from pathlib import Path
from typing import Dict, Any
from pybind_webcam_test import CameraInformation, Webcam

WORK_DIR = str(Path().resolve())


def read_toml(toml_path: str) -> Dict[str, Any]:
    with open(toml_path, "r") as f:
        dict_toml = toml.load(f)
    return dict_toml


toml_path = str(Path(WORK_DIR, "config", "config.toml"))
dict_toml = read_toml(toml_path)

camera_info = CameraInformation(device_id=dict_toml["Camera"]["device_id"])

cam = Webcam(camera_info)
if cam.update():
    test = cam.get()
    print(test.shape)
del cam
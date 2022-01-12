
When we build an executable using CMake, by default it inserts the local absolute path to the linked library to the DT_RPATH in the ELF binary. This can be inspected using the readelf utility on linux.

readelf -d | grep RPATH



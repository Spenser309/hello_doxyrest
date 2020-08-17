# hello\_doxyrest

Hello world example which shows a bug in DoxyRest

## Docker Build
```
cd docker
docker build -t hello_doxyrest .
```

To start a container with /mnt bind mounted to home directory.

```
docker run -it -v ~/:/mnt hello_doxyrest /bin/bash
```

## Build

```
mkdir build
cd build
cmake ..
make
make sphinx-docs
```


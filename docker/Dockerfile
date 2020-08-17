FROM ubuntu:18.04

RUN apt-get update && apt-get -y install \
    build-essential \
    curl git \
    python3 \
    python3-pip \
    python3-dev \
    python3-setuptools \
    liblua5.2-0 \
    libcurl4-openssl-dev \
    zlib1g-dev \
    bison flex \
    vim graphviz \
    && rm -rf /var/lib/apt/lists/*

RUN cd /tmp && \
    curl -ssL 'https://github.com/Kitware/CMake/releases/download/v3.13.4/cmake-3.13.4.tar.gz' -o /tmp/cmake.tar.gz && \
    tar xzf /tmp/cmake.tar.gz -C /tmp && \
    cd /tmp/cmake-3.13.4 && \
    ./bootstrap --parallel=4 --system-curl --prefix=/opt/cmake-3.13.4 && \
    make -j4 && \
    make install && \
    cd .. && rm -rf cmake-3.13.4*
ENV PATH=${PATH}:/opt/cmake-3.13.4/bin

RUN curl -ssL 'http://doxygen.nl/files/doxygen-1.8.19.src.tar.gz' -o /tmp/doxygen.tar.gz && \
   tar xzf /tmp/doxygen.tar.gz -C /tmp && \
   mkdir /tmp/doxygen-1.8.19/build && \
   cd /tmp/doxygen-1.8.19/build && \
   cmake -DCMAKE_INSTALL_PREFIX=/opt/doxygen-1.8.19/ .. && \
   make -j4 && \
   make install && \
   rm -rf /tmp/doxygen*
ENV PATH=${PATH}:/opt/doxygen-1.8.19/bin

RUN curl -ssL 'https://github.com/vovkos/doxyrest/releases/download/doxyrest-2.1.0/doxyrest-2.1.0-linux-amd64.tar.xz' -o /tmp/doxyrest.tar.xz && \
   xz -d /tmp/doxyrest.tar.xz && \
   tar xf /tmp/doxyrest.tar -C /opt/ && \
   rm -rf /tmp/doxyrest.tar.xz

RUN mv /opt/doxyrest-2.1.0-linux-amd64/lib/cmake/doxyrest/{doxyrest_config.cmake,doxyrest-config.cmake}

ENV PATH=${PATH}:/opt/doxyrest-2.1.0/bin

RUN pip3 install sphinx sphinx_rtd_theme
RUN pip3 install --upgrade keyrings.alt



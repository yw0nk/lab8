
FROM ubuntu:24.04


RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    wget \
    curl \
    libssl-dev \
    zlib1g-dev \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tmp
RUN wget https://cmake.org/files/v3.29/cmake-3.29.2.tar.gz && \
    tar -xzvf cmake-3.29.2.tar.gz && \
    cd cmake-3.29.2 && \
    ./bootstrap && \
    make -j$(nproc) && \
    make install && \
    cd / && rm -rf /tmp/*


COPY . /app
WORKDIR /app


RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build --target solver_application


ENV LOG_PATH=/logs/log.txt

WORKDIR /app/build/solver_application


VOLUME /logs

ENTRYPOINT ["./solver"]


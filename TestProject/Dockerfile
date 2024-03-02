FROM gcc:latest as build

RUN mkdir /usr/bin/gfortran 

COPY . /src

WORKDIR ./src

RUN apt-get update && \
    apt-get install libboost-all-dev libboost-program-options-dev \
    libpaho-mqttpp-dev libpaho-mqtt-dev\
    cmake \
    mosquitto -y -f \
    postgresql

RUN cd src && \
    cmake . && \
    make install

COPY init_services.sh /src/init_services.sh

COPY ./config/pg_hba.conf /etc/postgresql/15/main/pg_hba.conf 

EXPOSE 5432 8884

ENTRYPOINT exec /src/init_services.sh


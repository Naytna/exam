FROM ubuntu:18.04

LABEL author="Nikolaev Ilya"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y


EXPOSE 33333

WORKDIR /root/
RUN mkdir Nikolaev_221_3210
WORKDIR /root/Nikolaev_221_3210/
COPY . /root/Nikolaev_221_3210/


RUN qmake -qt5 hallServer.pro
RUN make

ENTRYPOINT ["./hallServer"]

FROM ubuntu
RUN apt-get update && apt-get upgrade -y && apt install nano -y && apt install build-essential -y
COPY ./lab3.cpp /home/lab3.cpp
WORKDIR /home
RUN g++ -o lab3 lab3.cpp
FROM --platform=x86_64 ubuntu:latest

WORKDIR /root/workdir/

COPY ./src/hexview.c src/hexview.c
COPY ./src/main.c    src/main.c

COPY ./include/hexview.h include/hexview.h
COPY ./makefile .

COPY ./test.c .

RUN apt update && apt upgrade -y && apt install build-essential -y
RUN gcc test.c -o test

RUN make
CMD [ "./main" ]
 
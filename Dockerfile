# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu

# These commands copy your files into the specified directory in the image
# and set that as the working location
VOLUME /root/env
WORKDIR /root/env

RUN apt-get update
RUN apt-get upgrade
RUN apt-get install build-essential binutils gcc g++ -y
# This command compiles your app using GCC, adjust for your source code


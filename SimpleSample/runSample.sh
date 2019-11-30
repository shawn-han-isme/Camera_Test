#!/bin/bash

HOST_ARCH=`uname -m | sed -e 's/i.86/i686/' -e 's/^armv.*/arm/'`
if [ $HOST_ARCH = "x86_64" ]; then
  GENICAM_LIB_SUBDIR=Linux64_x64
elif [ $HOST_ARCH = "i686" ]; then
  GENICAM_LIB_SUBDIR=Linux32_i86
elif [ $HOST_ARCH = "arm" ]; then 
  GENICAM_LIB_SUBDIR=Linux32_ARM
fi

START_DIR=`dirname $0`
START_DIR=`cd $START_DIR/../../..; pwd`
export LD_LIBRARY_PATH=./:/$START_DIR/lib/Libusb/:/$START_DIR/lib/GenICam/bin/:/$START_DIR/lib/GenICam/bin/$GENICAM_LIB_SUBDIR/:/$START_DIR/lib/:$LD_LIBRARY_PATH
./sample


################################################################################
################################################################################
##
## Makefile -- makefile for v2.3
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
##
################################################################################
################################################################################

TOPDIR = ../../../..
SUBDIR = FreeRTOS/portable/RVDS/ARM7_LPC21xx

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

LIBRARY = libFreeRTOS_portable

################################################################################
# source files
################################################################################

HEADERS += portmacro.h
SOURCES += portASM.s
SOURCES += port.c

################################################################################
# define user targets
################################################################################

default: build

clean: clean-objects clean-library

build:  build-objects build-library

headers: install-headers

install: build install-library

all: clean build install


include $(TOPDIR)/env/make/Makefile.rules



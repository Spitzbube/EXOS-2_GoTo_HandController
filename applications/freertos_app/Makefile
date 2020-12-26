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

TOPDIR = ../..
SUBDIR = applications/freertos_app

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# source files
################################################################################

SOURCES += main.c
SOURCES += uart.c
SOURCES += data.c
SOURCES += Startup.s

################################################################################
# define define user cc flags
################################################################################



################################################################################
# define define user ld flags
################################################################################



################################################################################
# define library used
################################################################################

LIBRARIES  = FreeRTOS FreeRTOS_portable

################################################################################
# define target name
################################################################################

PROGRAM = freertos_app

################################################################################
# define user targets
################################################################################

default: install

clean: clean-objects clean-program

build:  build-objects build-program build-elfdump-program build-intelhex-program

install: build install-program install-intelhex-program

headers:

all: clean build install


include $(TOPDIR)/env/make/Makefile.rules



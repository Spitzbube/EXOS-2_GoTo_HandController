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

#SOURCES += file_1f30.c
#SOURCES += object_database.c
#SOURCES += align_stars.c
#SOURCES += alignment.c
#SOURCES += earth.c
#SOURCES += mercury.c
#SOURCES += venus.c
#SOURCES += mars.c
#SOURCES += jupiter.c
#SOURCES += saturn.c
#SOURCES += uranus.c
#SOURCES += neptun.c
#SOURCES += pluto.c
#SOURCES += HelpScreen.c
#SOURCES += func_23130.c
#SOURCES += language.c
#SOURCES += func_27844.c
#SOURCES += func_3d72c.c
SOURCES += led.c
SOURCES += main.c
SOURCES += uart.c
SOURCES += data.c
SOURCES += Startup.s

################################################################################
# define define user cc flags
################################################################################

CCFLAGS += -DINCLUDE_ALL_C_FILES

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



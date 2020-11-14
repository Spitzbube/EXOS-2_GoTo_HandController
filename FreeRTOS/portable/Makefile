################################################################################
################################################################################
##
## Makefile -- makefile for FreeRTOS modules.
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
## o DIRECTORIES = the list of sub directories to build
##
################################################################################
################################################################################

  TOPDIR = ../..
  SUBDIR = FreeRTOS/portable

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

   DIRECTORIES += RVDS

################################################################################
# define user targets
################################################################################

default: all

clean: $(DIRECTORIES:%=subdir-clean-%)

build: $(DIRECTORIES:%=subdir-build-%)

headers: $(DIRECTORIES:%=subdir-headers-%)

install: $(DIRECTORIES:%=subdir-install-%)

depend: $(DIRECTORIES:%=subdir-depend-%)

all: clean build install

################################################################################
# include internal definitions and rules
################################################################################

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# local directory specific rules
################################################################################

subdir-clean-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking clean [$(SUBDIR)/$(@:subdir-clean-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-clean-%=%) clean TARGET=$(TARGET)

subdir-depend-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking depend [$(SUBDIR)/$(@:subdir-depend-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-depend-%=%) depend TARGET=$(TARGET)

subdir-headers-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking headers [$(SUBDIR)/$(@:subdir-headers-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-headers-%=%) headers TARGET=$(TARGET)

subdir-build-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking build [$(SUBDIR)/$(@:subdir-build-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-build-%=%) build TARGET=$(TARGET)

subdir-install-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking install [$(SUBDIR)/$(@:subdir-install-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-install-%=%) install TARGET=$(TARGET)

subdir-release-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking release [$(SUBDIR)/$(@:subdir-release-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-release-%=%) release TARGET=$(TARGET)

subdir-doc-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking doc [$(SUBDIR)/$(@:subdir-doc-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-doc-%=%) doc TARGET=$(TARGET)


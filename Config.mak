################################################################################
################################################################################
##
## Config.mak -- user specific development environment settings
##
## Copy this file into Config.mak.<username> to protect your private settings
## from being overwritten the next time you get an update.
## The make environment will first check for file "Config.mak.<username>",
## it will use the file "Config.mak" only if the user specific configuration
## file does not exist. <username> should be the string reported by
## "echo %USERNAME%" if you are using the standard windows shell, Cygwin
## users should call "echo $USERNAME" instead.
##
################################################################################
################################################################################

  TARGET   ?= arm7-realview

  
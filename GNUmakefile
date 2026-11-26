include $(GNUSTEP_MAKEFILES)/common.make

#
# Application
#
VERSION = 0.4
PACKAGE_NAME = AgnostepManager
APP_NAME = AgnostepManager
AgnostepManager_APPLICATION_ICON = AgnostepManager.tiff


#
# Resource files
#
AgnostepManager_RESOURCE_FILES = \
Resources/AgnostepManager.tiff \
Resources/Menu-GNUstep.gsmarkup \
Resources/Menu-OSX.gsmarkup \
Resources/TargetWindow.gsmarkup

#
# Localization
#
AgnostepManager_LANGUAGES = English French
AgnostepManager_LOCALIZED_RESOURCE_FILES = \
Localizable.strings \
InfoPlist.strings \
AgnostepManager.help \
Menu-GNUstep.strings \
Menu-OSX.strings

#
# Header files
#
AgnostepManager_HEADER_FILES = \
MyDelegate.h

#
# Objective-C Class files
#
AgnostepManager_OBJC_FILES = \
MyDelegate.m

#
# Other sources
#
AgnostepManager_OBJC_FILES += \
Main.m

#
#  Lib Renaissance
#
ifeq ($(FOUNDATION_LIB), apple)
  ADDITIONAL_INCLUDE_DIRS += -framework Renaissance
  ADDITIONAL_GUI_LIBS += -framework Renaissance
else
  ADDITIONAL_GUI_LIBS += -lRenaissance
endif

#
# Makefiles
#
include $(GNUSTEP_MAKEFILES)/application.make

####################################################
### A G N o S t e p  -  Desktop 
### (c) 2026 - Patrick Cardona
### Author: Patrick Cardona
###
### Thanks for the GNUstep Developers Community.
### This application is a free software.
### Read complete LICENSE.txt in the root directory.
####################################################

####################################################
### AgnostepManager.app: Agnostep Manager
### for the Agnostep Desktop Project
### Makefile: build the socket Helper
####################################################

PREFIX  ?= /usr/local
BINDIR  ?= $(PREFIX)/bin
CC      ?= cc
PKG_CONFIG ?= pkg-config

TARGET  = agnomgr_socket
SOURCE  = agnomgr_socket.c

GTK_CFLAGS := $(shell $(PKG_CONFIG) --cflags gio-unix-2.0)
GTK_LIBS   := $(shell $(PKG_CONFIG) --libs gio-unix-2.0)

CFLAGS  ?= -O2
CFLAGS  += -Wall -Wextra $(GTK_CFLAGS)
LDLIBS  += -lX11

.PHONY: all install clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

install: $(TARGET)
	install -d "$(DESTDIR)$(BINDIR)"
	install -m 755 $(TARGET) "$(DESTDIR)$(BINDIR)/$(TARGET)"

clean:
	rm -f $(TARGET)


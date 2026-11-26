# Agnostep Manager

AGNoStep  -  Apps Project
(c) 2026 - Patrick Cardona

Thanks for the GNUstep Developers Community.
This is Free and Open Source software.
Read [LICENSE](./LICENSE) in the root directory.

## What is AgnostepManager?

This is a GNUstep gui to [agnostep-apps-manager](../../../agnostep-apps-manager).
It allows to install all the necessary software to create
the whole Desktop experience.

## Dependencies

**AgnostepManager** depends on:
- A Xorg Server, because it uses Xembed.
- A complete GNUstep System:  
see [Agnostep](../../../agnostep) project.
- [agnostep-apps-manager](../../../agnostep-apps-manager) tools and scripts.

It is mandatory to keep this folder safe:

```
~/SOURCES/agnostep-apps-manager
```

If not present, to repair, just do this:

```console
cd
mkdir -p SOURCES && cd SOURCES
git clone https://github.com/pcardona34/agnostep-apps-manager
``` 

## Install

You must have superuser privileges to type your password
when asked.

### With agnostep-apps-manager

1. Run agnostep-apps-manager:
  ```console
  cd ~/SOURCES/agnostep-apps-manager
  bash ./agnostep.sh
  ```
2. Select the category: *agnostep-applications*
3. Select the application: *AgnostepManager*
4. Read info.
5. Confirm the installation.

### By yourself

1. Build and install Helper: read Helper folder INSTALL.
2. Install the Scripts: see the SCRIPTS folder: read SCRIPTS folder INSTALL.
3. Build and install AgnostepManager: read INSTALL.

## Using

```console
openapp AgnostepManager
```

Or run it from the `Applications` folder.

Then use the menu item: `Manager...`

## Help

It is provided from the `Info/Help...` menu item.

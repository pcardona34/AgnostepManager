/* 
####################################################
### A G N o S t e p  -  Desktop 
### (c) 2026 - Patrick Cardona
### Author: Patrick Cardona
###
### Thanks for the GNUstep Developers Community.
### This application is free software.
### Read complete License in the root directory.
####################################################

####################################################
### AgnostepManager.app: Agnostep Manager
### for the Agnostep Desktop Project
### Header: MyDelegate.h
####################################################
*/

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <Renaissance/Renaissance.h>

@interface MyDelegate : NSObject <NSApplicationDelegate>
{
	IBOutlet NSWindow *targetWindow;
	NSTask *bridge;
}

- (void) manager: (id) sender;
- (void) performManagement;
- (void) waitForHelperAndClose;
- (BOOL) checkAM;

@end

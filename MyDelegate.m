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
### Implementation: MyDelegate.m
####################################################
*/

#import <AppKit/AppKit.h>
#import <X11/Xlib.h>
// Backend-specific header; availability/location may vary by GNUstep install.
//#import <GNUstepGUI/GSWindow.h>
#import "MyDelegate.h"

@implementation MyDelegate


- (BOOL) checkAM  
{
  NSString *userName = NSUserName();
  NSString *homeDir = NSHomeDirectoryForUser(userName);
  NSString *am = [homeDir stringByAppendingString: @"/SOURCES/agnostep-desktop"];
  
  NSFileManager *manager = [NSFileManager defaultManager];  
  BOOL isDirectory;  
  BOOL exists = [manager fileExistsAtPath: am isDirectory: &isDirectory];  
  
  if (exists && isDirectory) {  
    return YES;  
  } else {  
    NSAlert *alert = [[[NSAlert alloc] init] autorelease];
    [alert setMessageText: _(@"Agnostep Manager Fatal Error")];
    [alert setInformativeText: [NSString stringWithFormat: _(@"The expected folder: %@ was not found.\nYou must repair it. You should read Help."),  am]];
    [alert runModal];
    [NSApp terminate:nil];
    return NO; // this will never be executed  
  } 
}

- (void) performManagement
{
  if ([self checkAM]) {
  
  // Initializing  the Target Window
  [NSBundle loadGSMarkupNamed: @"TargetWindow" owner: self];
  // Ask the backend window for its native X11 window.
  void *ref = [targetWindow windowRef];
  NSString *parentXID = [NSString stringWithFormat:@"%p", ref];

  bridge = [[NSTask alloc] init];
    [bridge setLaunchPath:@"/usr/local/bin/agnomgr_socket"];
    [bridge setArguments:[NSArray arrayWithObjects:
      parentXID, @"0", @"0", @"568", @"510", nil]];
      
      NSMutableDictionary *env = [NSMutableDictionary dictionaryWithDictionary:
        [[NSProcessInfo processInfo] environment]];
    [bridge setEnvironment:env];
      
   @try {
    [bridge launch];
      NSLog(@"Socket helper launched");
      
      /* Monitor the task in the background */
        [self performSelectorInBackground:@selector(waitForHelperAndClose) 
                               withObject:nil];
                               
  	} @catch (NSException *exception) {
    NSLog(@"Could not launch task: %@ — %@",
          [exception name], [exception reason]);
	}
  } 
}

- (void) manager: (id) sender
{
	[self performManagement];	
}

/* **************************************************************************** */
/*
 * Standard method to prepare the UI from the delegate: applicationDidFinishLaunching
 *
 */

- (void)applicationDidFinishLaunching:(NSNotification *)notification 
{
    //[self performManagement];
}

- (void) waitForHelperAndClose
{
    [bridge waitUntilExit];
    NSLog(@"Helper exited with status %d", [bridge terminationStatus]);
    
    [self performSelectorOnMainThread:@selector(closeWindow) 
                            withObject:nil 
                         waitUntilDone:NO];
}

- (void) closeWindow
{
    [targetWindow close];
}

@end

/* 
####################################################
### A G N o S t e p  -  Desktop 
### (c) 2026 - Patrick Cardona
### Author: Patrick Cardona
###
### Thanks for the GNUstep Developers Community.
### This application is a free software.
### Read complete LICENSE in the root directory.
####################################################

####################################################
### Helper of AgnostepManager.app: Agnostep Manager
### for the Agnostep Apps Project
### agnomgr_socket.c
####################################################
*/

#include <X11/Xlib.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static unsigned long
parse_number(const char *text, const char *name)
{
    char *end = NULL;
    errno = 0;
    unsigned long value = strtoul(text, &end, 0);

    if (errno != 0 || end == text || *end != '\0') {
        fprintf(stderr, "Invalid %s: %s\n", name, text);
        exit(EXIT_FAILURE);
    }
    return value;
}

int
main(int argc, char **argv)
{
    if (argc != 6) {
        fprintf(stderr, "Usage: %s PARENT_XID X Y WIDTH HEIGHT\n", argv[0]);
        return EXIT_FAILURE;
    }

    Window parent = (Window)parse_number(argv[1], "parent XID");
    int x = (int)parse_number(argv[2], "x");
    int y = (int)parse_number(argv[3], "y");
    unsigned int width = (unsigned int)parse_number(argv[4], "width");
    unsigned int height = (unsigned int)parse_number(argv[5], "height");

    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Cannot open X display\n");
        return EXIT_FAILURE;
    }

    /* Create the actual embedding area as a child of the GNUstep window. */
    Window host = XCreateSimpleWindow(
        display, parent, x, y, width, height, 0, 0, 0
    );
    XMapWindow(display, host);
	 XResizeWindow(display, host, width, height);
    XSync(display, False);

    char host_id[32];
    snprintf(host_id, sizeof host_id, "0x%lx", (unsigned long)host);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        XDestroyWindow(display, host);
        XCloseDisplay(display);
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        execl("/usr/bin/xterm", "xterm",
              "-tn", "xterm-256color",
              "-into", host_id,
              "-e", "/usr/local/bin/AMLauncher.sh",
              (char *)NULL);
        perror("execl xterm");
        _exit(127);
    }

    int status;
    while (waitpid(pid, &status, 0) < 0) {
        if (errno != EINTR) {
            perror("waitpid");
            break;
        }
    }

    XDestroyWindow(display, host);
    XCloseDisplay(display);

    return WIFEXITED(status) ? WEXITSTATUS(status) : EXIT_FAILURE;
}

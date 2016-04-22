#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>

void quit_call(void);
void help_call(void);

int main(int argc, char *argv[]) {
	Widget top_wid;
	Widget main_w;
	Widget menu_bar;
	Widget quit;
	Widget help;
	XtAppContext app;
	Arg arg[1];

	top_wid = XtVaAppInitialize(&app, "menu_cascade", NULL, 0, &argc, argv, NULL, NULL);
	main_w = XtVaCreateManagedWidget("main_window", xmMainWindowWidgetClass, top_wid, NULL);
	menu_bar = XmCreateMenuBar(main_w, "main_list", NULL, 0);

	XtManageChild(menu_bar);

	quit = XtVaCreateManagedWidget("Quit", xmCascadeButtonWidgetClass, menu_bar, XmNmnemonic, "Q", NULL);
	help = XtVaCreateManagedWidget("Help", xmCascadeButtonWidgetClass, menu_bar, XmNmnemonic, "H", NULL);

	XtAddCallback(quit, XmNactivateCallback, quit_call, NULL);
	XtAddCallback(help, XmNactivateCallback, help_call, NULL);

	XtSetArg(arg[0], XmNmenuHelpWidget, help);
	XtSetValues(menu_bar, arg, 1);

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void quit_call() {
	printf("Quitting program\n");
	exit(0);
}

void help_call() {
	printf("No one can help you...\n");
}

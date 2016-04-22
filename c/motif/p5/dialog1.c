#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>

void create_dialogs(void);
void info_pop_up(Widget, char *, XmPushButtonCallbackStruct *);
void quit_pop_up(Widget, char *, XmPushButtonCallbackStruct *);
void info_activate(Widget);
void quit_activate(Widget);

Widget info;
Widget quit;
Widget info_dialog;
Widget quit_dialog;

int main(int argc, char *argv[]) {
	XtAppContext app;
	Widget top_wid;
	Widget main_w;
	Widget menu_bar;

	top_wid = XtVaAppInitialize(&app, "Demos", NULL, 0, &argc, argv, NULL, NULL);

	main_w = XtVaCreateManagedWidget("main_window", xmMainWindowWidgetClass, top_wid, XmNheight, 300, XmNwidth, 300, NULL);

	menu_bar = (Widget) XmCreateMenuBar(main_w, "main_list", NULL, 0);
	XtManageChild(menu_bar);

	quit = XtVaCreateManagedWidget("Quit", xmCascadeButtonWidgetClass, menu_bar, XmNmnemonic, "Q", NULL);

	XtAddCallback(quit, XmNactivateCallback, quit_pop_up, NULL);

	info = XtVaCreateManagedWidget("Info", xmCascadeButtonWidgetClass, menu_bar, XmNmnemonic, "I", NULL);

	XtAddCallback(info, XmNactivateCallback, info_pop_up, NULL);

	create_dialogs();

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void create_dialogs() {
	XmString xm_string;
	Arg args[1];

	xm_string = XmStringCreateLocalized("Dialog widgets added to give info and check quit choice");
	XtSetArg(args[0], XmNmessageString, xm_string);

	info_dialog = XmCreateInformationDialog(info, "info", args, 1);

	XmStringFree(xm_string);

	XtAddCallback(info_dialog, XmNokCallback, info_activate, NULL);

	xm_string = XmStringCreateLocalized("Are you sure you want to quit?");
	XtSetArg(args[0], XmNmessageString, xm_string);

	quit_dialog = XmCreateWarningDialog(quit, "quit", args, 1);

	XmStringFree(xm_string);

	XtAddCallback(quit_dialog, XmNokCallback, quit_activate, NULL);
}

void info_pop_up(Widget cascade_button, char *text, XmPushButtonCallbackStruct *cbs) {
	XtManageChild(info_dialog);
}

void quit_pop_up(Widget cascade_button, char *text, XmPushButtonCallbackStruct *cbs) {
	XtManageChild(quit_dialog);
}

void info_activate(Widget dialog) {
	printf("Info Ok was pressed.\n");
}

void quit_activate(Widget dialog) {
	printf("Quit Ok was pressed.\n");
}

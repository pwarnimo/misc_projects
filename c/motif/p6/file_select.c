#include <stdio.h>
#include <stdlib.h>
#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>
#include <Xm/FileSB.h>

void quit_pop_up(Widget, char *, XmPushButtonCallbackStruct *);
void select_pop_up(Widget, char *, XmPushButtonCallbackStruct *);
void ScrubDial(Widget, int);
void select_activate(Widget, XtPointer, XmFileSelectionBoxCallbackStruct *);
void quit_activate(Widget);
void cancel(Widget, XtPointer, XmFileSelectionBoxCallbackStruct *);
void error(char *, char *);

FILE *fopen();

Widget top_wid;

int main(int argc, char *argv[]) {
	XtAppContext app;
	Widget main_w, menu_bar, file_select, quit;

	top_wid = XtVaAppInitialize(&app, "Demos", NULL, 0, &argc, argv, NULL, NULL);

	main_w = XtVaCreateManagedWidget("main_window", xmMainWindowWidgetClass, top_wid,
		XmNheight, 300,
		XmNwidth, 300,
		NULL);

	menu_bar = XmCreateMenuBar(main_w, "main_list", NULL, 0);
	XtManageChild(menu_bar);

	file_select = XtVaCreateManagedWidget("Select",
		xmCascadeButtonWidgetClass, menu_bar,
		XmNmnemonic, "S",
		NULL);

	XtAddCallback(file_select, XmNactivateCallback, select_pop_up, NULL);

	quit = XtVaCreateManagedWidget("Quit", 
		xmCascadeButtonWidgetClass, menu_bar,
		XmNmnemonic, "Q",
		NULL);

	XtAddCallback(quit, XmNactivateCallback, quit_pop_up,
		"Are you sure you want to quit?");

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void select_pop_up(Widget cascade_button, char *text, XmPushButtonCallbackStruct *cbs) {
	Widget dialog, remove;
	XmString mask;
	Arg args[1];

	mask = XmStringCreateLocalized("*.c");
	XtSetArg(args[0], XmNdirMask, mask);

	dialog = XmCreateFileSelectionDialog(cascade_button, "select", args, 1);
	XtAddCallback(dialog, XmNokCallback, select_activate, NULL);
	XtAddCallback(dialog, XmNcancelCallback, cancel, NULL);

	remove = XmSelectionBoxGetChild(dialog, XmDIALOG_HELP_BUTTON);

	XtUnmanageChild(remove);

	XtManageChild(dialog);
	XtPopup(XtParent(dialog), XtGrabNone);
}

void quit_pop_up(Widget cascade_button, char *text, XmPushButtonCallbackStruct *cbs) {
	Widget dialog;
	XmString xm_string;
	Arg args[2];

	xm_string = XmStringCreateLocalized(text);
	XtSetArg(args[0], XmNmessageString, xm_string);
	XtSetArg(args[1], XmNdefaultButtonType, XmDIALOG_CANCEL_BUTTON);

	dialog = XmCreateWarningDialog(cascade_button, "quit", args, 2);

	ScrubDial(dialog, XmDIALOG_HELP_BUTTON);

	XmStringFree(xm_string);

	XtAddCallback(dialog, XmNokCallback, quit_activate, NULL);

	XtManageChild(dialog);
	XtPopup(XtParent(dialog), XtGrabNone);
}

void ScrubDial(Widget wid, int dial) {
	Widget remove;

	remove = XmMessageBoxGetChild(wid, dial);
	XtUnmanageChild(remove);
}

void select_activate(Widget widget, XtPointer client_data, XmFileSelectionBoxCallbackStruct *selection) {
	FILE *fp;
	char *filename, line[200];

	XmStringGetLtoR(selection->value, XmSTRING_DEFAULT_CHARSET, &filename);

	if ((fp = fopen(filename, "r")) == NULL) {
		error("CANNOT OPEN FILE", filename);
	}
	else {
		while (!feof(fp)) {
			fgets(line, 200, fp);
			printf("%s\n", line);
		}

		fclose(fp);
	}
}

void cancel(Widget widget, XtPointer client_data, XmFileSelectionBoxCallbackStruct *selection) {
	XtUnmanageChild(widget);
}

void error(char *s1, char *s2) {
	printf("%s: %s\n", s1, s2);
	exit(-1);
}

void quit_activate(Widget dialog) {
	printf("Quit OK was pressed.\n");
	exit(0);
}

#include <Xm/MainW.h>
#include <Xm/Label.h>
#include <Xm/Command.h>
#include <Xm/TextF.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 30

void cmd_cbk();
void quit_cbk();

Widget msg_wid;

char *cmd_label = "Command Area: ";
char *msg_label = "Message Area: ";

int cmd_label_length;
int msg_label_length;

int main(int argc, char *argv[]) {
	Widget top_wid;
	Widget main_win;
	Widget menubar;
	Widget menu;
	Widget label;
	Widget cmd_wid;
	XtAppContext app;
	XmString label_str;
	XmString quit;

	top_wid = XtVaAppInitialize(&app, "Main Window", NULL, 0, &argc, argv, NULL, NULL);

	main_win = XtVaCreateWidget("main_w", xmMainWindowWidgetClass, top_wid, XmNcommandWindowLocation, XmCOMMAND_BELOW_WORKSPACE, NULL);

	quit = XmStringCreateLocalized("Quit");
	menubar = XmVaCreateSimpleMenuBar(main_win, "menubar", 
		XmVaCASCADEBUTTON, quit, "Q",
		NULL);

	menu = XmVaCreateSimplePulldownMenu(menubar, "file_menu", 0, quit_cbk,
		XmVaPUSHBUTTON, quit, "Q", NULL, NULL,
		NULL);

	XmStringFree(quit);

	XtManageChild(menubar);

	label_str = XmStringCreateLocalized("Work Area");

	label = XtVaCreateManagedWidget("main_window", xmLabelWidgetClass, main_win, XmNlabelString, label_str, XmNwidth, 1000, XmNheight, 800, NULL);

	XmStringFree(label_str);

	cmd_wid = XtVaCreateWidget("Command", xmTextFieldWidgetClass, main_win, XmNmaxLength, MAX_STR_LEN, NULL);

	XmTextSetString(cmd_wid, cmd_label);
	XmTextSetInsertionPosition(cmd_wid, cmd_label_length);

	XtAddCallback(cmd_wid, XmNactivateCallback, cmd_cbk, NULL);

	XtManageChild(cmd_wid);

	msg_wid = XtVaCreateWidget("Message:", xmTextFieldWidgetClass, main_win, XmNeditable, False, XmNmaxLength, MAX_STR_LEN, NULL);

	XmTextSetString(msg_wid, msg_label);

	XtManageChild(msg_wid);

	XtVaSetValues(main_win, 
		XmNmenuBar, menubar, 
		XmNworkWindow, label,
		XmNcommandWindow, cmd_wid, 
		XmNmessageWindow, msg_wid, 
		NULL);

	XtManageChild(main_win);
	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void cmd_cbk(Widget cmd_widget, XtPointer *client_data, XmAnyCallbackStruct *cbs) {
	char cmd[MAX_STR_LEN];
	char msg[MAX_STR_LEN];

	XmTextGetSubstring(cmd_widget, cmd_label_length, MAX_STR_LEN - cmd_label_length, MAX_STR_LEN, cmd);

	XmTextReplace(msg_wid, msg_label_length, MAX_STR_LEN, cmd);

	XmTextSetString(cmd_widget, cmd_label);
	XmTextSetInsertionPosition(cmd_widget, cmd_label_length);
}

void quit_cbk(Widget w, int item_no) {
	if (item_no == 0) {
		exit(0);
	}
}

#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/Label.h>

void quit_call(Widget, int);
void menu_call(Widget, int);
void help_call(void);

Widget label;
String food[] = {"Chicken", "Beef", "Pork", "Lamb", "Cheese"};

int main(int argc, char *argv[]) {
	Widget top_wid;
	Widget main_w;
	Widget help;
	Widget menubar;
	Widget menu;
	Widget widget;
	XtAppContext app;
	XColor back;
	XColor fore;
	XColor spare;
	XmString quit, menu_str, help_str, chicken, beef, pork, lamb, cheese, label_str;

	int n = 0;
	Arg args[2];

	top_wid = XtVaAppInitialize(&app, "Demos", NULL, 0, &argc, argv, NULL, NULL);
	main_w = XtVaCreateManagedWidget("main_window", xmMainWindowWidgetClass, top_wid, XmNwidth, 300, XmNheight, 300, NULL);
	quit = XmStringCreateLocalized("Quit");
	menu_str = XmStringCreateLocalized("Menu");
	help_str = XmStringCreateLocalized("Help");

	menubar = XmVaCreateSimpleMenuBar(main_w, "menubar",
		XmVaCASCADEBUTTON, quit, "Q",
		XmVaCASCADEBUTTON, menu_str, "M",
		XmVaCASCADEBUTTON, help_str, "H", 
		NULL);

	XmStringFree(menu_str);
	XmStringFree(help_str);

	XmVaCreateSimplePulldownMenu(menubar, "quit_menu", 0, quit_call, XmVaPUSHBUTTON, quit, "Q", NULL, NULL, NULL);
	XmStringFree(quit);

	chicken = XmStringCreateLocalized(food[0]);
	beef = XmStringCreateLocalized(food[1]);
	pork = XmStringCreateLocalized(food[2]);
	lamb = XmStringCreateLocalized(food[3]);
	cheese = XmStringCreateLocalized(food[4]);

	menu = XmVaCreateSimplePulldownMenu(menubar, "edit_menu", 1, menu_call,
		XmVaRADIOBUTTON, chicken, "C", NULL, NULL,
		XmVaRADIOBUTTON, beef, "B", NULL, NULL,
		XmVaRADIOBUTTON, pork, "P", NULL, NULL,
		XmVaRADIOBUTTON, lamb, "L", NULL, NULL,
		XmVaRADIOBUTTON, cheese, "h", NULL, NULL,
		XmNradioBehavior, True,
		XmNradioAlwaysOne, True,
		NULL);

	XmStringFree(chicken);
	XmStringFree(beef);
	XmStringFree(pork);
	XmStringFree(lamb);
	XmStringFree(cheese);

	if (widget = XtNameToWidget(menu, "button_1")) {
		XtSetArg(args[n], XmNset, True);
		n++;
		XtSetValues(widget, args, n);
	}

	n = 0;

	help = XtVaCreateManagedWidget("Help", xmCascadeButtonWidgetClass, menubar, XmNmnemonic, "H", NULL);

	XtAddCallback(help, XmNmenuHelpWidget, help_call, NULL);

	XtSetArg(args[n], XmNmenuHelpWidget, help);
	n++;
	XtSetValues(menubar, args, n);
	n = 0;

	XtManageChild(menubar);

	label_str = XmStringCreateLocalized(food[0]);

	label = XtVaCreateManagedWidget("main_window", xmLabelWidgetClass, main_w, XmNlabelString, label_str, NULL);

	XmStringFree(label_str);

	XtVaSetValues(main_w, XmNmenuBar, menubar, XmNworkWindow, label, NULL);

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void quit_call(Widget w, int item_no) {
	if (item_no == 0) {
		exit(0);
	}
}

void menu_call(Widget w, int item_no) {
	int n = 0;
	Arg args[1];

	XmString label_str;

	label_str = XmStringCreateLocalized(food[item_no]);

	XtSetArg(args[n], XmNlabelString, label_str);
	++n;
	XtSetValues(label, args, n);
}

void help_call() {
	printf("I can't help you...\n");
}

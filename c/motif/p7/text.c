#include <Xm/Xm.h>
#include <Xm/Text.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void quit_call();
void help_call();
void read_file(Widget);

int main(int argc, char *argv[]) {
	Widget top_wid, main_w, menu_bar, menu, quit, help, text_wid;
	XtAppContext app;
	Arg args[4];

	top_wid = XtVaAppInitialize(&app, "Text", NULL, 0, &argc, argv, NULL, NULL);

	main_w = XtVaCreateManagedWidget("main_w", xmMainWindowWidgetClass, top_wid, NULL);

	menu_bar = XmCreateMenuBar(main_w, "main_list", NULL, 0);
	XtManageChild(menu_bar);

	quit = XtVaCreateManagedWidget("Quit", 
		xmCascadeButtonWidgetClass, menu_bar, 
		XmNmnemonic, "Q", 
		NULL);

	XtAddCallback(quit, XmNactivateCallback, quit_call, NULL);

	XtSetArg(args[0], XmNrows, 30);
	XtSetArg(args[1], XmNcolumns, 80);
	XtSetArg(args[2], XmNeditable, False);
	XtSetArg(args[3], XmNeditMode, XmMULTI_LINE_EDIT);

	text_wid = XmCreateScrolledText(main_w, "text_wid", args, 4);
	XtManageChild(text_wid);

	read_file(text_wid);

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void read_file(Widget text_wid) {
	static char *filename = "text.c";
	char *text;
	struct stat statb;
	FILE *fp;

	if ((stat(filename, &statb) == -1) || !(fp = fopen(filename, "r"))) {
		fprintf(stderr, "Unable to open file: %s\n", filename);
		XtFree(filename);
		
		return;
	}

	if (!(text = XtMalloc((unsigned)(statb.st_size + 1)))) {
		fprintf(stderr, "Can't alloc enough space for %s", filename);
		XtFree(filename);
		fclose(fp);

		return;
	}

	if (!fread(text, sizeof(char), statb.st_size + 1, fp)) {
		fprintf(stderr, "File read error\n");
	}

	text[statb.st_size] = 0;

	XmTextSetString(text_wid, text);

	XtFree(text);
	//XtFree(filename);
	fclose(fp);
}

void quit_call() {
	printf("Quitting program\n");
	exit(0);
}

#include <Xm/Xm.h>
#include <Xm/PushB.h>

void pushed_fn(Widget, XtPointer, XmPushButtonCallbackStruct *);

int main(int argc, char *argv[]) {
	Widget top_wid;
	Widget button;
	XtAppContext app;

	top_wid = XtVaAppInitialize(&app, "Push", NULL, 0, &argc, argv, NULL, NULL);
	button = XmCreatePushButton(top_wid, "Push_me", NULL, 0);

	XtManageChild(button);
	XtAddCallback(button, XmNactivateCallback, pushed_fn, NULL);

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void pushed_fn(Widget w, XtPointer client_data, XmPushButtonCallbackStruct *cbs) {
	printf("Don't click me!");
}

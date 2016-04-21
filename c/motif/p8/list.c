#include <Xm/Xm.h>
#include <Xm/List.h>

void list_cbk(Widget, XtPointer, XmListCallbackStruct *);

String colours[] = {
	"Black",
	"Red",
	"Green",
	"Blue",
	"Grey"
};

Display *display;
Colormap cmap;

int main(int argc, char *argv[]) {
	Widget top_wid, list;
	XtAppContext app;
	int i, n = XtNumber(colours);
	XColor back, fore, spare;
	XmStringTable str_list;
	Arg args[4];

	top_wid = XtVaAppInitialize(&app, "List_top", NULL, 0, &argc, argv, NULL, NULL);

	str_list = (XmStringTable)XtMalloc(n * sizeof(XmString *));

	for (i = 0; i < n; i++) {
		str_list[i] = XmStringCreateSimple(colours[i]);
	}

	list = XtVaCreateManagedWidget("List",
		xmListWidgetClass, top_wid,
		XmNvisibleItemCount, n,
		XmNitemCount, n,
		XmNitems, str_list,
		XmNwidth, 300,
		XmNheight, 300,
		NULL);

	for (i = 0; i < n; i++) {
		XmStringFree(str_list[i]);
	}

	XtFree(str_list);

	cmap = DefaultColormapOfScreen(XtScreen(list));
	display = XtDisplay(list);

	XAllocNamedColor(display, cmap, colours[0], &back, &spare);
	XAllocNamedColor(display, cmap, "white", &fore, &spare);

	n = 0;
	XtSetArg(args[n], XmNbackground, back.pixel);
	++n;
	XtSetArg(args[n], XmNforeground, fore.pixel);
	++n;
	XtSetValues(list, args, n);

	XtAddCallback(list, XmNdefaultActionCallback, list_cbk, NULL);

	XtRealizeWidget(top_wid);
	XtAppMainLoop(app);
}

void list_cbk(Widget w, XtPointer data, XmListCallbackStruct *list_cbs) {
	int n = 0;
	Arg args[1];
	String selection;
	XColor xcolour, spare;

	XmStringGetLtoR(list_cbs->item, XmSTRING_DEFAULT_CHARSET, &selection);

	if (XAllocNamedColor(display, cmap, selection, &xcolour, &spare) == 0) {
		return;
	}

	XtSetArg(args[n], XmNbackground, xcolour.pixel);
	++n;
	XtSetValues(w, args, n);
}

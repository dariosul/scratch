/*
 * node_info.c
 *
 *  Created on: Sep 30, 2013
 *      Author: drusk
 */

#include <stdlib.h>

#include <Xm/PushB.h>
#include <Xm/RowColumn.h>

int main(int argc, char *argv[]) {

	XtAppContext app;
	Widget root_widget;
	Widget row_column;
	Widget update_button;
	Widget close_button;

	void update_callback(Widget, XtPointer, XtPointer);
	void close_callback(Widget, XtPointer, XtPointer);

	XtSetLanguageProc(NULL, NULL, NULL);

	root_widget = XtVaOpenApplication(&app, "Node Info", NULL, 0, &argc,
			argv, NULL, sessionShellWidgetClass, NULL);

	row_column = XmCreateRowColumn(root_widget, "MainRowCol", NULL, 0);

	update_button = XmCreatePushButton(row_column, "Update", NULL, 0);
	XtAddCallback(update_button, XmNactivateCallback, update_callback, NULL);

	close_button = XmCreatePushButton(row_column, "Close", NULL, 0);
	XtAddCallback(close_button, XmNactivateCallback, close_callback, NULL);

	XtManageChild(update_button);
	XtManageChild(close_button);
	XtManageChild(row_column);

	XtRealizeWidget(root_widget);
	XtAppMainLoop(app);

	return 0;
}

void update_callback(Widget widget, XtPointer client_data, XtPointer call_data) {
	puts("Update was pressed.");
}

void close_callback(Widget widget, XtPointer client_data, XtPointer call_data) {
	exit(0);
}

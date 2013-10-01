/*
 * node_info.c
 *
 *  Created on: Sep 30, 2013
 *      Author: drusk
 */

#include <stdlib.h>

#include <Xm/Form.h>
#include <Xm/LabelG.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>
#include <Xm/TextF.h>

char *labels[] = { "Index:", "X:", "Y:", "Z:", "Code:" };

int main(int argc, char *argv[]) {

	XtAppContext app;
	Widget root_widget;
	Widget row_column;
	Widget update_button;
	Widget close_button;
	Widget text;
	Widget form;
	Widget label;
	Arg args[8];
	int i;
	int n;

	void update_callback(Widget, XtPointer, XtPointer);
	void close_callback(Widget, XtPointer, XtPointer);

	XtSetLanguageProc(NULL, NULL, NULL);

	root_widget = XtVaOpenApplication(&app, "Node Info", NULL, 0, &argc,
			argv, NULL, sessionShellWidgetClass, NULL);

	row_column = XmCreateRowColumn(root_widget, "MainRowCol", NULL, 0);

	for (i = 0; i < XtNumber(labels); i++) {
		n = 0;
		XtSetArg(args[n], XmNfractionBase, 10); n++;
		XtSetArg(args[n], XmNnavigationType, XmNONE); n++;
		form = XmCreateForm(row_column, "form", args, n);

		n = 0;
		XtSetArg(args[n], XmNtopAttachment, XmATTACH_FORM); n++;
		XtSetArg(args[n], XmNbottomAttachment, XmATTACH_FORM); n++;
		XtSetArg(args[n], XmNleftAttachment, XmATTACH_FORM); n++;
		XtSetArg(args[n], XmNrightAttachment, XmATTACH_POSITION); n++;
		XtSetArg(args[n], XmNrightPosition, 3); n++;
		XtSetArg(args[n], XmNalignment, XmALIGNMENT_END); n++;
		XtSetArg(args[n], XmNnavigationType, XmNONE); n++;
		label = XmCreateLabelGadget(form, labels[i], args, n);
		XtManageChild(label);

		n = 0;
		XtSetArg(args[n], XmNtraversalOn, True); n++;
		XtSetArg(args[n], XmNleftAttachment, XmATTACH_POSITION); n++;
		XtSetArg(args[n], XmNleftPosition, 4); n++;
		XtSetArg(args[n], XmNrightAttachment, XmATTACH_FORM); n++;
		XtSetArg(args[n], XmNnavigationType, XmTAB_GROUP); n++;
		text = XmCreateTextField(form, "text", args, n);
		XtManageChild(text);

		XtManageChild(form);
	}

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

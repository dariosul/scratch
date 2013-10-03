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

void create_labeled_textfield(Widget *parent, char *label_string) {
	Widget form_widget;
	Widget label_widget;
	Widget text_widget;
	Arg args[8];
	int n = 0;

	XtSetArg(args[n], XmNfractionBase, 10); n++;
	XtSetArg(args[n], XmNnavigationType, XmNONE); n++;
	form_widget = XmCreateForm(*parent, "form", args, n);

	n = 0;
	XtSetArg(args[n], XmNtopAttachment, XmATTACH_FORM); n++;
	XtSetArg(args[n], XmNbottomAttachment, XmATTACH_FORM); n++;
	XtSetArg(args[n], XmNleftAttachment, XmATTACH_FORM); n++;
	XtSetArg(args[n], XmNrightAttachment, XmATTACH_POSITION); n++;
	XtSetArg(args[n], XmNrightPosition, 3); n++;
	XtSetArg(args[n], XmNalignment, XmALIGNMENT_END); n++;
	XtSetArg(args[n], XmNnavigationType, XmNONE); n++;
	label_widget = XmCreateLabelGadget(form_widget, label_string, args, n);
	XtManageChild(label_widget);

	n = 0;
	XtSetArg(args[n], XmNtraversalOn, True); n++;
	XtSetArg(args[n], XmNleftAttachment, XmATTACH_POSITION); n++;
	XtSetArg(args[n], XmNleftPosition, 4); n++;
	XtSetArg(args[n], XmNrightAttachment, XmATTACH_FORM); n++;
	XtSetArg(args[n], XmNnavigationType, XmTAB_GROUP); n++;
	text_widget = XmCreateTextField(form_widget, "text", args, n);
	XtManageChild(text_widget);

	XtManageChild(form_widget);
}

void update_callback(Widget widget, XtPointer client_data, XtPointer call_data) {
	puts("Update was pressed.");
}

void close_callback(Widget widget, XtPointer client_data, XtPointer call_data) {
	exit(0);
}

int main(int argc, char *argv[]) {

	XtAppContext app;
	Widget root_widget;
	Widget row_column;
	Widget update_button;
	Widget close_button;
	int i;

	void update_callback(Widget, XtPointer, XtPointer);
	void close_callback(Widget, XtPointer, XtPointer);

	XtSetLanguageProc(NULL, NULL, NULL);

	root_widget = XtVaOpenApplication(&app, "Node Info", NULL, 0, &argc,
			argv, NULL, sessionShellWidgetClass, NULL);

	row_column = XmCreateRowColumn(root_widget, "MainRowCol", NULL, 0);

	for (i = 0; i < XtNumber(labels); i++) {
		create_labeled_textfield(&row_column, labels[i]);
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

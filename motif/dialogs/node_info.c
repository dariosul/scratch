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

typedef struct {
	Widget index_widget;
	Widget x_widget;
	Widget y_widget;
	Widget z_widget;
	Widget code_widget;
} NodeInfoWidget;

Widget create_labeled_textfield(Widget *parent, char *label_string) {
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

	return text_widget;
}

void update_callback(Widget widget, XtPointer client_data, XtPointer call_data) {
	puts("Update was pressed.");
	NodeInfoWidget *node_info_widget = (NodeInfoWidget *)client_data;

	puts(XmTextFieldGetString(node_info_widget->index_widget));
	puts(XmTextFieldGetString(node_info_widget->x_widget));
	puts(XmTextFieldGetString(node_info_widget->y_widget));
	puts(XmTextFieldGetString(node_info_widget->z_widget));
	puts(XmTextFieldGetString(node_info_widget->code_widget));
}

void close_callback(Widget widget, XtPointer client_data, XtPointer call_data) {
	exit(0);
}

NodeInfoWidget *create_node_info_widget(Widget *parent) {
	NodeInfoWidget *node_info_widget;

	node_info_widget = (NodeInfoWidget *)malloc(sizeof(NodeInfoWidget));
	node_info_widget->index_widget = create_labeled_textfield(parent, "Index:");
	node_info_widget->x_widget = create_labeled_textfield(parent, "X:");
	node_info_widget->y_widget = create_labeled_textfield(parent, "Y:");
	node_info_widget->z_widget = create_labeled_textfield(parent, "Z:");
	node_info_widget->code_widget = create_labeled_textfield(parent, "Code:");

	return node_info_widget;
}

int main(int argc, char *argv[]) {

	XtAppContext app;
	Widget root_widget;
	Widget row_column;
	Widget update_button;
	Widget close_button;
	NodeInfoWidget *node_info_widget;
	int i;

	void update_callback(Widget, XtPointer, XtPointer);
	void close_callback(Widget, XtPointer, XtPointer);

	XtSetLanguageProc(NULL, NULL, NULL);

	root_widget = XtVaOpenApplication(&app, "Node Info", NULL, 0, &argc,
			argv, NULL, sessionShellWidgetClass, NULL);

	row_column = XmCreateRowColumn(root_widget, "MainRowCol", NULL, 0);

	node_info_widget = create_node_info_widget(&row_column);

	update_button = XmCreatePushButton(row_column, "Update", NULL, 0);
	XtAddCallback(update_button, XmNactivateCallback, update_callback,
			node_info_widget);

	close_button = XmCreatePushButton(row_column, "Close", NULL, 0);
	XtAddCallback(close_button, XmNactivateCallback, close_callback, NULL);

	XtManageChild(update_button);
	XtManageChild(close_button);
	XtManageChild(row_column);

	XtRealizeWidget(root_widget);
	XtAppMainLoop(app);

	free(node_info_widget);

	return 0;
}

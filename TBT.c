#include <ansi_c.h>
#include <rs232.h>
#include <cvirte.h>		
#include <userint.h>
#include "TBT.h"

static int panelHandle;
static int openedComPort;
static int openComPortStatus=0;
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "TBT.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
		}
	return 0;
}

int CVICALLBACK OnOpenComPortPressed (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	int selectedComPort=0;
	int error=0;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PANEL,PANEL_COMPORTLISTS,&selectedComPort);
			error=OpenComConfig(selectedComPort,"",9600,0,8,1,512,512);
			if(error>=0){
				SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,"Com Port Opened \n");
				openComPortStatus=1;
				SetCtrlAttribute(PANEL,PANEL_OPENBUTTON,ATTR_DIMMED,1);
				SetCtrlAttribute(PANEL,PANEL_CLOSEBUTTON,ATTR_DIMMED,0);
				openedComPort=selectedComPort;
				
				
			}
			else if(error<0){
				SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,"Com Port fail open\n");
				SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,GetRS232ErrorString(error));
				SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,"\n");
				
				
				
			}
			break;
		}
	return 0;
}

int CVICALLBACK OnCloseComPortPressed (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	int closeComPortError=0;
	switch (event)
		{
		case EVENT_COMMIT:
			if(openComPortStatus==1){
				closeComPortError=CloseCom(openedComPort);
				
				if(closeComPortError>=0){
				   	openComPortStatus=0;
				   	SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,"Com Port Closed \n");
				   	SetCtrlAttribute(PANEL,PANEL_OPENBUTTON,ATTR_DIMMED,0);
					SetCtrlAttribute(PANEL,PANEL_CLOSEBUTTON,ATTR_DIMMED,1);
				}
				else{
				
				   	SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,"Com Port fail open \n");
					SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,GetRS232ErrorString(closeComPortError));
					SetCtrlVal(PANEL,PANEL_COMPORTSTATUS,"\n"); 
				
				}
			}
			break;
		}
	return 0;
}
int CVICALLBACK sendButton (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	int buttonState=0;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PANEL,PANEL_INSTROCTIONLIST,&buttonState);
			if(openComPortStatus==1){
				if(buttonState==1){
					ComWrt(openedComPort,"1",2);
				}
				else if(buttonState==-1){
					ComWrt(openedComPort,"-1",2);
				}
				
			}
			break;
		}
	return 0;
}

int CVICALLBACK ForMeasurementDepthOkCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	int buttonState=0;
	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(PANEL,PANEL_DEPTHLIST,&buttonState);
			if(openComPortStatus==1){
				if(buttonState==40){
					ComWrt(openedComPort,"40",3);
				}
				else if(buttonState==20){
					ComWrt(openedComPort,"20",3);
				}
				else if(buttonState==10){
					ComWrt(openedComPort,"10",3);
				}
				
			}
			break;
		}
	return 0;
}



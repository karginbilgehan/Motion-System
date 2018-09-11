/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2018. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/
#include <userint.h>
#ifdef __cplusplus
    
	extern "C" {
#endif
	/* Panels and Controls: */
#define  PANEL                           1
#define  PANEL_QUITBUTTON                2       /* callback function: QuitCallback */
#define  PANEL_DECORATION                3
#define  PANEL_COMPORTLISTS              4
#define  PANEL_OPENBUTTON                5       /* callback function: OnOpenComPortPressed */
#define  PANEL_CLOSEBUTTON               6       /* callback function: OnCloseComPortPressed */
#define  PANEL_COMPORTSTATUS             7
#define  PANEL_INSTROCTIONLIST           8
#define  PANEL_SENDBUTTON                9       /* callback function: sendButton */
#define  PANEL_DEPTHLIST                 10
#define  PANEL_OKBUTTON                  11      /* callback function: ForMeasurementDepthOkCallback */
#define  PANEL_TEXTMSG                   12
#define  PANEL_DECORATION_2              13
		/* Menu Bars, Menus, and Menu Items: */
			/* (no menu bars in the resource file) */
		/* Callback Prototypes: */ 

int  CVICALLBACK ForMeasurementDepthOkCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnCloseComPortPressed(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnOpenComPortPressed(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK sendButton(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

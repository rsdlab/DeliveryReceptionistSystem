// -*- C++ -*-
/*!
 * @file  Scale_EJ.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "Scale_EJ.h"
#include<stdio.h>

#include<windows.h>
#include<string.h>
#include<iostream>
#include <sstream>
std::ostringstream intos, decos;

HANDLE EJ_zero;
HANDLE EJ;
BYTE In[4092];
DWORD Readbytes = 17;
DWORD lRead;
int  itemp;



// Module specification
// <rtc-template block="module_spec">
static const char* scale_ej_spec[] =
  {
    "implementation_id", "Scale_EJ",
    "type_name",         "Scale_EJ",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.COM_Port", "COM5",

    // Widget
    "conf.__widget__.COM_Port", "text",
    // Constraints

    "conf.__type__.COM_Port", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Scale_EJ::Scale_EJ(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_WeightOut("Weight", m_Weight)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Scale_EJ::~Scale_EJ()
{
}



RTC::ReturnCode_t Scale_EJ::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("Weight", m_WeightOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("COM_Port", m_COM_Port, "COM5");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

BYTE Scale_EJ::ReceiveData() {
	std::string COMPort = "\\\\.\\" + m_COM_Port;
	EJ = CreateFile(
		(LPCSTR)COMPort.c_str(),//"\\\\.\\COM5",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		0
		);

	if (EJ == INVALID_HANDLE_VALUE)
	{
		std::cout << "Port could not open" << std::endl;
		return -1;
	}
	std::cout << "Port open" << std::endl;
	int EJRET = SetupComm(EJ, 2048, 2048);
	if (EJRET == FALSE)
	{
		printf("SetupComm failed\n");
		CloseHandle(EJ);
		return -1;
	}
	//std::cout << "debug1" << std::endl;
	PurgeComm(EJ, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	//std::cout << "debug2" << std::endl;
	DCB dcb;
	GetCommState(EJ, &dcb);
	dcb.BaudRate = 2400;
	dcb.fNull = 1;
	dcb.ByteSize = 7;
	dcb.fParity = EVENPARITY;
	dcb.StopBits = ONESTOPBIT;

	//std::cout << "debug3" << std::endl;
	SetCommState(EJ, &dcb);
	//std::cout << "debug4" << std::endl;


	char Cmd[3] = { 0x51, 0x0d, 0x0a };

	DWORD Cmdbytes;


	//std::cout << "debug5" << std::endl;
	WriteFile(EJ, Cmd, 3, &Cmdbytes, NULL);
	//std::cout << "debug6" << std::endl;



	int Ret = ReadFile(
		EJ,
		In,
		Readbytes,
		&lRead,
		NULL
		);

	//int Ret;
	//std::cout << "debug7" << std::endl;
	PurgeComm(EJ, PURGE_RXCLEAR);
	if (Ret = 0)     //失敗した場合
	{
		std::cout << "ReadFile failed" << std::endl;
		CloseHandle(EJ);
		return -1;
	}
	//std::cout << "debug8" << std::endl;
	CloseHandle(EJ);
	//std::cout << "debug9" << std::endl;
	return 0;
}


/*
RTC::ReturnCode_t Scale_EJ::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Scale_EJ::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Scale_EJ::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Scale_EJ::onActivated(RTC::UniqueId ec_id)
{
	std::string COMPort = "\\\\.\\" + m_COM_Port;
	//BYTE Success;

	EJ_zero = CreateFile(
		(LPCSTR)COMPort.c_str(),//"\\\\.\\COM5",				 //どのポートを開くのか
		GENERIC_READ | GENERIC_WRITE, //アクセスモード,通常送受信ともするので読書き両方を指定
		0,					//共有モード：　通常0に設定　再オープン禁止
		NULL,				//セキュリティアトリビュート：通信では通常NULLに設定　
		OPEN_EXISTING,		//クリエイトﾃﾞｨｽﾄﾘビューション：通常COMポートはすでに存在しているのでOPEN_EXISTINGとします。
		FILE_ATTRIBUTE_NORMAL,	//属性：通信の場合属性はないのでFILE_ATTRIBUTE_NORMAL（属性なし）を指定　
		0				//テンプレートのハンドル：　通信の場合関係ない　通常NULLを指定
		);

	int EJRET = SetupComm(EJ_zero, 2048, 2048);
	if (EJRET == FALSE)
	{
		printf("SetupComm failed.\n");
		CloseHandle(EJ_zero);

	}

	EJRET = PurgeComm(EJ_zero, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	DCB dcb;
	GetCommState(EJ_zero, &dcb);
	dcb.BaudRate = 2400;
	dcb.fBinary = 1;
	dcb.ByteSize = 7;
	dcb.fParity = EVENPARITY;
	dcb.StopBits = ONESTOPBIT;


	SetCommState(EJ_zero, &dcb);


	char zeroCmd[3] = { 0x5a, 0x0d, 0x0a };
	DWORD ZEROCmdbytes;

	WriteFile(EJ_zero, zeroCmd, 3, &ZEROCmdbytes, NULL);

	std::cout << "Zero Clear" << std::endl;

	CloseHandle(EJ_zero);
	Sleep(500);

  return RTC::RTC_OK;
}


RTC::ReturnCode_t Scale_EJ::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Scale_EJ::onExecute(RTC::UniqueId ec_id)
{
	BYTE Success = 0;
	for (int i = 0; i < sizeof(In); i++)
	{
		In[i] = 0x00;
	}
	//std::cout << "レシーブ" << std::endl;
	Success = ReceiveData();
	//std::cout << "レシーブ2" << std::endl;
	if (Success == 0)
	{

		std::cout << "ReceiveData=" << In[0];
		std::cout << In[1];
		std::cout << In[2];
		std::cout << In[3];
		std::cout << In[4];
		std::cout << In[5];
		std::cout << In[6];
		std::cout << In[7];
		std::cout << In[8];
		std::cout << In[9];
		std::cout << In[10];
		std::cout << In[11];
		std::cout << In[12];
		std::cout << In[13];
		std::cout << In[14];
		std::cout << In[15] << std::endl;


		if (In[0] == 'S' && In[1] == 'T' && In[14] == 'g'){

			int flag = 0;
			intos.str("");
			intos.clear(std::ostringstream::goodbit);
			decos.str("");
			decos.clear(std::ostringstream::goodbit);
			std::string out_data = "";
			for (int i = 3; i <= 11; i++){

				intos << In[i];
			}
			double Value_data = std::stod(intos.str());

			/*for (int i = 4; i <= 11; i++){//回りくどいやり方
			if (In[i]!='.'){
			if (flag == 0){
			intos << In[i]; // 整数部連結
			}
			else
			{
			decos << In[i]; // 小数部連結
			}
			}
			else
			{
			flag = 1;
			}
			}
			if (In[3] == '+'){
			out_data ='+'+intos.str()+'.'+decos.str();
			}
			else{
			out_data = '-' + intos.str() + '.' + decos.str();
			}


			double Value_data = std::stod(out_data);
			*/
			std::cout << Value_data << " g" << std::endl;
			m_Weight.data = Value_data;
			m_WeightOut.write();

		}

	}

	//Sleep(100);

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Scale_EJ::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Scale_EJ::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Scale_EJ::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Scale_EJ::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Scale_EJ::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Scale_EJInit(RTC::Manager* manager)
  {
    coil::Properties profile(scale_ej_spec);
    manager->registerFactory(profile,
                             RTC::Create<Scale_EJ>,
                             RTC::Delete<Scale_EJ>);
  }
  
};



// -*- C++ -*-
/*!
 * @file  DeliveryManager.cpp
 * @brief DeliveryManager
 * @date $Date$
 *
 * $Id$
 */

#include "DeliveryManager.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <mbstring.h>
#include <string.h>

// ESC�̃L�[�R�[�h
#define ESC 0x1B

// Module specification
// <rtc-template block="module_spec">
static const char* deliverymanager_spec[] =
  {
    "implementation_id", "DeliveryManager",
    "type_name",         "DeliveryManager",
    "description",       "DeliveryManager",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.CurrentAddress", "Aichi",

    // Widget
    "conf.__widget__.CurrentAddress", "text",
    // Constraints

    "conf.__type__.CurrentAddress", "string",

    ""
  };
// </rtc-template>
std::string talk_FeeData;
std::string talk_FeeDataA;
std::string talk_FeeDataB;
std::string talk_FeeDataC;
std::string talk_DayData;
std::string talk_DayDataA;
std::string talk_DayDataB;
std::string talk_DayDataC;
std::string talk_thanks;
std::string talk_guide;
DeriveryDatabase::DeliveryData Del_data;
DeriveryDatabase::FeeAndDay FeeDayData;
PrintDelivery::PrintData Pri_data;

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
DeliveryManager::DeliveryManager(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_ObjectPropertyIn("ObjectProperty", m_ObjectProperty),
    m_guidetextOut("text", m_guidetext),
    m_DeliveryDatabaseInterfacePort("DeliveryDatabaseInterface"),
    m_PrintDeliveryInterfacePort("PrintDeliveryInterface")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DeliveryManager::~DeliveryManager()
{
}



RTC::ReturnCode_t DeliveryManager::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("ObjectProperty", m_ObjectPropertyIn);
  
  // Set OutPort buffer
  addOutPort("text", m_guidetextOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_DeliveryDatabaseInterfacePort.registerConsumer("DeliveryDatabaseInterface", "DeriveryDatabase::DeriveryDatabaseInterface", m_DeliveryDatabaseInterface);
  m_PrintDeliveryInterfacePort.registerConsumer("PrintDeliveryInterface", "PrintDelivery::PrintDeriveryInterface", m_PrintDeliveryInterface);
  
  // Set CORBA Service Ports
  addPort(m_DeliveryDatabaseInterfacePort);
  addPort(m_PrintDeliveryInterfacePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("CurrentAddress", m_CurrentAddress, "Aichi");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DeliveryManager::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryManager::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryManager::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t DeliveryManager::onActivated(RTC::UniqueId ec_id)
{
	std::string CurrentAddress;
	//47�s���{���̐錾
	std::string Hokkaido = "Hokkaido";
	std::string Aomori = "Aomori";
	std::string Iwate = "Iwate";
	std::string Akita = "Akita";
	std::string Miyagi = "Miyagi";
	std::string Yamagata = "Yamagata";
	std::string Fukushima = "Fukushima";
	std::string Niigata = "Niigata";
	std::string Ibaraki = "Ibaraki";
	std::string Chiba = "Chiba";
	std::string Tochigi = "Tochigi";
	std::string Gumma = "Gumma";
	std::string Saitama = "Saitama";
	std::string Tokyo = "Tokyo";
	std::string Kanagawa = "Kanagawa";
	std::string Shizuoka = "Shizuoka";
	std::string Yamanashi = "Yamanashi";
	std::string Nagano = "Nagano";
	std::string Toyama = "Toyama";
	std::string Isikawa = "Ishikawa";
	std::string Fukui = "Fukui";
	std::string Gifu = "Gifu";
	std::string Aichi = "Aichi";
	std::string Mie = "Mie";
	std::string Shiga = "Shiga";
	std::string Kyoto = "Kyoto";
	std::string Osaka = "Osaka";
	std::string Nara = "Nara";
	std::string Wakayama = "Wakayama";
	std::string Hyogo = "Hyogo";
	std::string Tottori = "Tottori";
	std::string Okayama = "Okayama";
	std::string Shimane = "Shimane";
	std::string Hiroshima = "Hiroshima";
	std::string Yamaguchi = "Yamaguchi";
	std::string Kagawa = "Kagawa";
	std::string Tokushima = "Tokushima";
	std::string Ehime = "Ehime";
	std::string Kochi = "Kochi";
	std::string Fukuoka = "Fukuoka";
	std::string Saga = "Saga";
	std::string Nagasaki = "Nagasaki";
	std::string Oita = "Oita";
	std::string Kumamoto = "Kumaoto";
	std::string Miyazaki = "Miyazaki";
	std::string Kagoshima = "Kagoshima";
	std::string Okinawa = "Okinawa";

	if (strstr(m_CurrentAddress.c_str(), Hokkaido.c_str()) != NULL)
	{
		std::cout << "���茳�F�k�C��" << std::endl;
		Del_data.address = "�k�C��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Aomori.c_str()) != NULL)
	{
		std::cout << "���茳�F�X��" << std::endl;
		Del_data.address = "�X��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Iwate.c_str()) != NULL)
	{
		std::cout << "���茳�F��茧" << std::endl;
		Del_data.address = "��茧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Miyagi.c_str()) != NULL)
	{
		std::cout << "���茳�F�{�錧" << std::endl;
		Del_data.address = "�{�錧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Akita.c_str()) != NULL)
	{
		std::cout << "���茳�F�H�c��" << std::endl;
		Del_data.address = "�H�c��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Yamagata.c_str()) != NULL)
	{
		std::cout << "���茳�F�R�`��" << std::endl;
		Del_data.address = "�R�`��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Fukushima.c_str()) != NULL)
	{
		std::cout << "���茳�F������" << std::endl;
		Del_data.address = "������";
	}
	else if (strstr(m_CurrentAddress.c_str(), Ibaraki.c_str()) != NULL)
	{
		std::cout << "���茳�F��錧" << std::endl;
		Del_data.address = "��錧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tochigi.c_str()) != NULL)
	{
		std::cout << "���茳�F�Ȗ،�" << std::endl;
		Del_data.address = "�Ȗ،�";
	}
	else if (strstr(m_CurrentAddress.c_str(), Gumma.c_str()) != NULL)
	{
		std::cout << "���茳�F�Q�n��" << std::endl;
		Del_data.address = "�Q�n��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Saitama.c_str()) != NULL)
	{
		std::cout << "���茳�F��ʌ�" << std::endl;
		Del_data.address = "��ʌ�";
	}
	else if (strstr(m_CurrentAddress.c_str(), Chiba.c_str()) != NULL)
	{
		std::cout << "���茳�F��t��" << std::endl;
		Del_data.address = "��t��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tokyo.c_str()) != NULL)
	{
		std::cout << "���茳�F�����s" << std::endl;
		Del_data.address = "�����s";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kanagawa.c_str()) != NULL)
	{
		std::cout << "���茳�F�_�ސ쌧" << std::endl;
		Del_data.address = "�_�ސ쌧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Niigata.c_str()) != NULL)
	{
		std::cout << "���茳�F�V����" << std::endl;
		Del_data.address = "�V����";
	}
	else if (strstr(m_CurrentAddress.c_str(), Toyama.c_str()) != NULL)
	{
		std::cout << "���茳�F�x�R��" << std::endl;
		Del_data.address = "�x�R��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Isikawa.c_str()) != NULL)
	{
		std::cout << "���茳�F�ΐ쌧" << std::endl;
		Del_data.address = "�ΐ쌧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Fukui.c_str()) != NULL)
	{
		std::cout << "���茳�F���䌧" << std::endl;
		Del_data.address = "���䌧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Yamanashi.c_str()) != NULL)
	{
		std::cout << "���茳�F�R����" << std::endl;
		Del_data.address = "�R����";
	}
	else if (strstr(m_CurrentAddress.c_str(), Nagano.c_str()) != NULL)
	{
		std::cout << "���茳�F���쌧" << std::endl;
		Del_data.address = "���쌧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Gifu.c_str()) != NULL)
	{
		std::cout << "���茳�F�򕌌�" << std::endl;
		Del_data.address = "�򕌌�";
	}
	else if (strstr(m_CurrentAddress.c_str(), Shizuoka.c_str()) != NULL)
	{
		std::cout << "���茳�F�É���" << std::endl;
		Del_data.address = "�É���";
	}
	else if (strstr(m_CurrentAddress.c_str(), Aichi.c_str()) != NULL)
	{
		std::cout << "���茳�F���m��" << std::endl;
		Del_data.address = "���m��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Mie.c_str()) != NULL)
	{
		std::cout << "���茳�F�O�d��" << std::endl;
		Del_data.address = "�O�d��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Shiga.c_str()) != NULL)
	{
		std::cout << "���茳�F���ꌧ" << std::endl;
		Del_data.address = "���ꌧ";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kyoto.c_str()) != NULL)
	{
		std::cout << "���茳�F���s�{" << std::endl;
		Del_data.address = "���s�{";
	}
	else if (strstr(m_CurrentAddress.c_str(), Osaka.c_str()) != NULL)
	{
		std::cout << "���茳�F���{" << std::endl;
		Del_data.address = "���{";
	}
	else if (strstr(m_CurrentAddress.c_str(), Hyogo.c_str()) != NULL)
	{
		std::cout << "���茳�F���Ɍ�" << std::endl;
		Del_data.address = "���Ɍ�";
	}
	else if (strstr(m_CurrentAddress.c_str(), Nara.c_str()) != NULL)
	{
		std::cout << "���茳�F�ޗǌ�" << std::endl;
		Del_data.address = "�ޗǌ�";
	}
	else if (strstr(m_CurrentAddress.c_str(), Wakayama.c_str()) != NULL)
	{
		std::cout << "���茳�F�a�̎R��" << std::endl;
		Del_data.address = "�a�̎R��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tottori.c_str()) != NULL)
	{
		std::cout << "���茳�F���挧" << std::endl;
		Del_data.address = "���挧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Okayama.c_str()) != NULL)
	{
		std::cout << "���茳�F���R��" << std::endl;
		Del_data.address = "���R��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Hiroshima.c_str()) != NULL)
	{
		std::cout << "���茳�F�L����" << std::endl;
		Del_data.address = "�L����";
	}
	else if (strstr(m_CurrentAddress.c_str(), Yamaguchi.c_str()) != NULL)
	{
		std::cout << "���茳�F�R����" << std::endl;
		Del_data.address = "�R����";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tokushima.c_str()) != NULL)
	{
		std::cout << "���茳�F������" << std::endl;
		Del_data.address = "������";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kagawa.c_str()) != NULL)
	{
		std::cout << "���茳�F���쌧" << std::endl;
		Del_data.address = "���쌧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Ehime.c_str()) != NULL)
	{
		std::cout << "���茳�F���Q��" << std::endl;
		Del_data.address = "���Q��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kochi.c_str()) != NULL)
	{
		std::cout << "���茳�F���m��" << std::endl;
		Del_data.address = "���m��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Fukuoka.c_str()) != NULL)
	{
		std::cout << "���茳�F������" << std::endl;
		Del_data.address = "������";
	}
	else if (strstr(m_CurrentAddress.c_str(), Saga.c_str()) != NULL)
	{
		std::cout << "���茳�F���ꌧ" << std::endl;
		Del_data.address = "���ꌧ";
	}
	else if (strstr(m_CurrentAddress.c_str(), Nagasaki.c_str()) != NULL)
	{
		std::cout << "���茳�F���茧" << std::endl;
		Del_data.address = "���茧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kumamoto.c_str()) != NULL)
	{
		std::cout << "���茳�F�F�{��" << std::endl;
		Del_data.address = "�F�{��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Oita.c_str()) != NULL)
	{
		std::cout << "���茳�F�啪��" << std::endl;
		Del_data.address = "�啪��";
	}
	else if (strstr(m_CurrentAddress.c_str(), Miyazaki.c_str()) != NULL)
	{
		std::cout << "���茳�F�{�茧" << std::endl;
		Del_data.address = "�{�茧";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kagoshima.c_str()) != NULL)
	{
		std::cout << "���茳�F��������" << std::endl;
		Del_data.address = "��������";
	}
	else if (strstr(m_CurrentAddress.c_str(), Okinawa.c_str()) != NULL)
	{
		std::cout << "���茳�F���ꌧ" << std::endl;
		Del_data.address = "���ꌧ";
	}
	else
	{
		std::cout << "���{�̓s���{���ȊO�����͂���܂���" << std::endl;
		return RTC::RTC_ERROR;
	}

	m_ObjectProperty.data.length(5);

	Del_data.option.length(9);
	Pri_data.option.length(9);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DeliveryManager::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DeliveryManager::onExecute(RTC::UniqueId ec_id)
{

	char sendPCord[32];/*�����X�֔ԍ�*/
	char sendAddress[1024];/*�����Z��*/
	char PCord[32];/*�˗���X�֔ԍ�*/
	char address[1024];/*�˗���Z��*/
	char sendName[32];/*����掁��*/
	char name[32];/*�˗��厁��*/
	char objectName[128];/*�i����*/
	char option[32];/*�I�v�V������*/
	//�I�v�V�������錾
	char s2[] = ",�C";  /* �J���}�̂� */
	char *tok;
	char *next_token1 = NULL;
	int optionFlag[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };/*flag0:���B,flag1:�������,flag2:�①,flag3:�Ⓚ,flag4:��������,flag5:��ʏ���,flag6:�ȈՏ���,flag7:�{�l������,flag8:�I�v�V�������� */
	int optionCount = 0;/*����:0�@�I�v�V���������Ƃق��̃I�v�V�����̑��d�o�^�֎~�̊Ǘ��t���O*/
	int freezeFlag = 0;/*�①,�Ⓚ��2�d�o�^�֎~�̊Ǘ��t���O*/
	int kakitomeFlag = 0;/*�e�폑����2�d�o�^�֎~�̊Ǘ��t���O*/
	int exitFlag = 0;/*1�̂Ƃ����[�v�E�o*/
	char optionWord[9][24] =
	{
		{ "�I�v�V��������" }, { "���B" }, { "�������" }, { "�①" }, { "�Ⓚ" }, { "��������" }, { "��ʏ���" }, { "�ȈՏ���" }, { "�{�l����󂯎��(�e�W)" }
	};

	int beepHz = 4000;//[Hz]
	int beepTime = 400;//[ms]

	char flag1[32];
	char flag2[32];
	char finalCheckflag[32];
	/*
	sendDATA[0]...sendPCord
	sendDATA[1]...sendAddress
	sendDATA[2]...semdName
	sendDATA[3]...PCord
	sendDATA[4]...address
	sendDATA[5]...name
	sendDATA[6]...objectname
	sendDATA[7]...option
	sendDATA[8]...
	sendDATA[9]...

	*/

	printf_s("��������Ⴂ�܂�\n�ē����J�n���邽�߂ɂ�Enter�L�[�������Ă�������\n");
	talk_guide = "��������Ⴂ�܂��A�ē����J�n���邽�߂ɂ̓G���^�[�L�[�������Ă�������";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	while (!_kbhit());
	/*
	{
		if (!kbhit() || (getch() != ESC))
		{
			deactivate(ec_id);
		}
		else
		{
			break;
		}

	}
	*/
	//=============����������========================================================================================================
	printf_s("�y���͂���̎����ƏZ���̓��́z\n");
	printf_s("���͂���̎�������͂��ĉ������F");
	talk_guide = "���͂���̎�������͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", sendName, 32);

	printf_s("���͂���̗X�֔ԍ�����͂��ĉ�����\n(�n�C�t��������7�����̐����œ��͂��ĉ�����)�F\n");
	talk_guide = "���͂���̗X�֔ԍ�����͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", sendPCord, 32);

	printf_s("���͂���̏Z������͂��ĉ������F\n");
	talk_guide = "���͂���̏Z������͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", sendAddress, 1024);

	while (1)
	{
		printf_s("\n�y���͂���̏����m�F���Ă��������z\n=======================================================================\n");

		printf_s("���͂��掁��:�@%s\n���͂���X�֔ԍ�:�@%s\n���͂���Z��:�@%s\n", sendName, sendPCord, sendAddress);
		printf_s("=======================================================================\n\n�@���͂�����ɊԈႢ���Ȃ����ɐi�ށ�1�����\n�y���͏��̏C���z�������ӏ��̏C���͂P���s���Ă��������B\n�@���͂��掁���̕ύX��2�����\n�@���͂���X�֔ԍ��̕ύX��3�����\n�@���͂���Z���̕ύX��4�����\n");
		talk_guide = "���͂���̏����m�F���Ă�������";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		while (1)
		{
			printf_s("\n(1, 2, 3, 4)�������͂��ĉ������B\n�ԍ�����:�@");
			scanf_s("%s", flag1, 32);

			if (_ismbblead(flag1[0]) == 0)
			{

			}
			else
			{
				char origin[32];
				char  converted[32];
				strcpy_s(origin, flag1);
				LCMapString(LOCALE_SYSTEM_DEFAULT, LCMAP_HALFWIDTH, origin, 32, converted, 32);
				strcpy_s(flag1, converted);
			}

			if (strcmp(flag1, "1") == 0 || strcmp(flag1, "2") == 0 || strcmp(flag1, "3") == 0 || strcmp(flag1, "4") == 0)
			{
				break;
			}
			else
			{
				talk_guide = "���͂��Ԉ���Ă��܂��B";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("���͂��Ԉ���Ă��܂�\n");
				Sleep(2);
			}

		}

		if (strcmp(flag1, "1") == 0)
		{
			while (1)
			{
				printf_s("===���ɐi��ő��v�ł����H===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
				talk_guide = "���ɐi��ő��v�ł����H ��낵����� y ���A�@�C������ꍇ�� n �������Ă�������";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				scanf_s("%s", flag2, 32);
				if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
				{
					break;
				}
				else
				{
					talk_guide = "���͂��Ԉ���Ă��܂��B";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					m_guidetextOut.write();
					//Beep(beepHz, beepTime);
					//Sleep(100);
					//Beep(beepHz, beepTime);
					printf_s("���͂��Ԉ���Ă��܂�\n");
					Sleep(2000);
				}
			}
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
			{
				break;
			}

		}
		else if (strcmp(flag1, "2") == 0)
		{
			printf_s("�y���͂���̎������ē��́z\n���݂̓��͎���:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n", sendName);
			scanf_s("%s", sendName, 32);
		}
		else if (strcmp(flag1, "3") == 0)
		{
			printf_s("�y���͂���̗X�֔ԍ����ē��́z\n���݂̓��͗X�֔ԍ�:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n(�n�C�t��������7�����̐����ōē��͂��ĉ�����)�F\n", sendPCord);
			scanf_s("%s", sendPCord, 32);
		}
		else if (strcmp(flag1, "4") == 0)
		{
			printf_s("�y���͂���̏Z�����ē��́z\n���݂̓��͏Z��:�@%s\n�ύX��̏Z�����ē��͂��ĉ�����:\n", sendAddress);
			scanf_s("%s", sendAddress, 1024);
		}
	}
	//===================================================================================================================================


	//=============�˗��ҏ�����========================================================================================================
	printf_s("�@\n�y���˗���̎����ƏZ���̓��́z\n");
	printf_s("���˗���̎�������͂��ĉ������F\n");
	talk_guide = "���˗���̎�������͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", name, 32);

	printf_s("���˗���̗X�֔ԍ�����͂��ĉ�����\n(�n�C�t��������7�����̐����œ��͂��ĉ�����)�F\n");
	talk_guide = "���˗���̗X�֔ԍ�����͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", PCord, 32);

	printf_s("���˗���̏Z������͂��ĉ������F\n");
	talk_guide = "���˗���̏Z������͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", address, 1024);

	while (1)
	{
		printf_s("�@\n�y���˗���l�̏����m�F���Ă��������z\n=======================================================================\n");

		printf_s("���˗���̎���:�@%s\n���˗���̗X�֔ԍ�:�@%s\n���˗���̏Z��:�@%s\n", name, PCord, address);
		printf_s("=======================================================================\n\n�@���˗���̏��ɊԈႢ���Ȃ����ɐi�ށ�1�����\n�y���͏��̏C���z�������ӏ��̏C���͂P���s���Ă��������B\n�@���˗���̎����̕ύX��2�����\n�@���˗���̗X�֔ԍ��̕ύX��3�����\n�@���˗���̏Z���̕ύX��4�����\n");
		talk_guide = "���˗���l�̏����m�F���Ă�������";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		while (1)
		{
			printf_s("\n(1, 2, 3, 4)�������͂��ĉ������B\n�ԍ�����:�@");
			scanf_s("%s", flag1, 32);

			if (_ismbblead(flag1[0]) == 0)
			{

			}
			else
			{
				char origin[32];
				char  converted[32];
				strcpy_s(origin, flag1);
				LCMapString(LOCALE_SYSTEM_DEFAULT, LCMAP_HALFWIDTH, origin, 32, converted, 32);
				strcpy_s(flag1, converted);
			}

			if (strcmp(flag1, "1") == 0 || strcmp(flag1, "2") == 0 || strcmp(flag1, "3") == 0 || strcmp(flag1, "4") == 0)
			{
				break;
			}
			else
			{
				talk_guide = "���͂��Ԉ���Ă��܂��B";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("���͂��Ԉ���Ă��܂�\n");
				Sleep(2000);
			}

		}

		if (strcmp(flag1, "1") == 0)
		{
			while (1)
			{
				printf_s("===���ɐi��ő��v�ł����H===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
				talk_guide = "���ɐi��ő��v�ł����H ��낵����� y ���A�@�C������ꍇ�� n �������Ă�������";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				scanf_s("%s", flag2, 32);
				if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
				{
					break;
				}
				else
				{
					talk_guide = "���͂��Ԉ���Ă��܂��B";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					//Beep(beepHz, beepTime);
					//Sleep(100);
					//Beep(beepHz, beepTime);
					printf_s("���͂��Ԉ���Ă��܂�\n");
					Sleep(2000);
				}
			}
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
			{
				break;
			}

		}
		else if (strcmp(flag1, "2") == 0)
		{
			printf_s("�y���˗���̎������ē��́z\n���݂̓��͎���:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n", name);
			scanf_s("%s", name, 32);
		}
		else if (strcmp(flag1, "3") == 0)
		{
			printf_s("�y���˗���̗X�֔ԍ����ē��́z\n���݂̓��͗X�֔ԍ�:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n(�n�C�t��������7�����̐����ōē��͂��ĉ�����)�F\n", PCord);
			scanf_s("%s", PCord, 32);
		}
		else if (strcmp(flag1, "4") == 0)
		{
			printf_s("�y���˗���̏Z�����ē��́z\n���݂̓��͏Z��:�@%s\n�ύX��̏Z�����ē��͂��ĉ�����:\n", address);
			scanf_s("%s", address, 1024);
		}
	}
	//======================================================================================================================================

	//============�i��������========================================================================================================

	printf_s("�@\n�y�i�����̓��́z\n");
	printf_s("�i��������͂��ĉ������F\n");
	talk_guide = "�i��������͂��ĉ�����";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", objectName, 128);
	while (1)
	{
		printf_s(" \n�y�i�������m�F���Ă��������z\n=======================================================================\n");

		printf_s("�i����:�@%s\n", objectName);
		printf_s("=======================================================================\n\n");
		talk_guide = "�i�������m�F���Ă�������";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		while (1){
			printf_s("�i�����ɊԈႢ�͂���܂��񂩁H\n�͂�(���ɐi��)��y, ������(�C������)��n�@����͂��ĉ������B\n����:");
			scanf_s("%s", flag2, 32);
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
			{
				break;
			}
			else
			{
				talk_guide = "���͂��Ԉ���Ă��܂��B";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("���͂��Ԉ���Ă��܂�\n");
				Sleep(2000);
			}
		}
		if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
		{
			break;
		}
		else
		{
			printf_s("�y�i�������ē��́z\n���݂̓��͕i����:�@%s\n�ύX��̕i�������ē��͂��ĉ�����:\n", objectName);
			scanf_s("%s", objectName, 128);
		}

	}

	//======================================================================================================================================

	//============�I�v�V��������========================================================================================================

	while (1)
	{
		if (optionCount == 0)
		{
			printf_s("�y�I�v�V�����̓��́z\n");
		}
		else
		{
			printf_s("\n�@\n�y�I�v�V�����̍ē��́z\n");
			optionCount = 0;
			freezeFlag = 0;
			kakitomeFlag = 0;
			int i = 0;
			while (i < 9)
			{
				optionFlag[i] = 0;
				i++;
			}
		}
		int loopFlag1 = 0;
		while (loopFlag1 < 9)
		{
			int i = loopFlag1;
			printf_s(" �@%s��%d�����\n", optionWord[i], i);
			loopFlag1++;
		}
		printf_s(" �������I���́u,�v�ŋ�؂��ē��͂��Ă�������\n�@�@���͗�:���B,�①,�{�l������(�e�W)���@1,3,8\n");
		printf_s("\n�I�v�V��������͂��ĉ������F");
		talk_guide = "��z���@�̃I�v�V��������͂��ĉ�����";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		scanf_s("%s", option, 32);
		int flag11 = 0;
		tok = strtok_s(option, s2, &next_token1);
		while (tok != NULL)
		{
			char optintype[32];
			if (_ismbblead(tok[0]) == 0)
			{
				strcpy_s(optintype, tok);
			}
			else
			{
				char origin[32];
				char  converted[32];
				strcpy_s(origin, tok);
				LCMapString(LOCALE_SYSTEM_DEFAULT, LCMAP_HALFWIDTH, origin, 32, converted, 32);
				strcpy_s(optintype, converted);
			}
			if (strcmp(optintype, "1") == 0 && optionFlag[1] == 0)
			{
				optionFlag[1] = 1;
				optionCount++;
			}
			if (strcmp(optintype, "2") == 0 && optionFlag[2] == 0)
			{
				optionFlag[2] = 1;
				optionCount++;
			}
			if (strcmp(optintype, "3") == 0 && optionFlag[3] == 0)
			{
				optionFlag[3] = 1;
				optionCount++;
				freezeFlag++;
			}
			if (strcmp(optintype, "4") == 0 && optionFlag[4] == 0)
			{
				optionFlag[4] = 1;
				optionCount++;
				freezeFlag++;
			}
			if (strcmp(optintype, "5") == 0 && optionFlag[5] == 0)
			{
				optionFlag[5] = 1;
				optionCount++;
				kakitomeFlag++;
			}
			if (strcmp(optintype, "6") == 0 && optionFlag[6] == 0)
			{
				optionFlag[6] = 1;
				optionCount++;
				kakitomeFlag++;
			}
			if (strcmp(optintype, "7") == 0 && optionFlag[7] == 0)
			{
				optionFlag[7] = 1;
				optionCount++;
				kakitomeFlag++;
			}
			if (strcmp(optintype, "8") == 0 && optionFlag[8] == 0)
			{
				optionFlag[8] = 1;
				optionCount++;
			}
			if (strcmp(optintype, "0") == 0 && optionFlag[0] == 0)
			{
				optionFlag[0] = 1;
				optionCount = optionCount + 20;
			}
			tok = strtok_s(NULL, s2, &next_token1);
		}
		int  loopFlag2 = 0;
		if (optionCount > 20)
		{
			printf_s("�����I�v�V���������Ƒ��̃I�v�V������2�d�o�^����Ă��܂�����\n�ē��͂��肢���܂��B");
			Sleep(3000);
		}
		else if (freezeFlag > 1)
		{
			printf_s("�����Ⓚ�Ɨ①��2�d�o�^����Ă��܂�����\n�ē��͂��肢���܂��B");
			Sleep(3000);
		}
		else if (kakitomeFlag > 1)
		{
			printf_s("�����e�폑�������d�o�^����Ă��܂�����\n�ē��͂��肢���܂��B");
			Sleep(3000);
		}
		else if (optionCount == 0)
		{
			printf_s("�������������͂���܂��񁦁�\n�ē��͂��肢���܂��B");
			Sleep(3000);
		}
		else
		{
			printf_s(" \n�y�I�v�V�������m�F���Ă��������z\n=======================================================================\n");
			loopFlag2 = 0;
			while (loopFlag2 < 9)
			{
				int i = loopFlag2;
				if (optionFlag[i] == 1)
				{
					printf_s("%d:%s\n", i, optionWord[i]);
				}
				loopFlag2++;
			}
			printf_s("=======================================================================\n\n");
			while (1)
			{
				printf_s("�I�v�V�����ɊԈႢ�͂���܂��񂩁H\n�͂�(���ɐi��)��y, ������(�C������)��n�@����͂��ĉ������B\n����:");
				talk_guide = "�I�v�V�����ɊԈႢ�͂���܂��񂩁H ��낵����� y ���A�@�C������ꍇ�� n �������Ă�������";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				scanf_s("%s", flag2, 32);
				if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
				{
					break;
				}
				else
				{
					talk_guide = "���͂��Ԉ���Ă��܂��B";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					//Beep(beepHz, beepTime);
					//Sleep(100);
					//Beep(beepHz, beepTime);
					printf_s("���͂��Ԉ���Ă��܂�\n");
					Sleep(2000);
				}
			}
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
			{
				exitFlag++;
			}
			else
			{
				exitFlag = 0;
			}
			if (exitFlag == 1)//�E�o����
			{
				break;
			}
		}
	}
	//=========================================================================================================

	//�ŏI�m�F======================================================================================

	while (1)
	{

		printf_s("\n�y���͏��̍ŏI�m�F�z\n================================================\n");
		printf_s("---------(���͂���̏��)---------------------------------------------\n");
		printf_s("�@1:���͂��掁��:�@%s\n", sendName);
		printf_s("�@2:���͂���X�֔ԍ�:�@%s\n�@3:���͂���Z��:�@%s\n", sendPCord, sendAddress);
		printf_s("---------(���˗���l�̏��)-------------------------------------------\n");
		printf_s("�@4:���˗���̎���:�@%s\n�@5:���˗���̗X�֔ԍ�:�@%s\n�@6:���˗���̏Z��:�@%s\n", name, PCord, address);
		printf_s("---------(�i�����̏��)-----------------------------------------------\n");
		printf_s("�@7:�i����:�@%s\n", objectName);
		printf_s("---------(�I�v�V�������)---------------------------------------------\n");
		printf_s("�@8:\n");
		talk_guide = "���͏��̍ŏI�m�F�����܂��B�ԈႢ������΁A�Ή������L�[�������ďC�����Ă��������B";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		int loopFlag3 = 0;
		while (loopFlag3 < 9)
		{
			int i = loopFlag3;
			if (optionFlag[i] == 1)
			{
				printf_s("�@�@%s\n", optionWord[i]);
			}
			loopFlag3++;
		}
		printf_s("=======================================================================\n\n�@ ���͏��ɊԈႢ���Ȃ����ɐi�ށ�0�����\n \n�y���͏��̏C���z�������ӏ��̏C���͂P���s���Ă��������B\n");
		printf_s("�@���˗���̎����̕ύX��1�����\n�@���˗���̗X�֔ԍ��̕ύX��2�����\n�@���˗���̏Z���̕ύX��3�����\n");
		printf_s("���˗���̎����̕ύX��4�����\n�@���˗���̗X�֔ԍ��̕ύX��5�����\n�@���˗���̏Z���̕ύX��6�����\n");
		printf_s("�i�����̕ύX��7�����\n");
		printf_s("�I�v�V�����̕ύX��8�����");

		while (1)
		{
			printf_s("\n(0, 1, 2, 3, 4, 5, 6, 7, 8)�������͂��ĉ������B\n�ԍ�����:�@");
			scanf_s("%s", finalCheckflag, 32);

			if (_ismbblead(finalCheckflag[0]) == 0)
			{

			}
			else
			{
				char origin[32];
				char  converted[32];
				strcpy_s(origin, finalCheckflag);
				LCMapString(LOCALE_SYSTEM_DEFAULT, LCMAP_HALFWIDTH, origin, 32, converted, 32);
				strcpy_s(finalCheckflag, converted);
			}

			if (strcmp(finalCheckflag, "0") == 0 || strcmp(finalCheckflag, "1") == 0 || strcmp(finalCheckflag, "2") == 0 || strcmp(finalCheckflag, "3") == 0 || strcmp(finalCheckflag, "4") == 0 || strcmp(finalCheckflag, "5") == 0 || strcmp(finalCheckflag, "6") == 0 || strcmp(finalCheckflag, "7") == 0 || strcmp(finalCheckflag, "8") == 0)
			{
				break;
			}
			else
			{
				talk_guide = "���͂��Ԉ���Ă��܂��B";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("���͂��Ԉ���Ă��܂�\n");
				Sleep(2000);
			}

		}
		// �ȉ����C�����Ē���flag������L�ڂŏI���\��
		if (strcmp(finalCheckflag, "0") == 0)/*�ύX�����ŏI��*/
		{
			//std::cout << "	debug1 " << std::endl;
			break;
		}
		if (strcmp(finalCheckflag, "1") == 0)/*���˗���̎����̕ύX*/
		{

			while (1)
			{
				int outFlag = 0;
				printf_s("�y���͂���̎������ē��́z\n���݂̓��͎���:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n", sendName);
				scanf_s("%s", sendName, 32);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̎���:%s\n", sendName);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "2") == 0)/*���˗���̗X�֔ԍ��̕ύX*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("�y���͂���̗X�֔ԍ����ē��́z\n���݂̓��͗X�֔ԍ�:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n(�n�C�t��������7�����̐����ōē��͂��ĉ�����)�F\n", sendPCord);
				scanf_s("%s", sendPCord, 32);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̗X�֔ԍ�:%s\n", sendPCord);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "3") == 0)/*���˗���̏Z���̕ύX*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("�y���͂���̏Z�����ē��́z\n���݂̓��͏Z��:�@%s\n�ύX��̏Z�����ē��͂��ĉ�����:\n", sendAddress);
				scanf_s("%s", sendAddress, 1024);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̏Z��:%s\n", sendAddress);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "4") == 0)/*���˗���̎����̕ύX*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("�y���˗���̎������ē��́z\n���݂̓��͎���:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n", name);
				scanf_s("%s", name, 32);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̎���:%s\n", name);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "5") == 0)/*���˗���̗X�֔ԍ��̕ύX*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("�y���˗���̗X�֔ԍ����ē��́z\n���݂̓��͗X�֔ԍ�:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n(�n�C�t��������7�����̐����ōē��͂��ĉ�����)�F\n", PCord);
				scanf_s("%s", PCord, 32);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̎���:%s\n", PCord);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "6") == 0)/*���˗���̏Z���̕ύX*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("�y���˗���̏Z�����ē��́z\n���݂̓��͏Z��:�@%s\n�ύX��̏Z�����ē��͂��ĉ�����:\n", address);
				scanf_s("%s", address, 1024);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̏Z��:%s\n", address);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "7") == 0)/*�i�����̕ύX*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("�y�i�������ē��́z\n���݂̕i����:�@%s\n�ύX��̎������ē��͂��ĉ�����:\n", objectName);
				scanf_s("%s", objectName, 128);
				printf_s("===���͏��͂����Ă��܂����H");
				printf_s("\n�ύX��̎���:%s\n", objectName);
				while (1)
				{
					printf_s("===\n�͂���y,��������n�@����͂��ĉ������B\n����:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "���͂��Ԉ���Ă��܂��B";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("���͂��Ԉ���Ă��܂�\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "8") == 0)/*�I�v�V�����̕ύX*/
		{
			while (1)
			{
				printf_s("\n�@\n�y�I�v�V�����̍ē��́z\n");
				optionCount = 0;
				freezeFlag = 0;
				kakitomeFlag = 0;
				int i = 0;
				while (i < 9)
				{
					optionFlag[i] = 0;
					i++;
				}
				int loopFlag1 = 0;
				while (loopFlag1 < 9)
				{
					int i = loopFlag1;
					printf_s(" �@%s��%d�����\n", optionWord[i], i);
					loopFlag1++;
				}
				printf_s(" �������I���́u,�v�ŋ�؂��ē��͂��Ă�������\n�@�@���͗�:���B,�①,�{�l������(�e�W)���@1,3,8\n");
				printf_s("\n�I�v�V��������͂��ĉ������F");
				scanf_s("%s", option, 32);
				int flag11 = 0;
				tok = strtok_s(option, s2, &next_token1);
				while (tok != NULL)
				{
					char optintype[32];
					if (_ismbblead(tok[0]) == 0)
					{
						strcpy_s(optintype, tok);
					}
					else
					{
						char origin[32];
						char  converted[32];
						strcpy_s(origin, tok);
						LCMapString(LOCALE_SYSTEM_DEFAULT, LCMAP_HALFWIDTH, origin, 32, converted, 32);
						strcpy_s(optintype, converted);
					}
					if (strcmp(optintype, "1") == 0 && optionFlag[1] == 0)
					{
						optionFlag[1] = 1;
						optionCount++;
					}
					if (strcmp(optintype, "2") == 0 && optionFlag[2] == 0)
					{
						optionFlag[2] = 1;
						optionCount++;
					}
					if (strcmp(optintype, "3") == 0 && optionFlag[3] == 0)
					{
						optionFlag[3] = 1;
						optionCount++;
						freezeFlag++;
					}
					if (strcmp(optintype, "4") == 0 && optionFlag[4] == 0)
					{
						optionFlag[4] = 1;
						optionCount++;
						freezeFlag++;
					}
					if (strcmp(optintype, "5") == 0 && optionFlag[5] == 0)
					{
						optionFlag[5] = 1;
						optionCount++;
						kakitomeFlag++;
					}
					if (strcmp(optintype, "6") == 0 && optionFlag[6] == 0)
					{
						optionFlag[6] = 1;
						optionCount++;
						kakitomeFlag++;
					}
					if (strcmp(optintype, "7") == 0 && optionFlag[7] == 0)
					{
						optionFlag[7] = 1;
						optionCount++;
						kakitomeFlag++;
					}
					if (strcmp(optintype, "8") == 0 && optionFlag[8] == 0)
					{
						optionFlag[8] = 1;
						optionCount++;
					}
					if (strcmp(optintype, "0") == 0 && optionFlag[0] == 0)
					{
						optionFlag[0] = 1;
						optionCount = optionCount + 20;
					}
					tok = strtok_s(NULL, s2, &next_token1);
				}
				int  loopFlag2 = 0;
				if (optionCount > 20)
				{
					printf_s("�����I�v�V���������Ƒ��̃I�v�V������2�d�o�^����Ă��܂�����\n�ē��͂��肢���܂��B");
					Sleep(3000);
				}
				else if (freezeFlag > 1)
				{
					printf_s("�����Ⓚ�Ɨ①��2�d�o�^����Ă��܂�����\n�ē��͂��肢���܂��B");
					Sleep(3000);
				}
				else if (kakitomeFlag > 1)
				{
					printf_s("�����e�폑�������d�o�^����Ă��܂�����\n�ē��͂��肢���܂��B");
					Sleep(3000);
				}
				else if (optionCount == 0)
				{
					printf_s("�������������͂���܂��񁦁�\n�ē��͂��肢���܂��B");
					Sleep(3000);
				}
				else
				{
					printf_s(" \n�y�I�v�V�������m�F���Ă��������z\n=======================================================================\n");
					loopFlag2 = 0;
					while (loopFlag2 < 9)
					{
						int i = loopFlag2;
						if (optionFlag[i] == 1)
						{
							printf_s("%d:%s\n", i, optionWord[i]);
						}
						loopFlag2++;
					}
					printf_s("=======================================================================\n\n");
					while (1)
					{
						printf_s("�I�v�V�����ɊԈႢ�͂���܂��񂩁H\n�͂�(���ɐi��)��y, ������(�C������)��n�@����͂��ĉ������B\n����:");
						scanf_s("%s", flag2, 32);
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "��") == 0)
						{
							break;
						}
						else
						{
							talk_guide = "���͂��Ԉ���Ă��܂��B";
							talk_guide = SjistoUTF8(talk_guide);
							m_guidetext.data = talk_guide.c_str();
							//Beep(beepHz, beepTime);
							//Sleep(100);
							//Beep(beepHz, beepTime);
							printf_s("���͂��Ԉ���Ă��܂�\n");
							Sleep(2000);
						}
					}
					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "��") == 0)
					{
						exitFlag = 1;
					}
					else
					{
						exitFlag = 0;
					}
					if (exitFlag == 1)//�E�o����
					{
						break;
					}
				}
			}

		}
	}
	//std::cout << "	debug2 " << std::endl;
	//===============================================================================================================

	//=========(�f�[�^�����E���M����)================================================================================
	///char sendPCord[32];/*�����X�֔ԍ�*/
	//char sendAddress[1024];/*�����Z��*/
	//char PCord[32];/*�˗���X�֔ԍ�*/
	//char address[1024];/*�˗���Z��*/
	//char sendName[32];/*����掁��*/
	//char name[32];/*�˗��厁��*/
	//char objectName[128];/*�i����*/
	//char option[32];/*�I�v�V������*/

	//===============================================================================================================

	//printf_s("���肪�Ƃ��������܂��� \n");
	//Sleep(5 * 1000);
	std::string setSendPCode;
	std::string setSendAddress;
	std::string setPCode;
	std::string setAddress;
	//Del_data.sendPCode.~_CORBA_String_member();
	setSendPCode = sendPCord;
	Del_data.sendPCode = setSendPCode.c_str();
	//Del_data.sendPCode = sendPCord;
	//std::cout << "	debug3 " << std::endl;
	setSendAddress = sendAddress;
	Del_data.sendAddress = setSendAddress.c_str();
	//Del_data.sendAddress = sendAddress;
	//std::cout << "	debug4 " << std::endl;
	setPCode = PCord;
	Del_data.PCode = setPCode.c_str();
	//Del_data.PCode = PCord;// m_CurrentPCode.c_str();
	//std::cout << "	debug5 " << std::endl;
	//setAddress = m_CurrentAddress;//address;
	//Del_data.address = setAddress.c_str();
	//Del_data.address = address;
	//std::cout << "	debug6 " << std::endl;
	//int optionFlag[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };/*flag0:���B,flag1:�������,flag2:�①,flag3:�Ⓚ,flag4:��������,flag5:��ʏ���,flag6:�ȈՏ���,flag7:�{�l������,flag8:�I�v�V�������� */
	//std::cout << "	debug7 " << std::endl;
	for (int delop = 0; delop < 9; delop++)
	{
		Del_data.option[delop] = optionFlag[delop];
	}
	/*
	int option_Data = 0;
	if (optionFlag[0] == 1)
	{
		option_Data += 1;
	}
	if (optionFlag[1] == 1)
	{
		option_Data += 1;
	}
	if (optionFlag[2] == 1 || optionFlag[2] == 1)
	{
		option_Data += 1;
	}
	Del_data.option = option_Data;
	*/

	int notfind = 0;
	//std::cout << "	���[�v�O " << std::endl;
	while (!kbhit() || (getch() != ESC))
	{
		//std::cout << "���[�v��" << std::endl;
		if (m_ObjectPropertyIn.isNew())
		{
			m_ObjectPropertyIn.read();

			if (m_ObjectProperty.data[0] == -1)
			{
				if (notfind == 0||notfind == 2)
				{
					std::cout << "" << std::endl;
					std::cout << "�ו�������̈ʒu�ɒu���Ă�������" << std::endl;
					std::cout << "�L�����Z������ꍇ�@Esc�L�[ �������Ă�������" << std::endl;
					talk_guide = "�ו�������̈ʒu�ɒu���Ă��������B�L�����Z������ꍇ�@�G�X�P�[�v�L�[ �������Ă�������";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					m_guidetextOut.write();
					notfind = 1;
				}
			}
			else if (m_ObjectProperty.data[0] == -2)
			{
				if (notfind == 0||notfind == 1)
				{
					std::cout << "" << std::endl;
					std::cout << "�ו��������Ă��܂���B������ו���u���Ă�������" << std::endl;
					std::cout << "�L�����Z������ꍇ�@Esc�L�[ �������Ă�������" << std::endl;
					talk_guide = "�ו��������Ă��܂���B������ו���u���Ă��������B�L�����Z������ꍇ�@�G�X�P�[�v�L�[ �������Ă�������";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					m_guidetextOut.write();
					notfind = 2;
				}
			}
			else if (m_ObjectProperty.data[0] == 1)
			{
				std::cout << "�ו������o���܂���" << std::endl;
				Del_data.objectSize.length = m_ObjectProperty.data[1];
				Del_data.objectSize.width = m_ObjectProperty.data[2];
				Del_data.objectSize.high = m_ObjectProperty.data[3];
				Del_data.weight = m_ObjectProperty.data[4];

				std::cout << "�f�[�^�x�[�X�ɖ₢���킹�đ�z�����Ɨ������擾���܂��B" << std::endl << std::endl;
				m_DeliveryDatabaseInterface->getDeriveryDayAndFee(Del_data, FeeDayData);

				std::cout << "Database����擾���܂����B" << std::endl;
				std::cout << "����͂����� : " << FeeDayData.Day << "��" << std::endl;
				std::cout << "���� : " << FeeDayData.Fee << "�~" << std::endl << std::endl;

				std::cout << "��z�`�[��������܂�" << std::endl << std::endl;
				std::string setPrintSendPCode;
				std::string setPrintSendAddress;
				std::string setPrintPCode;
				std::string setPrintAddress;
				std::string setPrintSendName;
				std::string setPrintName;
				std::string setPrintObjectName;
				//std::cout << "	debug1 " << std::endl;
				setPrintSendPCode = Del_data.sendPCode;
				Pri_data.sendPCode = setPrintSendPCode.c_str();
				//std::cout << "	debug2 " << std::endl;
				setPrintSendAddress = Del_data.sendAddress;
				Pri_data.sendAddress = setPrintSendAddress.c_str();
				//std::cout << "	debug3 " << std::endl;
				setPrintPCode = Del_data.PCode;
				Pri_data.PCode = setPrintPCode.c_str();
				//std::cout << "	debug4 " << std::endl;
				setPrintAddress = address;
				Pri_data.address = setPrintAddress.c_str();
				//std::cout << "	debug5 " << std::endl;
				setPrintSendName = sendName;
				Pri_data.sendName = setPrintSendName.c_str();
				//std::cout << "	debug6 " << std::endl;
				setPrintName = name;
				Pri_data.Name = setPrintName.c_str();
				//std::cout << "	debug7 " << std::endl;
				setPrintObjectName = objectName;
				Pri_data.Name = setPrintObjectName.c_str();
				//std::cout << "	debug8 " << std::endl;
				//Pri_data.sendPCode = Del_data.sendPCode;
				//Pri_data.sendAddress = Del_data.sendAddress;
				//Pri_data.PCode = Del_data.PCode;
				//Pri_data.address = Del_data.address;
				//Pri_data.sendName = sendName;
				//Pri_data.Name = name;
				//Pri_data.objectName = objectName;
				//std::cout << "	debug9 " << std::endl;
				for (int pri = 0; pri < 9; pri++)
				{
					Pri_data.option[pri] = optionFlag[pri];
				}
				m_PrintDeliveryInterface->PrintDeliveryData(Pri_data);

				talk_FeeDataA = "������";
				talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
				talk_FeeDataB = double2string(FeeDayData.Fee);
				talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
				talk_FeeDataC = "�~�ł��B";
				talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
				talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
				m_guidetext.data = talk_FeeData.c_str();
				m_guidetextOut.write();
				Sleep(3000);
				talk_FeeDataA = "���͂����v������";
				talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
				talk_FeeDataB = double2string(FeeDayData.Day);
				talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
				talk_FeeDataC = "���ł��B";
				talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
				talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
				m_guidetext.data = talk_FeeData.c_str();
				m_guidetextOut.write();
				Sleep(5000);
				break;
			}
		}
	}

	std::cout << "�����p���肪�Ƃ��������܂���" << std::endl << std::endl;
	talk_thanks = "�����p���肪�Ƃ��������܂���";
	talk_thanks = SjistoUTF8(talk_thanks);
	m_guidetext.data = talk_thanks.c_str();
	m_guidetextOut.write();
	Sleep(5000);
	/*
	//����==========================�J�n=====================================================
	Del_data.objectSize.length = 123;
	Del_data.objectSize.width = 456;
	Del_data.objectSize.high = 789;
	Del_data.weight = 12345;
	Del_data.sendPCode = "4700204";
	Del_data.sendAddress = "���m���݂悵�s";
	Del_data.PCode = m_CurrentPCode.c_str();
	//Del_data.address = "�����s���É��s�V����";
	Del_data.option = 1;

	std::cout << "�ȉ��f�[�^�����͂���܂����B" << std::endl;
	std::cout << "length�F" << Del_data.objectSize.length << std::endl;
	std::cout << "width�F" << Del_data.objectSize.width << std::endl;
	std::cout << "high�F" << Del_data.objectSize.high << std::endl;
	std::cout << "���ʁF" << Del_data.weight << std::endl;
	std::cout << "����͂���X�֔ԍ��F" << Del_data.sendPCode << std::endl;
	std::cout << "����͂���Z���F" << Del_data.sendAddress << std::endl;
	std::cout << "����͂����X�֔ԍ��F" << Del_data.PCode << std::endl;
	std::cout << "����͂����Z���F" << Del_data.address << std::endl;
	std::cout << "�I�v�V�����F" << Del_data.option << std::endl << std::endl;
	std::cout << "�f�[�^�x�[�X�ɖ₢���킹�đ�z�����Ɨ������擾���܂��B" << std::endl << std::endl;
	m_DeliveryDatabaseInterface->getDeriveryDayAndFee(Del_data, FeeDayData);

	std::cout << "Database����擾���܂����B" << std::endl;
	std::cout << "����͂����� : " << FeeDayData.Day << "��" << std::endl;
	std::cout << "���� : " << FeeDayData.Fee << "�~" <<  std::endl;

	Pri_data.sendPCode = Del_data.sendPCode;
	Pri_data.sendAddress = Del_data.sendAddress;
	Pri_data.PCode = Del_data.PCode;
	Pri_data.address = Del_data.address;
	Pri_data.sendName = "�^�葏�m";
	Pri_data.Name = "�����w";
	Pri_data.objectName = "�e�X�g�A�C�e��";
	Pri_data.option = Del_data.option;
	std::cout << "��z�`�[���RTC�Ƀf�[�^�𑗂�܂��B" << std::endl;
	m_PrintDeliveryInterface->PrintDeliveryData(Pri_data);

	talk_FeeDataA = "������";
	talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
	talk_FeeDataB = double2string(FeeDayData.Fee);
	talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
	talk_FeeDataC = "�~�ł��B";
	talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
	talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
	m_guidetext.data = talk_FeeData.c_str();
	m_guidetextOut.write();
	Sleep(3000);
	talk_FeeDataA = "���͂����v������";
	talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
	talk_FeeDataB = double2string(FeeDayData.Day);
	talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
	talk_FeeDataC = "���ł��B";
	talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
	talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
	m_guidetext.data = talk_FeeData.c_str();
	m_guidetextOut.write();
	Sleep(5000);
	//����========================�I��=======================================================
	*/
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DeliveryManager::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryManager::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryManager::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryManager::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryManager::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

std::string DeliveryManager::UTF8toSjis(std::string srcUTF8)
{
	//Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

	//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//UTF8����Unicode�֕ϊ�
	MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

	//ShiftJIS�֕ϊ���̕����񒷂𓾂�
	int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

	//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
	char* bufShiftJis = new char[lengthSJis];

	//Unicode����ShiftJIS�֕ϊ�
	WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

	std::string strSJis(bufShiftJis);

	delete bufUnicode;
	delete bufShiftJis;

	return strSJis;
}
std::string DeliveryManager::SjistoUTF8(std::string srcSjis)
{
	//Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

	//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//ShiftJIS����Unicode�֕ϊ�
	MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


	//UTF8�֕ϊ���̕����񒷂𓾂�
	int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

	//�K�v�ȕ�����UTF8������̃o�b�t�@���m��
	char* bufUTF8 = new char[lengthUTF8];

	//Unicode����UTF8�֕ϊ�
	WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);

	std::string strUTF8(bufUTF8);

	delete bufUnicode;
	delete bufUTF8;

	return strUTF8;
}

std::string DeliveryManager::double2string(double d){
	std::string rt;
	std::stringstream ss;
	ss << d;
	ss >> rt;
	return rt;
}

extern "C"
{
 
  void DeliveryManagerInit(RTC::Manager* manager)
  {
    coil::Properties profile(deliverymanager_spec);
    manager->registerFactory(profile,
                             RTC::Create<DeliveryManager>,
                             RTC::Delete<DeliveryManager>);
  }
  
};



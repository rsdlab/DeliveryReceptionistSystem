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

// ESCのキーコード
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
	//47都道府県の宣言
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
		std::cout << "送り元：北海道" << std::endl;
		Del_data.address = "北海道";
	}
	else if (strstr(m_CurrentAddress.c_str(), Aomori.c_str()) != NULL)
	{
		std::cout << "送り元：青森県" << std::endl;
		Del_data.address = "青森県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Iwate.c_str()) != NULL)
	{
		std::cout << "送り元：岩手県" << std::endl;
		Del_data.address = "岩手県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Miyagi.c_str()) != NULL)
	{
		std::cout << "送り元：宮城県" << std::endl;
		Del_data.address = "宮城県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Akita.c_str()) != NULL)
	{
		std::cout << "送り元：秋田県" << std::endl;
		Del_data.address = "秋田県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Yamagata.c_str()) != NULL)
	{
		std::cout << "送り元：山形県" << std::endl;
		Del_data.address = "山形県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Fukushima.c_str()) != NULL)
	{
		std::cout << "送り元：福島県" << std::endl;
		Del_data.address = "福島県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Ibaraki.c_str()) != NULL)
	{
		std::cout << "送り元：茨城県" << std::endl;
		Del_data.address = "茨城県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tochigi.c_str()) != NULL)
	{
		std::cout << "送り元：栃木県" << std::endl;
		Del_data.address = "栃木県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Gumma.c_str()) != NULL)
	{
		std::cout << "送り元：群馬県" << std::endl;
		Del_data.address = "群馬県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Saitama.c_str()) != NULL)
	{
		std::cout << "送り元：埼玉県" << std::endl;
		Del_data.address = "埼玉県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Chiba.c_str()) != NULL)
	{
		std::cout << "送り元：千葉県" << std::endl;
		Del_data.address = "千葉県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tokyo.c_str()) != NULL)
	{
		std::cout << "送り元：東京都" << std::endl;
		Del_data.address = "東京都";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kanagawa.c_str()) != NULL)
	{
		std::cout << "送り元：神奈川県" << std::endl;
		Del_data.address = "神奈川県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Niigata.c_str()) != NULL)
	{
		std::cout << "送り元：新潟県" << std::endl;
		Del_data.address = "新潟県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Toyama.c_str()) != NULL)
	{
		std::cout << "送り元：富山県" << std::endl;
		Del_data.address = "富山県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Isikawa.c_str()) != NULL)
	{
		std::cout << "送り元：石川県" << std::endl;
		Del_data.address = "石川県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Fukui.c_str()) != NULL)
	{
		std::cout << "送り元：福井県" << std::endl;
		Del_data.address = "福井県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Yamanashi.c_str()) != NULL)
	{
		std::cout << "送り元：山梨県" << std::endl;
		Del_data.address = "山梨県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Nagano.c_str()) != NULL)
	{
		std::cout << "送り元：長野県" << std::endl;
		Del_data.address = "長野県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Gifu.c_str()) != NULL)
	{
		std::cout << "送り元：岐阜県" << std::endl;
		Del_data.address = "岐阜県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Shizuoka.c_str()) != NULL)
	{
		std::cout << "送り元：静岡県" << std::endl;
		Del_data.address = "静岡県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Aichi.c_str()) != NULL)
	{
		std::cout << "送り元：愛知県" << std::endl;
		Del_data.address = "愛知県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Mie.c_str()) != NULL)
	{
		std::cout << "送り元：三重県" << std::endl;
		Del_data.address = "三重県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Shiga.c_str()) != NULL)
	{
		std::cout << "送り元：滋賀県" << std::endl;
		Del_data.address = "滋賀県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kyoto.c_str()) != NULL)
	{
		std::cout << "送り元：京都府" << std::endl;
		Del_data.address = "京都府";
	}
	else if (strstr(m_CurrentAddress.c_str(), Osaka.c_str()) != NULL)
	{
		std::cout << "送り元：大阪府" << std::endl;
		Del_data.address = "大阪府";
	}
	else if (strstr(m_CurrentAddress.c_str(), Hyogo.c_str()) != NULL)
	{
		std::cout << "送り元：兵庫県" << std::endl;
		Del_data.address = "兵庫県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Nara.c_str()) != NULL)
	{
		std::cout << "送り元：奈良県" << std::endl;
		Del_data.address = "奈良県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Wakayama.c_str()) != NULL)
	{
		std::cout << "送り元：和歌山県" << std::endl;
		Del_data.address = "和歌山県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tottori.c_str()) != NULL)
	{
		std::cout << "送り元：鳥取県" << std::endl;
		Del_data.address = "鳥取県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Okayama.c_str()) != NULL)
	{
		std::cout << "送り元：岡山県" << std::endl;
		Del_data.address = "岡山県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Hiroshima.c_str()) != NULL)
	{
		std::cout << "送り元：広島県" << std::endl;
		Del_data.address = "広島県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Yamaguchi.c_str()) != NULL)
	{
		std::cout << "送り元：山口県" << std::endl;
		Del_data.address = "山口県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Tokushima.c_str()) != NULL)
	{
		std::cout << "送り元：徳島県" << std::endl;
		Del_data.address = "徳島県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kagawa.c_str()) != NULL)
	{
		std::cout << "送り元：香川県" << std::endl;
		Del_data.address = "香川県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Ehime.c_str()) != NULL)
	{
		std::cout << "送り元：愛媛県" << std::endl;
		Del_data.address = "愛媛県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kochi.c_str()) != NULL)
	{
		std::cout << "送り元：高知県" << std::endl;
		Del_data.address = "高知県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Fukuoka.c_str()) != NULL)
	{
		std::cout << "送り元：福岡県" << std::endl;
		Del_data.address = "福岡県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Saga.c_str()) != NULL)
	{
		std::cout << "送り元：佐賀県" << std::endl;
		Del_data.address = "佐賀県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Nagasaki.c_str()) != NULL)
	{
		std::cout << "送り元：長崎県" << std::endl;
		Del_data.address = "長崎県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kumamoto.c_str()) != NULL)
	{
		std::cout << "送り元：熊本県" << std::endl;
		Del_data.address = "熊本県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Oita.c_str()) != NULL)
	{
		std::cout << "送り元：大分県" << std::endl;
		Del_data.address = "大分県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Miyazaki.c_str()) != NULL)
	{
		std::cout << "送り元：宮崎県" << std::endl;
		Del_data.address = "宮崎県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Kagoshima.c_str()) != NULL)
	{
		std::cout << "送り元：鹿児島県" << std::endl;
		Del_data.address = "鹿児島県";
	}
	else if (strstr(m_CurrentAddress.c_str(), Okinawa.c_str()) != NULL)
	{
		std::cout << "送り元：沖縄県" << std::endl;
		Del_data.address = "沖縄県";
	}
	else
	{
		std::cout << "日本の都道府県以外が入力されました" << std::endl;
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

	char sendPCord[32];/*送り先郵便番号*/
	char sendAddress[1024];/*送り先住所*/
	char PCord[32];/*依頼主郵便番号*/
	char address[1024];/*依頼主住所*/
	char sendName[32];/*送り先氏名*/
	char name[32];/*依頼主氏名*/
	char objectName[128];/*品物名*/
	char option[32];/*オプション名*/
	//オプション部宣言
	char s2[] = ",，";  /* カンマのみ */
	char *tok;
	char *next_token1 = NULL;
	int optionFlag[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };/*flag0:速達,flag1:代金引換,flag2:冷蔵,flag3:冷凍,flag4:現金書留,flag5:一般書留,flag6:簡易書留,flag7:本人限定受取,flag8:オプション無し */
	int optionCount = 0;/*初期:0　オプション無しとほかのオプションの多重登録禁止の管理フラグ*/
	int freezeFlag = 0;/*冷蔵,冷凍の2重登録禁止の管理フラグ*/
	int kakitomeFlag = 0;/*各種書留の2重登録禁止の管理フラグ*/
	int exitFlag = 0;/*1のときループ脱出*/
	char optionWord[9][24] =
	{
		{ "オプション無し" }, { "速達" }, { "代金引換" }, { "冷蔵" }, { "冷凍" }, { "現金書留" }, { "一般書留" }, { "簡易書留" }, { "本人限定受け取り(親展)" }
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

	printf_s("いらっしゃいませ\n案内を開始するためにはEnterキーを押してください\n");
	talk_guide = "いらっしゃいませ、案内を開始するためにはエンターキーを押してください";
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
	//=============送り先情報入力========================================================================================================
	printf_s("【お届け先の氏名と住所の入力】\n");
	printf_s("お届け先の氏名を入力して下さい：");
	talk_guide = "お届け先の氏名を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", sendName, 32);

	printf_s("お届け先の郵便番号を入力して下さい\n(ハイフンを除く7文字の数字で入力して下さい)：\n");
	talk_guide = "お届け先の郵便番号を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", sendPCord, 32);

	printf_s("お届け先の住所を入力して下さい：\n");
	talk_guide = "お届け先の住所を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", sendAddress, 1024);

	while (1)
	{
		printf_s("\n【お届け先の情報を確認してください】\n=======================================================================\n");

		printf_s("お届け先氏名:　%s\nお届け先郵便番号:　%s\nお届け先住所:　%s\n", sendName, sendPCord, sendAddress);
		printf_s("=======================================================================\n\n　お届け先情報に間違いがなく次に進む→1を入力\n【入力情報の修正】※複数箇所の修正は１つずつ行ってください。\n　お届け先氏名の変更→2を入力\n　お届け先郵便番号の変更→3を入力\n　お届け先住所の変更→4を入力\n");
		talk_guide = "お届け先の情報を確認してください";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		while (1)
		{
			printf_s("\n(1, 2, 3, 4)から一つ入力して下さい。\n番号入力:　");
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
				talk_guide = "入力が間違っています。";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("入力が間違っています\n");
				Sleep(2);
			}

		}

		if (strcmp(flag1, "1") == 0)
		{
			while (1)
			{
				printf_s("===次に進んで大丈夫ですか？===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
				talk_guide = "次に進んで大丈夫ですか？ よろしければ y を、　修正する場合は n を押してください";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				scanf_s("%s", flag2, 32);
				if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
				{
					break;
				}
				else
				{
					talk_guide = "入力が間違っています。";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					m_guidetextOut.write();
					//Beep(beepHz, beepTime);
					//Sleep(100);
					//Beep(beepHz, beepTime);
					printf_s("入力が間違っています\n");
					Sleep(2000);
				}
			}
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
			{
				break;
			}

		}
		else if (strcmp(flag1, "2") == 0)
		{
			printf_s("【お届け先の氏名を再入力】\n現在の入力氏名:　%s\n変更後の氏名を再入力して下さい:\n", sendName);
			scanf_s("%s", sendName, 32);
		}
		else if (strcmp(flag1, "3") == 0)
		{
			printf_s("【お届け先の郵便番号を再入力】\n現在の入力郵便番号:　%s\n変更後の氏名を再入力して下さい:\n(ハイフンを除く7文字の数字で再入力して下さい)：\n", sendPCord);
			scanf_s("%s", sendPCord, 32);
		}
		else if (strcmp(flag1, "4") == 0)
		{
			printf_s("【お届け先の住所を再入力】\n現在の入力住所:　%s\n変更後の住所を再入力して下さい:\n", sendAddress);
			scanf_s("%s", sendAddress, 1024);
		}
	}
	//===================================================================================================================================


	//=============依頼者情報入力========================================================================================================
	printf_s("　\n【ご依頼主の氏名と住所の入力】\n");
	printf_s("ご依頼主の氏名を入力して下さい：\n");
	talk_guide = "ご依頼主の氏名を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", name, 32);

	printf_s("ご依頼主の郵便番号を入力して下さい\n(ハイフンを除く7文字の数字で入力して下さい)：\n");
	talk_guide = "ご依頼主の郵便番号を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", PCord, 32);

	printf_s("ご依頼主の住所を入力して下さい：\n");
	talk_guide = "ご依頼主の住所を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", address, 1024);

	while (1)
	{
		printf_s("　\n【ご依頼主様の情報を確認してください】\n=======================================================================\n");

		printf_s("ご依頼主の氏名:　%s\nご依頼主の郵便番号:　%s\nご依頼主の住所:　%s\n", name, PCord, address);
		printf_s("=======================================================================\n\n　ご依頼主の情報に間違いがなく次に進む→1を入力\n【入力情報の修正】※複数箇所の修正は１つずつ行ってください。\n　ご依頼主の氏名の変更→2を入力\n　ご依頼主の郵便番号の変更→3を入力\n　ご依頼主の住所の変更→4を入力\n");
		talk_guide = "ご依頼主様の情報を確認してください";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		while (1)
		{
			printf_s("\n(1, 2, 3, 4)から一つ入力して下さい。\n番号入力:　");
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
				talk_guide = "入力が間違っています。";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("入力が間違っています\n");
				Sleep(2000);
			}

		}

		if (strcmp(flag1, "1") == 0)
		{
			while (1)
			{
				printf_s("===次に進んで大丈夫ですか？===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
				talk_guide = "次に進んで大丈夫ですか？ よろしければ y を、　修正する場合は n を押してください";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				scanf_s("%s", flag2, 32);
				if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
				{
					break;
				}
				else
				{
					talk_guide = "入力が間違っています。";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					//Beep(beepHz, beepTime);
					//Sleep(100);
					//Beep(beepHz, beepTime);
					printf_s("入力が間違っています\n");
					Sleep(2000);
				}
			}
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
			{
				break;
			}

		}
		else if (strcmp(flag1, "2") == 0)
		{
			printf_s("【ご依頼主の氏名を再入力】\n現在の入力氏名:　%s\n変更後の氏名を再入力して下さい:\n", name);
			scanf_s("%s", name, 32);
		}
		else if (strcmp(flag1, "3") == 0)
		{
			printf_s("【ご依頼主の郵便番号を再入力】\n現在の入力郵便番号:　%s\n変更後の氏名を再入力して下さい:\n(ハイフンを除く7文字の数字で再入力して下さい)：\n", PCord);
			scanf_s("%s", PCord, 32);
		}
		else if (strcmp(flag1, "4") == 0)
		{
			printf_s("【ご依頼主の住所を再入力】\n現在の入力住所:　%s\n変更後の住所を再入力して下さい:\n", address);
			scanf_s("%s", address, 1024);
		}
	}
	//======================================================================================================================================

	//============品物情報入力========================================================================================================

	printf_s("　\n【品物名の入力】\n");
	printf_s("品物名を入力して下さい：\n");
	talk_guide = "品物名を入力して下さい";
	talk_guide = SjistoUTF8(talk_guide);
	m_guidetext.data = talk_guide.c_str();
	m_guidetextOut.write();
	scanf_s("%s", objectName, 128);
	while (1)
	{
		printf_s(" \n【品物名を確認してください】\n=======================================================================\n");

		printf_s("品物名:　%s\n", objectName);
		printf_s("=======================================================================\n\n");
		talk_guide = "品物名を確認してください";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		while (1){
			printf_s("品物名に間違いはありませんか？\nはい(次に進む)→y, いいえ(修正する)→n　を入力して下さい。\n入力:");
			scanf_s("%s", flag2, 32);
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
			{
				break;
			}
			else
			{
				talk_guide = "入力が間違っています。";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("入力が間違っています\n");
				Sleep(2000);
			}
		}
		if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
		{
			break;
		}
		else
		{
			printf_s("【品物名を再入力】\n現在の入力品物名:　%s\n変更後の品物名を再入力して下さい:\n", objectName);
			scanf_s("%s", objectName, 128);
		}

	}

	//======================================================================================================================================

	//============オプション入力========================================================================================================

	while (1)
	{
		if (optionCount == 0)
		{
			printf_s("【オプションの入力】\n");
		}
		else
		{
			printf_s("\n　\n【オプションの再入力】\n");
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
			printf_s(" 　%s→%dを入力\n", optionWord[i], i);
			loopFlag1++;
		}
		printf_s(" ※複数選択は「,」で区切って入力してください\n　　入力例:速達,冷蔵,本人限定受取(親展)→　1,3,8\n");
		printf_s("\nオプションを入力して下さい：");
		talk_guide = "宅配方法のオプションを入力して下さい";
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
			printf_s("※※オプション無しと他のオプションが2重登録されています※※\n再入力お願いします。");
			Sleep(3000);
		}
		else if (freezeFlag > 1)
		{
			printf_s("※※冷凍と冷蔵が2重登録されています※※\n再入力お願いします。");
			Sleep(3000);
		}
		else if (kakitomeFlag > 1)
		{
			printf_s("※※各種書留が多重登録されています※※\n再入力お願いします。");
			Sleep(3000);
		}
		else if (optionCount == 0)
		{
			printf_s("※※正しい入力ありません※※\n再入力お願いします。");
			Sleep(3000);
		}
		else
		{
			printf_s(" \n【オプションを確認してください】\n=======================================================================\n");
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
				printf_s("オプションに間違いはありませんか？\nはい(次に進む)→y, いいえ(修正する)→n　を入力して下さい。\n入力:");
				talk_guide = "オプションに間違いはありませんか？ よろしければ y を、　修正する場合は n を押してください";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				m_guidetextOut.write();
				scanf_s("%s", flag2, 32);
				if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
				{
					break;
				}
				else
				{
					talk_guide = "入力が間違っています。";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					//Beep(beepHz, beepTime);
					//Sleep(100);
					//Beep(beepHz, beepTime);
					printf_s("入力が間違っています\n");
					Sleep(2000);
				}
			}
			if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
			{
				exitFlag++;
			}
			else
			{
				exitFlag = 0;
			}
			if (exitFlag == 1)//脱出判定
			{
				break;
			}
		}
	}
	//=========================================================================================================

	//最終確認======================================================================================

	while (1)
	{

		printf_s("\n【入力情報の最終確認】\n================================================\n");
		printf_s("---------(お届け先の情報)---------------------------------------------\n");
		printf_s("　1:お届け先氏名:　%s\n", sendName);
		printf_s("　2:お届け先郵便番号:　%s\n　3:お届け先住所:　%s\n", sendPCord, sendAddress);
		printf_s("---------(ご依頼主様の情報)-------------------------------------------\n");
		printf_s("　4:ご依頼主の氏名:　%s\n　5:ご依頼主の郵便番号:　%s\n　6:ご依頼主の住所:　%s\n", name, PCord, address);
		printf_s("---------(品物名の情報)-----------------------------------------------\n");
		printf_s("　7:品物名:　%s\n", objectName);
		printf_s("---------(オプション情報)---------------------------------------------\n");
		printf_s("　8:\n");
		talk_guide = "入力情報の最終確認をします。間違いがあれば、対応したキーを押して修正してください。";
		talk_guide = SjistoUTF8(talk_guide);
		m_guidetext.data = talk_guide.c_str();
		m_guidetextOut.write();
		int loopFlag3 = 0;
		while (loopFlag3 < 9)
		{
			int i = loopFlag3;
			if (optionFlag[i] == 1)
			{
				printf_s("　　%s\n", optionWord[i]);
			}
			loopFlag3++;
		}
		printf_s("=======================================================================\n\n　 入力情報に間違いがなく次に進む→0を入力\n \n【入力情報の修正】※複数箇所の修正は１つずつ行ってください。\n");
		printf_s("　ご依頼主の氏名の変更→1を入力\n　ご依頼主の郵便番号の変更→2を入力\n　ご依頼主の住所の変更→3を入力\n");
		printf_s("ご依頼主の氏名の変更→4を入力\n　ご依頼主の郵便番号の変更→5を入力\n　ご依頼主の住所の変更→6を入力\n");
		printf_s("品物名の変更→7を入力\n");
		printf_s("オプションの変更→8を入力");

		while (1)
		{
			printf_s("\n(0, 1, 2, 3, 4, 5, 6, 7, 8)から一つ入力して下さい。\n番号入力:　");
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
				talk_guide = "入力が間違っています。";
				talk_guide = SjistoUTF8(talk_guide);
				m_guidetext.data = talk_guide.c_str();
				//Beep(beepHz, beepTime);
				//Sleep(100);
				//Beep(beepHz, beepTime);
				printf_s("入力が間違っています\n");
				Sleep(2000);
			}

		}
		// 以下を修正して直すflag分岐を記載で終了予定
		if (strcmp(finalCheckflag, "0") == 0)/*変更無しで終了*/
		{
			//std::cout << "	debug1 " << std::endl;
			break;
		}
		if (strcmp(finalCheckflag, "1") == 0)/*ご依頼主の氏名の変更*/
		{

			while (1)
			{
				int outFlag = 0;
				printf_s("【お届け先の氏名を再入力】\n現在の入力氏名:　%s\n変更後の氏名を再入力して下さい:\n", sendName);
				scanf_s("%s", sendName, 32);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の氏名:%s\n", sendName);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "2") == 0)/*ご依頼主の郵便番号の変更*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("【お届け先の郵便番号を再入力】\n現在の入力郵便番号:　%s\n変更後の氏名を再入力して下さい:\n(ハイフンを除く7文字の数字で再入力して下さい)：\n", sendPCord);
				scanf_s("%s", sendPCord, 32);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の郵便番号:%s\n", sendPCord);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "3") == 0)/*ご依頼主の住所の変更*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("【お届け先の住所を再入力】\n現在の入力住所:　%s\n変更後の住所を再入力して下さい:\n", sendAddress);
				scanf_s("%s", sendAddress, 1024);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の住所:%s\n", sendAddress);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "4") == 0)/*ご依頼主の氏名の変更*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("【ご依頼主の氏名を再入力】\n現在の入力氏名:　%s\n変更後の氏名を再入力して下さい:\n", name);
				scanf_s("%s", name, 32);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の氏名:%s\n", name);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "5") == 0)/*ご依頼主の郵便番号の変更*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("【ご依頼主の郵便番号を再入力】\n現在の入力郵便番号:　%s\n変更後の氏名を再入力して下さい:\n(ハイフンを除く7文字の数字で再入力して下さい)：\n", PCord);
				scanf_s("%s", PCord, 32);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の氏名:%s\n", PCord);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "6") == 0)/*ご依頼主の住所の変更*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("【ご依頼主の住所を再入力】\n現在の入力住所:　%s\n変更後の住所を再入力して下さい:\n", address);
				scanf_s("%s", address, 1024);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の住所:%s\n", address);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "7") == 0)/*品物名の変更*/
		{
			while (1)
			{
				int outFlag = 0;
				printf_s("【品物名を再入力】\n現在の品物名:　%s\n変更後の氏名を再入力して下さい:\n", objectName);
				scanf_s("%s", objectName, 128);
				printf_s("===入力情報はあっていますか？");
				printf_s("\n変更後の氏名:%s\n", objectName);
				while (1)
				{
					printf_s("===\nはい→y,いいえ→n　を入力して下さい。\n入力:");
					scanf_s("%s", flag2, 32);

					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
					{
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
						{
							outFlag = 1;
						}
						break;
					}
					else
					{
						talk_guide = "入力が間違っています。";
						talk_guide = SjistoUTF8(talk_guide);
						m_guidetext.data = talk_guide.c_str();
						//Beep(beepHz, beepTime);
						//Sleep(100);
						//Beep(beepHz, beepTime);
						printf_s("入力が間違っています\n");
						Sleep(2000);
					}
				}
				if (outFlag == 1)
				{
					break;
				}
			}
		}
		if (strcmp(finalCheckflag, "8") == 0)/*オプションの変更*/
		{
			while (1)
			{
				printf_s("\n　\n【オプションの再入力】\n");
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
					printf_s(" 　%s→%dを入力\n", optionWord[i], i);
					loopFlag1++;
				}
				printf_s(" ※複数選択は「,」で区切って入力してください\n　　入力例:速達,冷蔵,本人限定受取(親展)→　1,3,8\n");
				printf_s("\nオプションを入力して下さい：");
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
					printf_s("※※オプション無しと他のオプションが2重登録されています※※\n再入力お願いします。");
					Sleep(3000);
				}
				else if (freezeFlag > 1)
				{
					printf_s("※※冷凍と冷蔵が2重登録されています※※\n再入力お願いします。");
					Sleep(3000);
				}
				else if (kakitomeFlag > 1)
				{
					printf_s("※※各種書留が多重登録されています※※\n再入力お願いします。");
					Sleep(3000);
				}
				else if (optionCount == 0)
				{
					printf_s("※※正しい入力ありません※※\n再入力お願いします。");
					Sleep(3000);
				}
				else
				{
					printf_s(" \n【オプションを確認してください】\n=======================================================================\n");
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
						printf_s("オプションに間違いはありませんか？\nはい(次に進む)→y, いいえ(修正する)→n　を入力して下さい。\n入力:");
						scanf_s("%s", flag2, 32);
						if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0 || strcmp(flag2, "N") == 0 || strcmp(flag2, "n") == 0 || strcmp(flag2, "ｎ") == 0)
						{
							break;
						}
						else
						{
							talk_guide = "入力が間違っています。";
							talk_guide = SjistoUTF8(talk_guide);
							m_guidetext.data = talk_guide.c_str();
							//Beep(beepHz, beepTime);
							//Sleep(100);
							//Beep(beepHz, beepTime);
							printf_s("入力が間違っています\n");
							Sleep(2000);
						}
					}
					if (strcmp(flag2, "Y") == 0 || strcmp(flag2, "y") == 0 || strcmp(flag2, "ｙ") == 0)
					{
						exitFlag = 1;
					}
					else
					{
						exitFlag = 0;
					}
					if (exitFlag == 1)//脱出判定
					{
						break;
					}
				}
			}

		}
	}
	//std::cout << "	debug2 " << std::endl;
	//===============================================================================================================

	//=========(データ統括・送信処理)================================================================================
	///char sendPCord[32];/*送り先郵便番号*/
	//char sendAddress[1024];/*送り先住所*/
	//char PCord[32];/*依頼主郵便番号*/
	//char address[1024];/*依頼主住所*/
	//char sendName[32];/*送り先氏名*/
	//char name[32];/*依頼主氏名*/
	//char objectName[128];/*品物名*/
	//char option[32];/*オプション名*/

	//===============================================================================================================

	//printf_s("ありがとうございました \n");
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
	//int optionFlag[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };/*flag0:速達,flag1:代金引換,flag2:冷蔵,flag3:冷凍,flag4:現金書留,flag5:一般書留,flag6:簡易書留,flag7:本人限定受取,flag8:オプション無し */
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
	//std::cout << "	ループ前 " << std::endl;
	while (!kbhit() || (getch() != ESC))
	{
		//std::cout << "ループ中" << std::endl;
		if (m_ObjectPropertyIn.isNew())
		{
			m_ObjectPropertyIn.read();

			if (m_ObjectProperty.data[0] == -1)
			{
				if (notfind == 0||notfind == 2)
				{
					std::cout << "" << std::endl;
					std::cout << "荷物を所定の位置に置いてください" << std::endl;
					std::cout << "キャンセルする場合　Escキー を押してください" << std::endl;
					talk_guide = "荷物を所定の位置に置いてください。キャンセルする場合　エスケープキー を押してください";
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
					std::cout << "荷物が梱包されていません。梱包した荷物を置いてください" << std::endl;
					std::cout << "キャンセルする場合　Escキー を押してください" << std::endl;
					talk_guide = "荷物が梱包されていません。梱包した荷物を置いてください。キャンセルする場合　エスケープキー を押してください";
					talk_guide = SjistoUTF8(talk_guide);
					m_guidetext.data = talk_guide.c_str();
					m_guidetextOut.write();
					notfind = 2;
				}
			}
			else if (m_ObjectProperty.data[0] == 1)
			{
				std::cout << "荷物を検出しました" << std::endl;
				Del_data.objectSize.length = m_ObjectProperty.data[1];
				Del_data.objectSize.width = m_ObjectProperty.data[2];
				Del_data.objectSize.high = m_ObjectProperty.data[3];
				Del_data.weight = m_ObjectProperty.data[4];

				std::cout << "データベースに問い合わせて宅配日数と料金を取得します。" << std::endl << std::endl;
				m_DeliveryDatabaseInterface->getDeriveryDayAndFee(Del_data, FeeDayData);

				std::cout << "Databaseから取得しました。" << std::endl;
				std::cout << "送り届け日数 : " << FeeDayData.Day << "日" << std::endl;
				std::cout << "料金 : " << FeeDayData.Fee << "円" << std::endl << std::endl;

				std::cout << "宅配伝票を印刷します" << std::endl << std::endl;
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

				talk_FeeDataA = "料金は";
				talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
				talk_FeeDataB = double2string(FeeDayData.Fee);
				talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
				talk_FeeDataC = "円です。";
				talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
				talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
				m_guidetext.data = talk_FeeData.c_str();
				m_guidetextOut.write();
				Sleep(3000);
				talk_FeeDataA = "お届け所要日数は";
				talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
				talk_FeeDataB = double2string(FeeDayData.Day);
				talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
				talk_FeeDataC = "日です。";
				talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
				talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
				m_guidetext.data = talk_FeeData.c_str();
				m_guidetextOut.write();
				Sleep(5000);
				break;
			}
		}
	}

	std::cout << "ご利用ありがとうございました" << std::endl << std::endl;
	talk_thanks = "ご利用ありがとうございました";
	talk_thanks = SjistoUTF8(talk_thanks);
	m_guidetext.data = talk_thanks.c_str();
	m_guidetextOut.write();
	Sleep(5000);
	/*
	//検証==========================開始=====================================================
	Del_data.objectSize.length = 123;
	Del_data.objectSize.width = 456;
	Del_data.objectSize.high = 789;
	Del_data.weight = 12345;
	Del_data.sendPCode = "4700204";
	Del_data.sendAddress = "愛知県みよし市";
	Del_data.PCode = m_CurrentPCode.c_str();
	//Del_data.address = "東京都名古屋市天白区";
	Del_data.option = 1;

	std::cout << "以下データが入力されました。" << std::endl;
	std::cout << "length：" << Del_data.objectSize.length << std::endl;
	std::cout << "width：" << Del_data.objectSize.width << std::endl;
	std::cout << "high：" << Del_data.objectSize.high << std::endl;
	std::cout << "質量：" << Del_data.weight << std::endl;
	std::cout << "送り届け先郵便番号：" << Del_data.sendPCode << std::endl;
	std::cout << "送り届け先住所：" << Del_data.sendAddress << std::endl;
	std::cout << "送り届け元郵便番号：" << Del_data.PCode << std::endl;
	std::cout << "送り届け元住所：" << Del_data.address << std::endl;
	std::cout << "オプション：" << Del_data.option << std::endl << std::endl;
	std::cout << "データベースに問い合わせて宅配日数と料金を取得します。" << std::endl << std::endl;
	m_DeliveryDatabaseInterface->getDeriveryDayAndFee(Del_data, FeeDayData);

	std::cout << "Databaseから取得しました。" << std::endl;
	std::cout << "送り届け日数 : " << FeeDayData.Day << "日" << std::endl;
	std::cout << "料金 : " << FeeDayData.Fee << "円" <<  std::endl;

	Pri_data.sendPCode = Del_data.sendPCode;
	Pri_data.sendAddress = Del_data.sendAddress;
	Pri_data.PCode = Del_data.PCode;
	Pri_data.address = Del_data.address;
	Pri_data.sendName = "真崎聡士";
	Pri_data.Name = "名城大学";
	Pri_data.objectName = "テストアイテム";
	Pri_data.option = Del_data.option;
	std::cout << "宅配伝票印刷RTCにデータを送ります。" << std::endl;
	m_PrintDeliveryInterface->PrintDeliveryData(Pri_data);

	talk_FeeDataA = "料金は";
	talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
	talk_FeeDataB = double2string(FeeDayData.Fee);
	talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
	talk_FeeDataC = "円です。";
	talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
	talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
	m_guidetext.data = talk_FeeData.c_str();
	m_guidetextOut.write();
	Sleep(3000);
	talk_FeeDataA = "お届け所要日数は";
	talk_FeeDataA = SjistoUTF8(talk_FeeDataA);
	talk_FeeDataB = double2string(FeeDayData.Day);
	talk_FeeDataB = SjistoUTF8(talk_FeeDataB);
	talk_FeeDataC = "日です。";
	talk_FeeDataC = SjistoUTF8(talk_FeeDataC);
	talk_FeeData = talk_FeeDataA + talk_FeeDataB + talk_FeeDataC;
	m_guidetext.data = talk_FeeData.c_str();
	m_guidetextOut.write();
	Sleep(5000);
	//検証========================終了=======================================================
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
	//Unicodeへ変換後の文字列長を得る
	int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

	//必要な分だけUnicode文字列のバッファを確保
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//UTF8からUnicodeへ変換
	MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

	//ShiftJISへ変換後の文字列長を得る
	int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

	//必要な分だけShiftJIS文字列のバッファを確保
	char* bufShiftJis = new char[lengthSJis];

	//UnicodeからShiftJISへ変換
	WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

	std::string strSJis(bufShiftJis);

	delete bufUnicode;
	delete bufShiftJis;

	return strSJis;
}
std::string DeliveryManager::SjistoUTF8(std::string srcSjis)
{
	//Unicodeへ変換後の文字列長を得る
	int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);

	//必要な分だけUnicode文字列のバッファを確保
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//ShiftJISからUnicodeへ変換
	MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);


	//UTF8へ変換後の文字列長を得る
	int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

	//必要な分だけUTF8文字列のバッファを確保
	char* bufUTF8 = new char[lengthUTF8];

	//UnicodeからUTF8へ変換
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



// -*-C++-*-
/*!
 * @file  DeliveryDatabaseInterfaceSVC_impl.cpp
 * @brief Service implementation code of DeliveryDatabaseInterface.idl
 *
 */

#include "DeliveryDatabaseInterfaceSVC_impl.h"
#include "Database_ReturnID.h"
#include <stdio.h>
#include <iostream>
#include <string>

/*
 * Example implementational code for IDL interface DeriveryDatabase::DeriveryDatabaseInterface
 */
DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl::DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl()
{
  // Please add extra constructor code here.
}


DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl::~DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
DeriveryDatabase::RETURN_ID* DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl::getDeriveryDayAndFee(const DeriveryDatabase::DeliveryData& Alldata, DeriveryDatabase::FeeAndDay& FDdata)
{
	//47都道府県の宣言
	std::string Hokkaidou = "北海道";
	std::string Aomori = "青森";
	std::string Iwate = "岩手";
	std::string Akita = "秋田";
	std::string Miyagi = "宮城";
	std::string Yamagata = "山形";
	std::string Hukusima = "福島";
	std::string Niigata = "新潟";
	std::string Ibaragi = "茨木";
	std::string Tiba = "千葉";
	std::string Totigi = "栃木";
	std::string Gunma = "群馬";
	std::string Saitama = "埼玉";
	std::string Tokyo = "東京";
	std::string Kanagawa = "神奈川";
	std::string Sizuoka = "静岡";
	std::string Yamanasi = "山梨";
	std::string Nagano = "長野";
	std::string Toyama = "富山";
	std::string Isikawa = "石川";
	std::string Hukui = "福井";
	std::string Gihu = "岐阜";
	std::string Aichi = "愛知";
	std::string Mie = "三重";
	std::string Siga = "滋賀";
	std::string Kyoto = "京都";
	std::string Osaka = "大阪";
	std::string Nara = "奈良";
	std::string Wakayama = "和歌山";
	std::string Hyogo = "兵庫";
	std::string Tottori = "鳥取";
	std::string Okayama = "岡山";
	std::string Simane = "島根";
	std::string Hirosima = "広島";
	std::string Yamaguti = "山口";
	std::string Kagawa = "香川";
	std::string Tokusima = "徳島";
	std::string Ehime = "愛媛";
	std::string Kouti = "高知";
	std::string Hukuoka = "福岡";
	std::string Saga = "佐賀";
	std::string Nagasaki = "長崎";
	std::string Oita = "大分";
	std::string Kumamoto = "熊本";
	std::string Miyazaki = "宮崎";
	std::string Kagosima = "鹿児島";
	std::string Okinawa = "沖縄";
	//std::cout << "宣言" << std::endl;
	std::string sendAddress = Alldata.sendAddress;
	std::string address = Alldata.address;

	std::cout << "以下のデータを受け取りました" << std::endl;
	std::cout << "length：" << Alldata.objectSize.length*100 << "[cm]" << std::endl;
	std::cout << "width：" << Alldata.objectSize.width*100 << "[cm]" <<std::endl;
	std::cout << "high：" << Alldata.objectSize.high*100 << "[cm]" <<std::endl;
	std::cout << "質量：" << Alldata.weight << "[g]" << std::endl;
	std::cout << "送り届け先郵便番号：" << Alldata.sendPCode << std::endl;
	std::cout << "送り届け先住所：" << Alldata.sendAddress << std::endl;
	std::cout << "送り届け元郵便番号：" << Alldata.PCode << std::endl;
	std::cout << "送り届け元住所：" << Alldata.address << std::endl;
	//std::cout << "オプション：" << Alldata.option[0] << std::endl << std::endl;

	//===========================サイズの判定============================
	double threesize;
	double size;
	double sizePoint;
	threesize = Alldata.objectSize.length*1000 + Alldata.objectSize.width*1000 + Alldata.objectSize.high*1000;

	if (threesize <= 600 && Alldata.weight <= 2000)
	{
		std::cout << "60サイズ" << std::endl;
		size = 60;
		sizePoint = 1;
	}
	else if (threesize <= 800 && Alldata.weight <= 5000)
	{
		std::cout << "80サイズ" << std::endl;
		size = 80;
		sizePoint = 1.2;
	}
	else if (threesize <= 1000 && Alldata.weight <= 10000)
	{
		std::cout << "100サイズ" << std::endl;
		size = 100;
		sizePoint = 1.4;
	}
	else if (threesize <= 1200 && Alldata.weight <= 15000)
	{
		std::cout << "120サイズ" << std::endl;
		size = 120;
		sizePoint = 1.6;
	}
	else if (threesize <= 1400 && Alldata.weight <= 20000)
	{
		std::cout << "140サイズ" << std::endl;
		size = 140;
		sizePoint = 1.8;
	}
	else
	{
		std::cout << "160サイズ" << std::endl;
		size = 160;
		sizePoint = 2;
	}

	//=========================お届け先住所とお届け元住所の差=====================

	int sendAddressPoint;
	int addressPoint;
	//======================送り届け先判定================================
	if (strstr(sendAddress.c_str(), Hokkaidou.c_str()) != NULL)
	{
		std::cout << "送り先：北海道" << std::endl;
		sendAddressPoint = 0;
	}
	else if (strstr(sendAddress.c_str(), Aomori.c_str()) != NULL || strstr(sendAddress.c_str(), Akita.c_str()) != NULL || strstr(sendAddress.c_str(), Iwate.c_str()) != NULL)
	{
		std::cout << "送り先：北東北" << std::endl;
		sendAddressPoint = 1;
	}
	else if (strstr(sendAddress.c_str(), Miyagi.c_str()) != NULL || strstr(sendAddress.c_str(), Yamagata.c_str()) != NULL || strstr(sendAddress.c_str(), Hukusima.c_str()) != NULL)
	{
		std::cout << "送り先：南東北" << std::endl;
		sendAddressPoint = 2;
	}
	else if (strstr(sendAddress.c_str(), Ibaragi.c_str()) != NULL || strstr(sendAddress.c_str(), Totigi.c_str()) != NULL || strstr(sendAddress.c_str(), Gunma.c_str()) != NULL || strstr(sendAddress.c_str(), Saitama.c_str()) != NULL || strstr(sendAddress.c_str(), Saitama.c_str()) != NULL || strstr(sendAddress.c_str(), Tiba.c_str()) != NULL || strstr(sendAddress.c_str(), Kanagawa.c_str()) != NULL || strstr(sendAddress.c_str(), Tokyo.c_str()) != NULL || strstr(sendAddress.c_str(), Yamanasi.c_str()) != NULL)
	{
		std::cout << "送り先：関東" << std::endl;
		sendAddressPoint = 3;
	}
	else if (strstr(sendAddress.c_str(), Niigata.c_str()) != NULL || strstr(sendAddress.c_str(), Nagano.c_str()) != NULL)
	{
		std::cout << "送り先：信越" << std::endl;
		sendAddressPoint = 4;
	}
	else if (strstr(sendAddress.c_str(), Toyama.c_str()) != NULL || strstr(sendAddress.c_str(), Isikawa.c_str()) != NULL || strstr(sendAddress.c_str(), Hukui.c_str()) != NULL)
	{
		std::cout << "送り先：北陸" << std::endl;
		sendAddressPoint = 5;
	}
	else if (strstr(sendAddress.c_str(), Sizuoka.c_str()) != NULL || strstr(sendAddress.c_str(), Aichi.c_str()) != NULL || strstr(sendAddress.c_str(), Mie.c_str()) != NULL || strstr(sendAddress.c_str(), Gihu.c_str()) != NULL)
	{
		std::cout << "送り先：中部" << std::endl;
		sendAddressPoint = 6;
	}
	else if (strstr(sendAddress.c_str(), Osaka.c_str()) != NULL || strstr(sendAddress.c_str(), Kyoto.c_str()) != NULL || strstr(sendAddress.c_str(), Siga.c_str()) != NULL || strstr(sendAddress.c_str(), Nara.c_str()) != NULL || strstr(sendAddress.c_str(), Wakayama.c_str()) != NULL || strstr(sendAddress.c_str(), Hyogo.c_str()) != NULL)
	{
		std::cout << "送り先：関西" << std::endl;
		sendAddressPoint = 7;
	}
	else if (strstr(sendAddress.c_str(), Okayama.c_str()) != NULL || strstr(sendAddress.c_str(), Hirosima.c_str()) != NULL || strstr(sendAddress.c_str(), Yamaguti.c_str()) != NULL || strstr(sendAddress.c_str(), Tottori.c_str()) != NULL || strstr(sendAddress.c_str(), Simane.c_str()) != NULL)
	{
		std::cout << "送り先：中国" << std::endl;
		sendAddressPoint = 8;
	}
	else if (strstr(sendAddress.c_str(), Kagawa.c_str()) != NULL || strstr(sendAddress.c_str(), Tokusima.c_str()) != NULL || strstr(sendAddress.c_str(), Ehime.c_str()) != NULL || strstr(sendAddress.c_str(), Kouti.c_str()) != NULL)
	{
		std::cout << "送り先：四国" << std::endl;
		sendAddressPoint = 9;
	}
	else if (strstr(sendAddress.c_str(), Hukuoka.c_str()) != NULL || strstr(sendAddress.c_str(), Saga.c_str()) != NULL || strstr(sendAddress.c_str(), Nagasaki.c_str()) != NULL || strstr(sendAddress.c_str(), Kumamoto.c_str()) != NULL || strstr(sendAddress.c_str(), Oita.c_str()) != NULL || strstr(sendAddress.c_str(), Miyazaki.c_str()) != NULL || strstr(sendAddress.c_str(), Kagosima.c_str()) != NULL)
	{
		std::cout << "送り先：九州" << std::endl;
		sendAddressPoint = 9;
	}
	else if (strstr(sendAddress.c_str(), Okinawa.c_str()) != NULL)
	{
		std::cout << "送り先：沖縄" << std::endl;
		sendAddressPoint = 9;
	}
	else
	{
		std::cout << "エラー：送り届け先に日本の都道府県以外が入力されました" << std::endl;
		RETURNID_NG;
	}
	//======================送り届け先判定終了================================

	//======================送り届け元判定================================
	if (strstr(address.c_str(), Hokkaidou.c_str()) != NULL)
	{
		std::cout << "送り元：北海道" << std::endl;
		addressPoint = 0;
	}
	else if (strstr(address.c_str(), Aomori.c_str()) != NULL || strstr(address.c_str(), Akita.c_str()) != NULL || strstr(address.c_str(), Iwate.c_str()) != NULL)
	{
		std::cout << "送り元：北東北" << std::endl;
		addressPoint = 1;
	}
	else if (strstr(address.c_str(), Miyagi.c_str()) != NULL || strstr(address.c_str(), Yamagata.c_str()) != NULL || strstr(address.c_str(), Hukusima.c_str()) != NULL)
	{
		std::cout << "送り元：南東北" << std::endl;
		addressPoint = 2;
	}
	else if (strstr(address.c_str(), Ibaragi.c_str()) != NULL || strstr(address.c_str(), Totigi.c_str()) != NULL || strstr(address.c_str(), Gunma.c_str()) != NULL || strstr(address.c_str(), Saitama.c_str()) != NULL || strstr(address.c_str(), Saitama.c_str()) != NULL || strstr(address.c_str(), Tiba.c_str()) != NULL || strstr(address.c_str(), Kanagawa.c_str()) != NULL || strstr(address.c_str(), Tokyo.c_str()) != NULL || strstr(address.c_str(), Yamanasi.c_str()) != NULL)
	{
		std::cout << "送り元：関東" << std::endl;
		addressPoint = 3;
	}
	else if (strstr(address.c_str(), Niigata.c_str()) != NULL || strstr(address.c_str(), Nagano.c_str()) != NULL)
	{
		std::cout << "送り元：信越" << std::endl;
		addressPoint = 4;
	}
	else if (strstr(address.c_str(), Toyama.c_str()) != NULL || strstr(address.c_str(), Isikawa.c_str()) != NULL || strstr(address.c_str(), Hukui.c_str()) != NULL)
	{
		std::cout << "送り元：北陸" << std::endl;
		addressPoint = 5;
	}
	else if (strstr(address.c_str(), Sizuoka.c_str()) != NULL || strstr(address.c_str(), Aichi.c_str()) != NULL || strstr(address.c_str(), Mie.c_str()) != NULL || strstr(address.c_str(), Gihu.c_str()) != NULL)
	{
		std::cout << "送り元：中部" << std::endl;
		addressPoint = 6;
	}
	else if (strstr(address.c_str(), Osaka.c_str()) != NULL || strstr(address.c_str(), Kyoto.c_str()) != NULL || strstr(address.c_str(), Siga.c_str()) != NULL || strstr(address.c_str(), Nara.c_str()) != NULL || strstr(address.c_str(), Wakayama.c_str()) != NULL || strstr(address.c_str(), Hyogo.c_str()) != NULL)
	{
		std::cout << "送り元：関西" << std::endl;
		addressPoint = 7;
	}
	else if (strstr(address.c_str(), Okayama.c_str()) != NULL || strstr(address.c_str(), Hirosima.c_str()) != NULL || strstr(address.c_str(), Yamaguti.c_str()) != NULL || strstr(address.c_str(), Tottori.c_str()) != NULL || strstr(address.c_str(), Simane.c_str()) != NULL)
	{
		std::cout << "送り元：中国" << std::endl;
		addressPoint = 8;
	}
	else if (strstr(address.c_str(), Kagawa.c_str()) != NULL || strstr(address.c_str(), Tokusima.c_str()) != NULL || strstr(address.c_str(), Ehime.c_str()) != NULL || strstr(address.c_str(), Kouti.c_str()) != NULL)
	{
		std::cout << "送り元：四国" << std::endl;
		addressPoint = 9;
	}
	else if (strstr(address.c_str(), Hukuoka.c_str()) != NULL || strstr(address.c_str(), Saga.c_str()) != NULL || strstr(address.c_str(), Nagasaki.c_str()) != NULL || strstr(address.c_str(), Kumamoto.c_str()) != NULL || strstr(address.c_str(), Oita.c_str()) != NULL || strstr(address.c_str(), Miyazaki.c_str()) != NULL || strstr(address.c_str(), Kagosima.c_str()) != NULL)
	{
		std::cout << "送り元：九州" << std::endl;
		addressPoint = 10;
	}
	else if (strstr(address.c_str(), Okinawa.c_str()) != NULL)
	{
		std::cout << "送り元：沖縄" << std::endl;
		addressPoint = 11;
	}
	else
	{
		std::cout << "エラー：送り届け元に日本の都道府県以外が入力されました" << std::endl;
		RETURNID_NG;
	}
	//======================送り届け元判定終了================================


	//======================料金判定=========================================
	int DeliveryLengthPoint;
	DeliveryLengthPoint = abs(sendAddressPoint - addressPoint);
	//std::cout << "DeliveryLengthPoint = " << DeliveryLengthPoint << std::endl;
	int Feeint;
	//int Day;
	Feeint = (600 + 55 * DeliveryLengthPoint)*sizePoint;

	//======================オプションによるの追加料金==============================
	if (Alldata.option[1] != 0){
		std::cout << "速達料金 + 324円" << std::endl;
		Feeint = Feeint + 324;
	}
	if (Alldata.option[2] != 0){
		std::cout << "代金引換手数料 + 324円" << std::endl;
		Feeint = Feeint + 324;
	}
	if (Alldata.option[3] != 0){
		std::cout << "冷蔵料金 + 324円" << std::endl;
		Feeint = Feeint + 324;
	}
	if (Alldata.option[4] != 0){
		std::cout << "冷凍料金 + 324円" << std::endl;
		Feeint = Feeint + 324;
	}


	if (DeliveryLengthPoint <= 1)
	{
		FDdata.Day = 1;
	}
	else if (DeliveryLengthPoint <= 3)
	{
		FDdata.Day = 2;
	}
	else if (DeliveryLengthPoint <= 6)
	{
		FDdata.Day = 3;
	}
	else if (DeliveryLengthPoint <= 9)
	{
		FDdata.Day = 4;
	}
	else if (DeliveryLengthPoint <= 11)
	{
		FDdata.Day = 7;
	}
	else
	{
		std::cout << "お届け日数を計算できません" << std::endl;
		return 0;
	}

	FDdata.Fee = Feeint;

	std::cout << "以下のお届け日数と料金を返信します" << std::endl;
	std::cout << " Day : " << FDdata.Day << std::endl;
	std::cout << " Fee : " << FDdata.Fee << std::endl;

	std::cout << "Success" << std::endl << std::endl;

	RETURNID_OK;
}



// End of example implementational code




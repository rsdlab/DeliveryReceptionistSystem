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
	//47�s���{���̐錾
	std::string Hokkaidou = "�k�C��";
	std::string Aomori = "�X";
	std::string Iwate = "���";
	std::string Akita = "�H�c";
	std::string Miyagi = "�{��";
	std::string Yamagata = "�R�`";
	std::string Hukusima = "����";
	std::string Niigata = "�V��";
	std::string Ibaragi = "���";
	std::string Tiba = "��t";
	std::string Totigi = "�Ȗ�";
	std::string Gunma = "�Q�n";
	std::string Saitama = "���";
	std::string Tokyo = "����";
	std::string Kanagawa = "�_�ސ�";
	std::string Sizuoka = "�É�";
	std::string Yamanasi = "�R��";
	std::string Nagano = "����";
	std::string Toyama = "�x�R";
	std::string Isikawa = "�ΐ�";
	std::string Hukui = "����";
	std::string Gihu = "��";
	std::string Aichi = "���m";
	std::string Mie = "�O�d";
	std::string Siga = "����";
	std::string Kyoto = "���s";
	std::string Osaka = "���";
	std::string Nara = "�ޗ�";
	std::string Wakayama = "�a�̎R";
	std::string Hyogo = "����";
	std::string Tottori = "����";
	std::string Okayama = "���R";
	std::string Simane = "����";
	std::string Hirosima = "�L��";
	std::string Yamaguti = "�R��";
	std::string Kagawa = "����";
	std::string Tokusima = "����";
	std::string Ehime = "���Q";
	std::string Kouti = "���m";
	std::string Hukuoka = "����";
	std::string Saga = "����";
	std::string Nagasaki = "����";
	std::string Oita = "�啪";
	std::string Kumamoto = "�F�{";
	std::string Miyazaki = "�{��";
	std::string Kagosima = "������";
	std::string Okinawa = "����";
	//std::cout << "�錾" << std::endl;
	std::string sendAddress = Alldata.sendAddress;
	std::string address = Alldata.address;

	std::cout << "�ȉ��̃f�[�^���󂯎��܂���" << std::endl;
	std::cout << "length�F" << Alldata.objectSize.length*100 << "[cm]" << std::endl;
	std::cout << "width�F" << Alldata.objectSize.width*100 << "[cm]" <<std::endl;
	std::cout << "high�F" << Alldata.objectSize.high*100 << "[cm]" <<std::endl;
	std::cout << "���ʁF" << Alldata.weight << "[g]" << std::endl;
	std::cout << "����͂���X�֔ԍ��F" << Alldata.sendPCode << std::endl;
	std::cout << "����͂���Z���F" << Alldata.sendAddress << std::endl;
	std::cout << "����͂����X�֔ԍ��F" << Alldata.PCode << std::endl;
	std::cout << "����͂����Z���F" << Alldata.address << std::endl;
	//std::cout << "�I�v�V�����F" << Alldata.option[0] << std::endl << std::endl;

	//===========================�T�C�Y�̔���============================
	double threesize;
	double size;
	double sizePoint;
	threesize = Alldata.objectSize.length*1000 + Alldata.objectSize.width*1000 + Alldata.objectSize.high*1000;

	if (threesize <= 600 && Alldata.weight <= 2000)
	{
		std::cout << "60�T�C�Y" << std::endl;
		size = 60;
		sizePoint = 1;
	}
	else if (threesize <= 800 && Alldata.weight <= 5000)
	{
		std::cout << "80�T�C�Y" << std::endl;
		size = 80;
		sizePoint = 1.2;
	}
	else if (threesize <= 1000 && Alldata.weight <= 10000)
	{
		std::cout << "100�T�C�Y" << std::endl;
		size = 100;
		sizePoint = 1.4;
	}
	else if (threesize <= 1200 && Alldata.weight <= 15000)
	{
		std::cout << "120�T�C�Y" << std::endl;
		size = 120;
		sizePoint = 1.6;
	}
	else if (threesize <= 1400 && Alldata.weight <= 20000)
	{
		std::cout << "140�T�C�Y" << std::endl;
		size = 140;
		sizePoint = 1.8;
	}
	else
	{
		std::cout << "160�T�C�Y" << std::endl;
		size = 160;
		sizePoint = 2;
	}

	//=========================���͂���Z���Ƃ��͂����Z���̍�=====================

	int sendAddressPoint;
	int addressPoint;
	//======================����͂��攻��================================
	if (strstr(sendAddress.c_str(), Hokkaidou.c_str()) != NULL)
	{
		std::cout << "�����F�k�C��" << std::endl;
		sendAddressPoint = 0;
	}
	else if (strstr(sendAddress.c_str(), Aomori.c_str()) != NULL || strstr(sendAddress.c_str(), Akita.c_str()) != NULL || strstr(sendAddress.c_str(), Iwate.c_str()) != NULL)
	{
		std::cout << "�����F�k���k" << std::endl;
		sendAddressPoint = 1;
	}
	else if (strstr(sendAddress.c_str(), Miyagi.c_str()) != NULL || strstr(sendAddress.c_str(), Yamagata.c_str()) != NULL || strstr(sendAddress.c_str(), Hukusima.c_str()) != NULL)
	{
		std::cout << "�����F�쓌�k" << std::endl;
		sendAddressPoint = 2;
	}
	else if (strstr(sendAddress.c_str(), Ibaragi.c_str()) != NULL || strstr(sendAddress.c_str(), Totigi.c_str()) != NULL || strstr(sendAddress.c_str(), Gunma.c_str()) != NULL || strstr(sendAddress.c_str(), Saitama.c_str()) != NULL || strstr(sendAddress.c_str(), Saitama.c_str()) != NULL || strstr(sendAddress.c_str(), Tiba.c_str()) != NULL || strstr(sendAddress.c_str(), Kanagawa.c_str()) != NULL || strstr(sendAddress.c_str(), Tokyo.c_str()) != NULL || strstr(sendAddress.c_str(), Yamanasi.c_str()) != NULL)
	{
		std::cout << "�����F�֓�" << std::endl;
		sendAddressPoint = 3;
	}
	else if (strstr(sendAddress.c_str(), Niigata.c_str()) != NULL || strstr(sendAddress.c_str(), Nagano.c_str()) != NULL)
	{
		std::cout << "�����F�M�z" << std::endl;
		sendAddressPoint = 4;
	}
	else if (strstr(sendAddress.c_str(), Toyama.c_str()) != NULL || strstr(sendAddress.c_str(), Isikawa.c_str()) != NULL || strstr(sendAddress.c_str(), Hukui.c_str()) != NULL)
	{
		std::cout << "�����F�k��" << std::endl;
		sendAddressPoint = 5;
	}
	else if (strstr(sendAddress.c_str(), Sizuoka.c_str()) != NULL || strstr(sendAddress.c_str(), Aichi.c_str()) != NULL || strstr(sendAddress.c_str(), Mie.c_str()) != NULL || strstr(sendAddress.c_str(), Gihu.c_str()) != NULL)
	{
		std::cout << "�����F����" << std::endl;
		sendAddressPoint = 6;
	}
	else if (strstr(sendAddress.c_str(), Osaka.c_str()) != NULL || strstr(sendAddress.c_str(), Kyoto.c_str()) != NULL || strstr(sendAddress.c_str(), Siga.c_str()) != NULL || strstr(sendAddress.c_str(), Nara.c_str()) != NULL || strstr(sendAddress.c_str(), Wakayama.c_str()) != NULL || strstr(sendAddress.c_str(), Hyogo.c_str()) != NULL)
	{
		std::cout << "�����F�֐�" << std::endl;
		sendAddressPoint = 7;
	}
	else if (strstr(sendAddress.c_str(), Okayama.c_str()) != NULL || strstr(sendAddress.c_str(), Hirosima.c_str()) != NULL || strstr(sendAddress.c_str(), Yamaguti.c_str()) != NULL || strstr(sendAddress.c_str(), Tottori.c_str()) != NULL || strstr(sendAddress.c_str(), Simane.c_str()) != NULL)
	{
		std::cout << "�����F����" << std::endl;
		sendAddressPoint = 8;
	}
	else if (strstr(sendAddress.c_str(), Kagawa.c_str()) != NULL || strstr(sendAddress.c_str(), Tokusima.c_str()) != NULL || strstr(sendAddress.c_str(), Ehime.c_str()) != NULL || strstr(sendAddress.c_str(), Kouti.c_str()) != NULL)
	{
		std::cout << "�����F�l��" << std::endl;
		sendAddressPoint = 9;
	}
	else if (strstr(sendAddress.c_str(), Hukuoka.c_str()) != NULL || strstr(sendAddress.c_str(), Saga.c_str()) != NULL || strstr(sendAddress.c_str(), Nagasaki.c_str()) != NULL || strstr(sendAddress.c_str(), Kumamoto.c_str()) != NULL || strstr(sendAddress.c_str(), Oita.c_str()) != NULL || strstr(sendAddress.c_str(), Miyazaki.c_str()) != NULL || strstr(sendAddress.c_str(), Kagosima.c_str()) != NULL)
	{
		std::cout << "�����F��B" << std::endl;
		sendAddressPoint = 9;
	}
	else if (strstr(sendAddress.c_str(), Okinawa.c_str()) != NULL)
	{
		std::cout << "�����F����" << std::endl;
		sendAddressPoint = 9;
	}
	else
	{
		std::cout << "�G���[�F����͂���ɓ��{�̓s���{���ȊO�����͂���܂���" << std::endl;
		RETURNID_NG;
	}
	//======================����͂��攻��I��================================

	//======================����͂�������================================
	if (strstr(address.c_str(), Hokkaidou.c_str()) != NULL)
	{
		std::cout << "���茳�F�k�C��" << std::endl;
		addressPoint = 0;
	}
	else if (strstr(address.c_str(), Aomori.c_str()) != NULL || strstr(address.c_str(), Akita.c_str()) != NULL || strstr(address.c_str(), Iwate.c_str()) != NULL)
	{
		std::cout << "���茳�F�k���k" << std::endl;
		addressPoint = 1;
	}
	else if (strstr(address.c_str(), Miyagi.c_str()) != NULL || strstr(address.c_str(), Yamagata.c_str()) != NULL || strstr(address.c_str(), Hukusima.c_str()) != NULL)
	{
		std::cout << "���茳�F�쓌�k" << std::endl;
		addressPoint = 2;
	}
	else if (strstr(address.c_str(), Ibaragi.c_str()) != NULL || strstr(address.c_str(), Totigi.c_str()) != NULL || strstr(address.c_str(), Gunma.c_str()) != NULL || strstr(address.c_str(), Saitama.c_str()) != NULL || strstr(address.c_str(), Saitama.c_str()) != NULL || strstr(address.c_str(), Tiba.c_str()) != NULL || strstr(address.c_str(), Kanagawa.c_str()) != NULL || strstr(address.c_str(), Tokyo.c_str()) != NULL || strstr(address.c_str(), Yamanasi.c_str()) != NULL)
	{
		std::cout << "���茳�F�֓�" << std::endl;
		addressPoint = 3;
	}
	else if (strstr(address.c_str(), Niigata.c_str()) != NULL || strstr(address.c_str(), Nagano.c_str()) != NULL)
	{
		std::cout << "���茳�F�M�z" << std::endl;
		addressPoint = 4;
	}
	else if (strstr(address.c_str(), Toyama.c_str()) != NULL || strstr(address.c_str(), Isikawa.c_str()) != NULL || strstr(address.c_str(), Hukui.c_str()) != NULL)
	{
		std::cout << "���茳�F�k��" << std::endl;
		addressPoint = 5;
	}
	else if (strstr(address.c_str(), Sizuoka.c_str()) != NULL || strstr(address.c_str(), Aichi.c_str()) != NULL || strstr(address.c_str(), Mie.c_str()) != NULL || strstr(address.c_str(), Gihu.c_str()) != NULL)
	{
		std::cout << "���茳�F����" << std::endl;
		addressPoint = 6;
	}
	else if (strstr(address.c_str(), Osaka.c_str()) != NULL || strstr(address.c_str(), Kyoto.c_str()) != NULL || strstr(address.c_str(), Siga.c_str()) != NULL || strstr(address.c_str(), Nara.c_str()) != NULL || strstr(address.c_str(), Wakayama.c_str()) != NULL || strstr(address.c_str(), Hyogo.c_str()) != NULL)
	{
		std::cout << "���茳�F�֐�" << std::endl;
		addressPoint = 7;
	}
	else if (strstr(address.c_str(), Okayama.c_str()) != NULL || strstr(address.c_str(), Hirosima.c_str()) != NULL || strstr(address.c_str(), Yamaguti.c_str()) != NULL || strstr(address.c_str(), Tottori.c_str()) != NULL || strstr(address.c_str(), Simane.c_str()) != NULL)
	{
		std::cout << "���茳�F����" << std::endl;
		addressPoint = 8;
	}
	else if (strstr(address.c_str(), Kagawa.c_str()) != NULL || strstr(address.c_str(), Tokusima.c_str()) != NULL || strstr(address.c_str(), Ehime.c_str()) != NULL || strstr(address.c_str(), Kouti.c_str()) != NULL)
	{
		std::cout << "���茳�F�l��" << std::endl;
		addressPoint = 9;
	}
	else if (strstr(address.c_str(), Hukuoka.c_str()) != NULL || strstr(address.c_str(), Saga.c_str()) != NULL || strstr(address.c_str(), Nagasaki.c_str()) != NULL || strstr(address.c_str(), Kumamoto.c_str()) != NULL || strstr(address.c_str(), Oita.c_str()) != NULL || strstr(address.c_str(), Miyazaki.c_str()) != NULL || strstr(address.c_str(), Kagosima.c_str()) != NULL)
	{
		std::cout << "���茳�F��B" << std::endl;
		addressPoint = 10;
	}
	else if (strstr(address.c_str(), Okinawa.c_str()) != NULL)
	{
		std::cout << "���茳�F����" << std::endl;
		addressPoint = 11;
	}
	else
	{
		std::cout << "�G���[�F����͂����ɓ��{�̓s���{���ȊO�����͂���܂���" << std::endl;
		RETURNID_NG;
	}
	//======================����͂�������I��================================


	//======================��������=========================================
	int DeliveryLengthPoint;
	DeliveryLengthPoint = abs(sendAddressPoint - addressPoint);
	//std::cout << "DeliveryLengthPoint = " << DeliveryLengthPoint << std::endl;
	int Feeint;
	//int Day;
	Feeint = (600 + 55 * DeliveryLengthPoint)*sizePoint;

	//======================�I�v�V�����ɂ��̒ǉ�����==============================
	if (Alldata.option[1] != 0){
		std::cout << "���B���� + 324�~" << std::endl;
		Feeint = Feeint + 324;
	}
	if (Alldata.option[2] != 0){
		std::cout << "��������萔�� + 324�~" << std::endl;
		Feeint = Feeint + 324;
	}
	if (Alldata.option[3] != 0){
		std::cout << "�①���� + 324�~" << std::endl;
		Feeint = Feeint + 324;
	}
	if (Alldata.option[4] != 0){
		std::cout << "�Ⓚ���� + 324�~" << std::endl;
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
		std::cout << "���͂��������v�Z�ł��܂���" << std::endl;
		return 0;
	}

	FDdata.Fee = Feeint;

	std::cout << "�ȉ��̂��͂������Ɨ�����ԐM���܂�" << std::endl;
	std::cout << " Day : " << FDdata.Day << std::endl;
	std::cout << " Fee : " << FDdata.Fee << std::endl;

	std::cout << "Success" << std::endl << std::endl;

	RETURNID_OK;
}



// End of example implementational code




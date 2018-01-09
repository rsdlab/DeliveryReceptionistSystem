// -*-C++-*-
/*!
 * @file  PrintDelivaryInterfaceSVC_impl.cpp
 * @brief Service implementation code of PrintDelivaryInterface.idl
 *
 */

#include "PrintDelivaryInterfaceSVC_impl.h"
#include "Print_ReturnID.h"
#include <iostream>

/*
 * Example implementational code for IDL interface PrintDelivery::PrintDeriveryInterface
 */
PrintDelivery_PrintDeriveryInterfaceSVC_impl::PrintDelivery_PrintDeriveryInterfaceSVC_impl()
{
  // Please add extra constructor code here.
}


PrintDelivery_PrintDeriveryInterfaceSVC_impl::~PrintDelivery_PrintDeriveryInterfaceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
PrintDelivery::RETURN_ID* PrintDelivery_PrintDeriveryInterfaceSVC_impl::PrintDeliveryData(const PrintDelivery::PrintData& data)
{
	std::cout << "データを受け取りました。宅配伝票を印刷します。" << std::endl << std::endl;

	printf_s("\n【宅配伝票】\n================================================\n");
	printf_s("---------(お届け先の情報)---------------------------------------------\n");
	printf_s("　1:お届け先氏名:　%s\n", data.sendName);
	printf_s("　2:お届け先郵便番号:　%s\n　3:お届け先住所:　%s\n", data.sendPCode, data.sendAddress);
	printf_s("---------(ご依頼主様の情報)-------------------------------------------\n");
	printf_s("　4:ご依頼主の氏名:　%s\n　5:ご依頼主の郵便番号:　%s\n　6:ご依頼主の住所:　%s\n", data.Name, data.PCode, data.address);
	printf_s("---------(品物名の情報)-----------------------------------------------\n");
	printf_s("　7:品物名:　%s\n", data.objectName);
	printf_s("---------(オプション情報)---------------------------------------------\n");
	printf_s("　8:");


	//std::cout << "送り届け先郵便番号：" << data.sendPCode << std::endl;
	//std::cout << "送り届け先住所：" << data.sendAddress << std::endl;
	//std::cout << "送り届け先名前：" << data.sendName << std::endl;
	//std::cout << "送り届け元郵便番号：" << data.PCode << std::endl;
	//std::cout << "送り届け元住所：" << data.address << std::endl;
	//std::cout << "送り届け元名前：" << data.Name << std::endl;
	//std::cout << "商品名：" << data.objectName << std::endl;
	/*flag1:速達,flag2:代金引換,flag3:冷蔵,flag4:冷凍,flag5:現金書留,flag6:一般書留,flag7:簡易書留,flag8:本人限定受取,flag0:オプション無し */
	//std::cout << "オプション：";
	if (data.option[1] != 0){
		std::cout << "速達  ";
	}
	if (data.option[2] != 0){
		std::cout << "代金引換  ";
	}
	if (data.option[3] != 0){
		std::cout << "冷蔵  ";
	}
	if (data.option[4] != 0){
		std::cout << "冷凍  ";
	}
	if (data.option[5] != 0){
		std::cout << "現金書留  ";
	}
	if (data.option[6] != 0){
		std::cout << "一般書留  ";
	}
	if (data.option[7] != 0){
		std::cout << "簡易書留  ";
	}
	if (data.option[8] != 0){
		std::cout << "本人限定受取  ";
	}
	if (data.option[0] != 0){
		std::cout << "無し  ";
	}
	std::cout << "" << std::endl;


	std::cout << "Success" << std::endl << std::endl;
	RETURNID_OK;
}



// End of example implementational code




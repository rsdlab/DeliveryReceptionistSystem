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
	std::cout << "�f�[�^���󂯎��܂����B��z�`�[��������܂��B" << std::endl << std::endl;

	printf_s("\n�y��z�`�[�z\n================================================\n");
	printf_s("---------(���͂���̏��)---------------------------------------------\n");
	printf_s("�@1:���͂��掁��:�@%s\n", data.sendName);
	printf_s("�@2:���͂���X�֔ԍ�:�@%s\n�@3:���͂���Z��:�@%s\n", data.sendPCode, data.sendAddress);
	printf_s("---------(���˗���l�̏��)-------------------------------------------\n");
	printf_s("�@4:���˗���̎���:�@%s\n�@5:���˗���̗X�֔ԍ�:�@%s\n�@6:���˗���̏Z��:�@%s\n", data.Name, data.PCode, data.address);
	printf_s("---------(�i�����̏��)-----------------------------------------------\n");
	printf_s("�@7:�i����:�@%s\n", data.objectName);
	printf_s("---------(�I�v�V�������)---------------------------------------------\n");
	printf_s("�@8:");


	//std::cout << "����͂���X�֔ԍ��F" << data.sendPCode << std::endl;
	//std::cout << "����͂���Z���F" << data.sendAddress << std::endl;
	//std::cout << "����͂��於�O�F" << data.sendName << std::endl;
	//std::cout << "����͂����X�֔ԍ��F" << data.PCode << std::endl;
	//std::cout << "����͂����Z���F" << data.address << std::endl;
	//std::cout << "����͂������O�F" << data.Name << std::endl;
	//std::cout << "���i���F" << data.objectName << std::endl;
	/*flag1:���B,flag2:�������,flag3:�①,flag4:�Ⓚ,flag5:��������,flag6:��ʏ���,flag7:�ȈՏ���,flag8:�{�l������,flag0:�I�v�V�������� */
	//std::cout << "�I�v�V�����F";
	if (data.option[1] != 0){
		std::cout << "���B  ";
	}
	if (data.option[2] != 0){
		std::cout << "�������  ";
	}
	if (data.option[3] != 0){
		std::cout << "�①  ";
	}
	if (data.option[4] != 0){
		std::cout << "�Ⓚ  ";
	}
	if (data.option[5] != 0){
		std::cout << "��������  ";
	}
	if (data.option[6] != 0){
		std::cout << "��ʏ���  ";
	}
	if (data.option[7] != 0){
		std::cout << "�ȈՏ���  ";
	}
	if (data.option[8] != 0){
		std::cout << "�{�l������  ";
	}
	if (data.option[0] != 0){
		std::cout << "����  ";
	}
	std::cout << "" << std::endl;


	std::cout << "Success" << std::endl << std::endl;
	RETURNID_OK;
}



// End of example implementational code




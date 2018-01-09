//Print_ReturnID
#ifndef __Print_ReturnID_H__
#define __Print_ReturnID_H__

static PrintDelivery::RETURN_ID* RETURN_CODE(int id, const char *comment)
{
  PrintDelivery::RETURN_ID_var RETURNCODE = new PrintDelivery::RETURN_ID;
  RETURNCODE->id = id;
  RETURNCODE->comment = comment;
  return RETURNCODE._retn(); 
}

#define RETURNID(id,comment) { return RETURN_CODE(id,comment);}

#define RETURNID_OK RETURNID(PrintDelivery::OK,"�I�y���[�V�����𐳏�Ɏ󂯕t��.")
#define RETURNID_NG RETURNID(PrintDelivery::NG,"�I�y���[�V��������.")
#define RETURNID_STATUS_ERR RETURNID(PrintDelivery::STATUS_ERR,"�I�y���[�V�������󂯕t���\�ȏ�ԂłȂ�.")
#define RETURNID_VALUE_ERR RETURNID(PrintDelivery::VALUE_ERR,"�������s��.")
#define RETURNID_NOT_SV_ON_ERR RETURNID(PrintDelivery::NOT_SV_ON_ERR,"�S�Ă̎��̃T�[�{�������Ă��Ȃ�.")
#define RETURNID_FULL_MOTION_QUEUE_ERR RETURNID(PrintDelivery::FULL_MOTION_QUEUE_ERR,"�o�b�t�@����t.")
#define RETURNID_NOT_IMPLEMENTED RETURNID(PrintDelivery::NOT_IMPLEMENTED,"�������̃R�}���h.")

#endif//__Print_ReturnID_H__

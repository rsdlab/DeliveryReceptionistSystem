//Database_ReturnID
#ifndef __Database_ReturnID_H__
#define __Database_ReturnID_H__

static DeriveryDatabase::RETURN_ID* RETURN_CODE(int id, const char *comment)
{
  DeriveryDatabase::RETURN_ID_var RETURNCODE = new DeriveryDatabase::RETURN_ID;
  RETURNCODE->id = id;
  RETURNCODE->comment = comment;
  return RETURNCODE._retn(); 
}

#define RETURNID(id,comment) { return RETURN_CODE(id,comment);}

#define RETURNID_OK RETURNID(DeriveryDatabase::OK,"�I�y���[�V�����𐳏�Ɏ󂯕t��.")
#define RETURNID_NG RETURNID(DeriveryDatabase::NG,"�I�y���[�V��������.")
#define RETURNID_STATUS_ERR RETURNID(DeriveryDatabase::STATUS_ERR,"�I�y���[�V�������󂯕t���\�ȏ�ԂłȂ�.")
#define RETURNID_VALUE_ERR RETURNID(DeriveryDatabase::VALUE_ERR,"�������s��.")
#define RETURNID_NOT_SV_ON_ERR RETURNID(DeriveryDatabase::NOT_SV_ON_ERR,"�S�Ă̎��̃T�[�{�������Ă��Ȃ�.")
#define RETURNID_FULL_MOTION_QUEUE_ERR RETURNID(DeriveryDatabase::FULL_MOTION_QUEUE_ERR,"�o�b�t�@����t.")
#define RETURNID_NOT_IMPLEMENTED RETURNID(DeriveryDatabase::NOT_IMPLEMENTED,"�������̃R�}���h.")

#endif//__Database_ReturnID_H__

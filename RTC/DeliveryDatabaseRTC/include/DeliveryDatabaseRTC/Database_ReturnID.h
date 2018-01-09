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

#define RETURNID_OK RETURNID(DeriveryDatabase::OK,"オペレーションを正常に受け付け.")
#define RETURNID_NG RETURNID(DeriveryDatabase::NG,"オペレーション拒否.")
#define RETURNID_STATUS_ERR RETURNID(DeriveryDatabase::STATUS_ERR,"オペレーションを受け付け可能な状態でない.")
#define RETURNID_VALUE_ERR RETURNID(DeriveryDatabase::VALUE_ERR,"引数が不正.")
#define RETURNID_NOT_SV_ON_ERR RETURNID(DeriveryDatabase::NOT_SV_ON_ERR,"全ての軸のサーボが入っていない.")
#define RETURNID_FULL_MOTION_QUEUE_ERR RETURNID(DeriveryDatabase::FULL_MOTION_QUEUE_ERR,"バッファが一杯.")
#define RETURNID_NOT_IMPLEMENTED RETURNID(DeriveryDatabase::NOT_IMPLEMENTED,"未実装のコマンド.")

#endif//__Database_ReturnID_H__

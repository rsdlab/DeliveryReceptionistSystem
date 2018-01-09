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

#define RETURNID_OK RETURNID(PrintDelivery::OK,"オペレーションを正常に受け付け.")
#define RETURNID_NG RETURNID(PrintDelivery::NG,"オペレーション拒否.")
#define RETURNID_STATUS_ERR RETURNID(PrintDelivery::STATUS_ERR,"オペレーションを受け付け可能な状態でない.")
#define RETURNID_VALUE_ERR RETURNID(PrintDelivery::VALUE_ERR,"引数が不正.")
#define RETURNID_NOT_SV_ON_ERR RETURNID(PrintDelivery::NOT_SV_ON_ERR,"全ての軸のサーボが入っていない.")
#define RETURNID_FULL_MOTION_QUEUE_ERR RETURNID(PrintDelivery::FULL_MOTION_QUEUE_ERR,"バッファが一杯.")
#define RETURNID_NOT_IMPLEMENTED RETURNID(PrintDelivery::NOT_IMPLEMENTED,"未実装のコマンド.")

#endif//__Print_ReturnID_H__

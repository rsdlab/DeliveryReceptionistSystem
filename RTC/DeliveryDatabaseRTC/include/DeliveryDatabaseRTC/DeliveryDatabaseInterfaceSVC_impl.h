// -*-C++-*-
/*!
 * @file  DeliveryDatabaseInterfaceSVC_impl.h
 * @brief Service implementation header of DeliveryDatabaseInterface.idl
 *
 */

#include "BasicDataTypeSkel.h"

#include "DeliveryDatabaseInterfaceSkel.h"

#ifndef DELIVERYDATABASEINTERFACESVC_IMPL_H
#define DELIVERYDATABASEINTERFACESVC_IMPL_H
 
/*!
 * @class DeriveryDatabaseInterfaceSVC_impl
 * Example class implementing IDL interface DeriveryDatabase::DeriveryDatabaseInterface
 */
class DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl
 : public virtual POA_DeriveryDatabase::DeriveryDatabaseInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~DeriveryDatabaseInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
	 DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~DeriveryDatabase_DeriveryDatabaseInterfaceSVC_impl();

   // attributes and operations
   DeriveryDatabase::RETURN_ID* getDeriveryDayAndFee(const DeriveryDatabase::DeliveryData& Alldata, DeriveryDatabase::FeeAndDay& FDdata);

};



#endif // DELIVERYDATABASEINTERFACESVC_IMPL_H


